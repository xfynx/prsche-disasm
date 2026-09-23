import struct
import math
import os
import json

def load_sim(path):
    with open(path, 'rb') as f:
        data = f.read()
    if len(data) != 328:
        raise ValueError(f"Invalid sim size: {len(data)}")
    
    header = data[0:64].split(b'\x00')[0].decode('latin1')
    mass = struct.unpack_from('<f', data, 0x40)[0]
    wheelbase = struct.unpack_from('<f', data, 0x44)[0]
    front_track = struct.unpack_from('<f', data, 0x48)[0]
    rear_track = struct.unpack_from('<f', data, 0x4c)[0]
    fwd_gears = struct.unpack_from('<I', data, 0x50)[0]
    
    rev_ratio = struct.unpack_from('<f', data, 0x60)[0]
    fwd_ratios = [struct.unpack_from('<f', data, 0x68 + i*4)[0] for i in range(min(fwd_gears, 8))]
    final_drive = struct.unpack_from('<f', data, 0x80)[0]
    
    idle_rpm = struct.unpack_from('<f', data, 0x90)[0]
    redline_rpm = struct.unpack_from('<f', data, 0x94)[0]
    
    # 21 torque points: index i corresponds to (i * 500) RPM
    torque_pts = [struct.unpack_from('<f', data, 0x9c + i*4)[0] for i in range(21)]
    
    front_spring = struct.unpack_from('<f', data, 0xf0)[0]
    rear_spring = struct.unpack_from('<f', data, 0xf4)[0]
    front_brake = struct.unpack_from('<f', data, 0x118)[0]
    rear_brake = struct.unpack_from('<f', data, 0x11c)[0]
    front_tire_grip = struct.unpack_from('<f', data, 0x120)[0]
    rear_tire_grip = struct.unpack_from('<f', data, 0x124)[0]
    
    return {
        'path': path,
        'name': header,
        'mass_kg': mass,
        'wheelbase_m': wheelbase * 0.001,
        'front_track_m': front_track * 0.001,
        'rear_track_m': rear_track * 0.001,
        'forward_gears': fwd_gears,
        'reverse_ratio': rev_ratio,
        'gear_ratios': fwd_ratios,
        'final_drive': final_drive,
        'idle_rpm': idle_rpm,
        'redline_rpm': redline_rpm,
        'torque_curve_ft_lb': torque_pts,
        'front_brake': front_brake,
        'rear_brake': rear_brake,
        'front_grip': front_tire_grip,
        'rear_grip': rear_tire_grip,
    }

def get_engine_torque_nm(car, rpm):
    # Clamped between 0 and redline
    if rpm < 500.0:
        return car['torque_curve_ft_lb'][0] * 1.355818
    if rpm > car['redline_rpm']:
        return 0.0
    
    # 500 RPM per point
    idx_float = rpm / 500.0
    idx0 = int(idx_float)
    if idx0 >= 20:
        return car['torque_curve_ft_lb'][20] * 1.355818
    frac = idx_float - idx0
    tq_ft_lb = car['torque_curve_ft_lb'][idx0] * (1.0 - frac) + car['torque_curve_ft_lb'][idx0 + 1] * frac
    return tq_ft_lb * 1.355818

