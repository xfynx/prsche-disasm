"""Test snapshot isolation and overwrite protection using synthetic content."""
import importlib.util
import tempfile
import unittest
from pathlib import Path

spec = importlib.util.spec_from_file_location('iteration', Path(__file__).with_name('new-iteration.py'))
iteration = importlib.util.module_from_spec(spec)
spec.loader.exec_module(iteration)


class SnapshotTests(unittest.TestCase):
    def test_copy_is_independent_and_excludes_build_products(self):
        with tempfile.TemporaryDirectory() as tmp:
            root = Path(tmp)
            source = root/'iterations/000-bootstrap'
            (source/'src').mkdir(parents=True)
            (source/'src/main.rs').write_text('original', encoding='utf-8')
            (source/'target').mkdir()
            (source/'target/build').write_text('cache', encoding='utf-8')
            (source/'runs/001-old').mkdir(parents=True)
            (source/'runs/001-old/snap.png').write_bytes(b'png')
            target = iteration.create_iteration(root, source.name, '001-viewer')
            self.assertFalse((target/'target').exists())
            self.assertFalse((target/'runs/001-old').exists())
            self.assertTrue((target/'runs/README.md').exists())
            (target/'src/main.rs').write_text('changed', encoding='utf-8')
            self.assertEqual((source/'src/main.rs').read_text(), 'original')
            with self.assertRaises(FileExistsError):
                iteration.create_iteration(root, source.name, '001-viewer')
            with self.assertRaises(ValueError):
                iteration.create_iteration(root, source.name, '../escape')
            with self.assertRaises(ValueError):
                iteration.create_iteration(root, source.name, '000-other')


if __name__ == '__main__':
    unittest.main()
