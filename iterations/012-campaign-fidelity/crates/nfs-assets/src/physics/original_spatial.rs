//! Bounded original support-tree lookup for supplied, valid node arenas.
//!
//! `Porsche.exe` SHA256
//! `ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`.
//! Sources: `research/original-collision/spatial-source.jsonl`, grid width
//! initializer `0x48384a..0x483881`, bounds `0x484450`, traversal `0x484500`,
//! cache resolution `0x473240`; replayed in `runs/014-original-spatial-query`.
//! Resource loading, insertion, and live road-surface binding remain open.

#[derive(Clone, Debug, PartialEq)]
pub struct SpatialNode {
    /// Level in bits 28..31, X in bits 0..13, Z in bits 14..27.
    pub packed: u32,
    /// Original pointer slots +4, +8, +0xc, +0x10: (-X,+Z), (+X,+Z),
    /// (-X,-Z), (+X,-Z).
    pub children: [Option<usize>; 4],
    /// Whether the pointer at +0x14 is non-null, including an empty vector.
    pub records_present: bool,
}

impl SpatialNode {
    /// Child constructor 0x483bd0, independently replayed in Run 016.
    /// The original's selectors other than 0, 1, and 3 take the same branch
    /// as 2. Each packed coordinate wraps within its own fourteen bits.
    pub fn child(parent: u32, selector: u32) -> Self {
        let x = ((parent & 0x3fff) * 2 + u32::from(selector == 1 || selector == 3)) & 0x3fff;
        let z =
            (((parent >> 14) & 0x3fff) * 2 + u32::from(selector == 0 || selector == 1)) & 0x3fff;
        Self {
            packed: (parent & 0xf0000000).wrapping_add(0x10000000) | (z << 14) | x,
            children: [None; 4],
            records_present: false,
        }
    }
}

#[derive(Clone, Debug, PartialEq)]
pub struct SpatialGrid {
    pub half_extent: f32,
    pub widths: [f32; 16],
}

impl SpatialGrid {
    /// Fresh initialization with zeroed unused widths, as in the replay's
    /// fresh PE image. The original in-place global initializer only writes
    /// `depth` entries; repeated initialization is outside this constructor.
    /// `depth` is an infrastructure bound for the 16-entry width table.
    pub fn new(half_extent: f32, depth: usize) -> Self {
        assert!((1..=16).contains(&depth), "grid depth must be 1..=16");
        let mut widths = [0.0; 16];
        widths[0] = (half_extent as f64 * 2.0) as f32;
        for level in 1..depth {
            widths[level] = (widths[level - 1] as f64 * 0.5) as f32;
        }
        Self {
            half_extent,
            widths,
        }
    }

    /// Original inclusive X/Z bounds test. The point's Y is ignored.
    pub fn contains(&self, packed: u32, point: [f32; 3]) -> bool {
        let width = self.widths[(packed >> 28) as usize] as f64;
        let x = (packed & 0x3fff) as f64;
        let z = ((packed >> 14) & 0x3fff) as f64;
        let lower_x = x * width - self.half_extent as f64;
        let lower_z = (z * width - self.half_extent as f64) as f32 as f64;
        let px = point[0] as f64;
        let pz = point[2] as f64;
        lower_x <= px && px <= lower_x + width && lower_z <= pz && pz <= lower_z + width
    }

    /// Traverse an already supplied acyclic arena whose root is index zero.
    /// A missing selected child returns the original root.
    pub fn query(&self, nodes: &[SpatialNode], point: [f32; 3]) -> usize {
        let root = &nodes[0];
        if root.children.iter().all(Option::is_none) {
            return 0;
        }
        let width = self.widths[(root.packed >> 28) as usize] as f64;
        let mut width = width;
        let x = (root.packed & 0x3fff) as f64;
        let z = ((root.packed >> 14) & 0x3fff) as f64;
        let mut center_x = (x + 0.5) * width - self.half_extent as f64;
        let mut center_z = (z + 0.5) * width - self.half_extent as f64;
        let mut node_index = 0;
        loop {
            let node = &nodes[node_index];
            if node.records_present {
                return node_index;
            }
            let negative_x = (point[0] as f64) < center_x;
            let negative_z = (point[2] as f64) < center_z;
            let slot = match (negative_x, negative_z) {
                (true, false) => 0,
                (false, false) => 1,
                (true, true) => 2,
                (false, true) => 3,
            };
            center_x += if negative_x {
                -width * 0.25
            } else {
                width * 0.25
            };
            center_z += if negative_z {
                -width * 0.25
            } else {
                width * 0.25
            };
            width *= 0.5;
            match node.children[slot] {
                Some(child) => node_index = child,
                None => return 0,
            }
        }
    }

    /// Resolve the cached leaf before querying the supplied arena. A cached
    /// node may win on an inclusive shared boundary where fresh traversal
    /// would choose its neighbor.
    pub fn resolve_cached(
        &self,
        nodes: &[SpatialNode],
        point: [f32; 3],
        cached: Option<usize>,
    ) -> (usize, bool) {
        if let Some(index) = cached {
            let node = &nodes[index];
            if node.records_present && self.contains(node.packed, point) {
                return (index, true);
            }
        }
        (self.query(nodes, point), false)
    }
}
