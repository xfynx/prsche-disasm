"""Mapping must not silently read another PE section or virtual-only bytes."""
import unittest

from audit_topology_evidence import raw_offset


class MappingTests(unittest.TestCase):
    def setUp(self):
        self.sections = [dict(rva=0x1000, raw_offset=0x400, raw_size=0x200),
                         dict(rva=0x3000, raw_offset=0x800, raw_size=0x100)]

    def test_relocated_raw_sections(self):
        self.assertEqual(raw_offset(self.sections, 0x1080, 16), 0x480)
        self.assertEqual(raw_offset(self.sections, 0x3004, 4), 0x804)

    def test_virtual_gap_and_cross_boundary_rejected(self):
        for rva, size in [(0x1200, 1), (0x11f8, 16), (0x2fff, 2), (0x3100, 1)]:
            with self.subTest(rva=rva), self.assertRaises(ValueError):
                raw_offset(self.sections, rva, size)


if __name__ == '__main__':
    unittest.main()
