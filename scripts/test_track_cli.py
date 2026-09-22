"""Test CLI and track loading functionality for 002-track-viewer."""
import subprocess
import tempfile
import unittest
from pathlib import Path

WORKSPACE = Path(__file__).resolve().parents[1]
candidates = [
    WORKSPACE / "local/builds/004-track-topology/windows/porsche-viewer.exe",
    WORKSPACE / "local/builds/004-track-topology/.cargo-target/release/porsche-viewer.exe",
    WORKSPACE / "local/builds/003-track-environment/windows/porsche-viewer.exe",
    WORKSPACE / "local/builds/003-track-environment/.cargo-target/release/porsche-viewer.exe",
    WORKSPACE / "local/builds/002-track-viewer/windows/porsche-viewer.exe",
    WORKSPACE / "local/builds/002-track-viewer/.cargo-target/release/porsche-viewer.exe",
]
EXE = next((p for p in candidates if p.exists()), candidates[0])
GAME_DIR = WORKSPACE / "local/game"


class TestTrackCli(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        if not EXE.exists():
            raise unittest.SkipTest(f"Binary not built: {EXE}")
        if not GAME_DIR.exists():
            raise unittest.SkipTest(f"Game directory not found: {GAME_DIR}")

    def test_inspect_skidpad(self):
        res = subprocess.run(
            [str(EXE), "inspect", "--game-dir", str(GAME_DIR), "--track", "skidpad"],
            capture_output=True,
            text=True,
        )
        self.assertEqual(res.returncode, 0, f"inspect skidpad failed: {res.stderr}")
        self.assertIn("6848 triangles", res.stdout)
        self.assertIn("98 textures", res.stdout)
        self.assertIn("107 materials", res.stdout)
        self.assertIn("Props: 70 articles, 11 instances", res.stdout)
        self.assertIn("Sky: loaded", res.stdout)

    def test_inspect_car_regression(self):
        res = subprocess.run(
            [str(EXE), "inspect", "--game-dir", str(GAME_DIR), "--car", "356a"],
            capture_output=True,
            text=True,
        )
        self.assertEqual(res.returncode, 0, f"inspect car 356a failed: {res.stderr}")
        self.assertIn("parts", res.stdout)

    def test_view_screenshot_headless(self):
        with tempfile.TemporaryDirectory() as tmpdir:
            out_png = Path(tmpdir) / "test_skidpad.png"
            res = subprocess.run(
                [
                    str(EXE),
                    "view",
                    "--game-dir",
                    str(GAME_DIR),
                    "--track",
                    "skidpad",
                    "--screenshot",
                    str(out_png),
                    "--pitch",
                    "0.5",
                    "--yaw",
                    "0.5",
                    "--width",
                    "320",
                    "--height",
                    "240",
                ],
                capture_output=True,
                text=True,
            )
            self.assertEqual(res.returncode, 0, f"screenshot failed: {res.stderr}")
            self.assertTrue(out_png.exists())
            self.assertGreater(out_png.stat().st_size, 1000)


if __name__ == "__main__":
    unittest.main()