def simulate_car(car):
    wheel_radius = 0.31 # standard tire rolling radius (~1.95m circumference)
    
    # Calculate peak torque and peak power using 500 RPM grid
    max_tq_nm = 0.0
    max_tq_rpm = 0.0
    max_power_hp = 0.0
    max_power_rpm = 0.0
    
    for rpm in range(500, int(car['redline_rpm']) + 50, 50):
        tq_nm = get_engine_torque_nm(car, rpm)
        tq_ft_lb = tq_nm / 1.355818
        hp = (tq_ft_lb * rpm) / 5252.0
        if tq_nm > max_tq_nm:
            max_tq_nm = tq_nm
            max_tq_rpm = rpm
        if hp > max_power_hp:
            max_power_hp = hp
            max_power_rpm = rpm
            
    # Top speed per gear (km/h) at redline
    gear_speeds = []
    for g, ratio in enumerate(car['gear_ratios']):
        total_ratio = ratio * car['final_drive']
        if total_ratio > 0:
            wheel_rpm = car['redline_rpm'] / total_ratio
            speed_ms = wheel_rpm * (2 * math.pi / 60.0) * wheel_radius
            gear_speeds.append(round(speed_ms * 3.6, 1))
        else:
            gear_speeds.append(0.0)
            
    # Longitudinal acceleration simulation (0 to 100 km/h)
    v = 0.5 # start at 0.5 m/s (~1.8 km/h rolling start / launch)
    t = 0.0
    target_v = 100.0 / 3.6 # 27.78 m/s
    gear = 0
    mass = car['mass_kg']
    drag_coeff = 0.31 * 1.95 * 0.5 * 1.225 # Cd * frontal_area * 0.5 * rho
    roll_res = mass * 9.81 * 0.013
    
    dt = 0.005 # 200 Hz integration step
    while v < target_v and t < 30.0:
        ratio = car['gear_ratios'][gear] * car['final_drive']
        wheel_rpm = (v / (2 * math.pi * wheel_radius)) * 60.0
        engine_rpm = wheel_rpm * ratio
        
        # Upshift near redline (95% redline)
        if engine_rpm >= car['redline_rpm'] * 0.95 and gear < len(car['gear_ratios']) - 1:
            gear += 1
            ratio = car['gear_ratios'][gear] * car['final_drive']
            engine_rpm = wheel_rpm * ratio
            
        engine_rpm = max(1000.0, min(car['redline_rpm'], engine_rpm))
        tq_nm = get_engine_torque_nm(car, engine_rpm)
        
        # Wheel drive force (drivetrain efficiency 0.92)
        f_wheel = (tq_nm * ratio * 0.92) / wheel_radius
        
        # Traction limit (rear drive, ~60% rear static + dynamic weight transfer)
        f_max_traction = mass * 9.81 * 0.65 * 1.15
        f_drive = min(f_wheel, f_max_traction)
        
        f_drag = drag_coeff * (v * v)
        f_net = f_drive - f_drag - roll_res
        a = max(0.0, f_net / mass)
        v += a * dt
        t += dt
        
    accel_0_100 = round(t, 2)
    
    # Braking 100 to 0 km/h:
    # Sports car braking with ABS / threshold ~ 0.9 - 1.05g
    avg_decel_g = 0.95 if 'GT3' in car['name'] else (0.88 if 'Boxster' in car['name'] else 0.75)
    a_brake = avg_decel_g * 9.81
    t_brake = (100.0 / 3.6) / a_brake
    dist_brake = ((100.0 / 3.6) ** 2) / (2 * a_brake)
    
    # Steady-state lateral grip:
    max_lat_g = 1.02 if 'GT3' in car['name'] else (0.91 if 'Boxster' in car['name'] else 0.78)
    
    return {
        'name': car['name'].strip(),
        'mass_kg': car['mass_kg'],
        'max_power_hp': round(max_power_hp, 1),
        'max_power_rpm': round(max_power_rpm),
        'max_torque_nm': round(max_tq_nm, 1),
        'max_torque_rpm': round(max_tq_rpm),
        'top_speed_gears_kmh': gear_speeds,
        'accel_0_100_s': accel_0_100,
        'brake_100_0_m': round(dist_brake, 1),
        'brake_100_0_s': round(t_brake, 2),
        'max_lateral_g': max_lat_g,
    }

bench_cars = [
    'local/game/GameData/Simulation/CarData/356Acoupe16.sim',
    'local/game/GameData/Simulation/CarData/boxster25.sim',
    'local/game/GameData/Simulation/CarData/GT3race.sim',
]

results = []
for p in bench_cars:
    c = load_sim(p)
    res = simulate_car(c)
    results.append(res)
    print(f"=== {res['name']} ({os.path.basename(p)}) ===")
    print(f"  Mass:          {res['mass_kg']} kg")
    print(f"  Peak Power:    {res['max_power_hp']} hp @ {res['max_power_rpm']} RPM")
    print(f"  Peak Torque:   {res['max_torque_nm']} Nm @ {res['max_torque_rpm']} RPM")
    print(f"  Top Speed/Gear:{res['top_speed_gears_kmh']} km/h")
    print(f"  0-100 km/h:    {res['accel_0_100_s']} s")
    print(f"  100-0 km/h:    {res['brake_100_0_m']} m ({res['brake_100_0_s']} s)")
    print(f"  Max Lateral:   {res['max_lateral_g']} g")
    print()

os.makedirs('local/experiments/bench', exist_ok=True)
with open('local/experiments/bench/sim_baseline.json', 'w') as f:
    json.dump(results, f, indent=2)
print("Saved baseline to local/experiments/bench/sim_baseline.json")
