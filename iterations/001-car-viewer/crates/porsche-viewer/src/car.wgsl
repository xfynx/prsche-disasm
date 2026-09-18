struct Camera { view_projection: mat4x4<f32>, eye: vec4<f32> };
struct Material { color: vec4<f32>, params: vec4<f32> };
@group(0) @binding(0) var<uniform> camera: Camera;
@group(1) @binding(0) var color_texture: texture_2d<f32>;
@group(1) @binding(1) var color_sampler: sampler;
@group(1) @binding(2) var<uniform> material: Material;
struct Output {
    @builtin(position) clip: vec4<f32>,
    @location(0) position: vec3<f32>,
    @location(1) normal: vec3<f32>,
    @location(2) uv: vec2<f32>,
};
@vertex fn vs_main(@location(0) position: vec3<f32>, @location(1) normal: vec3<f32>, @location(2) uv: vec2<f32>) -> Output {
    var out: Output;
    out.clip = camera.view_projection * vec4<f32>(position, 1.0);
    out.position = position;
    out.normal = normal;
    out.uv = uv;
    return out;
}
@fragment fn fs_main(in: Output, @builtin(front_facing) front: bool) -> @location(0) vec4<f32> {
    let texel = textureSample(color_texture, color_sampler, in.uv);
    // Exterior alpha encodes paint regions, not opacity. Alpha 255 is fixed
    // artwork (lamps/chrome), 0 is unpainted background; intermediate values
    // select paint regions. Full CLR palette decoding is separate work.
    let painted = material.params.z > 0.5 && texel.a > 0.5 / 255.0 && texel.a < 254.5 / 255.0;
    let tint = select(vec3<f32>(1.0), material.color.rgb, material.params.z < 0.5 || painted);
    let base = vec4<f32>(texel.rgb * tint, texel.a * material.color.a);
    let alpha_mode = material.params.x;
    let alpha_cutoff = material.params.y;
    if alpha_mode > 0.5 && alpha_mode < 1.5 && base.a <= alpha_cutoff { discard; }
    let normal = normalize(select(-in.normal, in.normal, front));
    let key = normalize(vec3<f32>(-0.4, 0.8, 0.6));
    let fill = normalize(vec3<f32>(0.8, 0.3, -0.6));
    let lighting = 0.38 + 0.50 * max(dot(normal, key), 0.0) + 0.20 * max(dot(normal, fill), 0.0);
    let eye = normalize(camera.eye.xyz - in.position);
    let specular = pow(max(dot(normal, normalize(key + eye)), 0.0), 48.0) * 0.12;
    let out_alpha = select(1.0, base.a, alpha_mode > 1.5);
    return vec4<f32>(base.rgb * lighting + vec3<f32>(specular), out_alpha);
}
