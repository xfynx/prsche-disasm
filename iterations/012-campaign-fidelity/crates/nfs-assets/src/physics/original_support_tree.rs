//! Type-1 support tree insertion/splitting from Porsche.exe, outside gameplay.
//! SHA256 ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39.
//! Insert 0x484ae0, split 0x483df0, predicate 0x484320, child 0x483bd0.
//! Win32 locks and allocator layout are platform infrastructure; Vec keeps
//! original record order. See Run 017 original instruction replay.

use super::original_spatial::{SpatialGrid, SpatialNode};
use super::original_support::{
    select_support_polygon, SupportLeafRecord, SupportPolygon, SupportVertices,
};
use super::original_support_bounds;
use nfs_formats::Result;

#[derive(Clone, Debug, PartialEq)]
pub struct SupportTreeNode {
    pub cell: SpatialNode,
    /// None mirrors a null vector pointer, distinct from an allocated empty vector.
    pub records: Option<Vec<usize>>,
}

#[derive(Clone, Debug, PartialEq)]
pub struct SupportTree {
    pub grid: SpatialGrid,
    pub nodes: Vec<SupportTreeNode>,
}

fn bounds(polygon: &SupportPolygon) -> ([f32; 3], [f32; 3]) {
    let points: &[[f32; 3]] = match &polygon.vertices {
        SupportVertices::Triangle(points) => points,
        SupportVertices::Quad(points) => points,
    };
    original_support_bounds::bounds(points, [0.0; 3], [0.0; 3])
}

impl SupportTree {
    pub fn new(grid: SpatialGrid, root: u32) -> Self {
        assert!(
            root >> 28 <= 12,
            "root beyond original split stopping level"
        );
        Self {
            grid,
            nodes: vec![SupportTreeNode {
                cell: SpatialNode {
                    packed: root,
                    children: [None; 4],
                    records_present: false,
                },
                records: None,
            }],
        }
    }

    /// Original scene setup at 0x487876: half extent 8192, depth 15, root zero.
    pub fn original_scene() -> Self {
        Self::new(SpatialGrid::new(8192.0, 15), 0)
    }

    /// Type-1 polygons with finite geometry only. Invalid caller references
    /// or unsupported float inputs are rejected before mutating the tree.
    pub fn insert(&mut self, polygons: &[SupportPolygon], index: usize) -> Result<()> {
        let polygon = polygons
            .get(index)
            .ok_or("support polygon index outside arena")?;
        let points: &[[f32; 3]] = match &polygon.vertices {
            SupportVertices::Triangle(points) => points,
            SupportVertices::Quad(points) => points,
        };
        if points.iter().flatten().any(|v| !v.is_finite())
            || polygon.center.iter().any(|v| !v.is_finite())
        {
            return Err("nonfinite support geometry outside proven tree contract".into());
        }
        self.insert_at(0, polygons, index);
        Ok(())
    }

    /// Original scene → cached node → leaf records → selected type-1 polygon.
    /// Returns (polygon index, updated cached node). Polygons must be the same
    /// immutable arena used for insertion; game-unit conversion is not inferred.
    pub fn query(
        &self,
        polygons: &[SupportPolygon],
        point: [f32; 3],
        cached: Option<usize>,
    ) -> Result<(Option<usize>, usize)> {
        if point.iter().any(|value| !value.is_finite()) {
            return Err("nonfinite support query outside proven tree contract".into());
        }
        let retained = if let Some(cached) = cached {
            let node = self
                .nodes
                .get(cached)
                .ok_or("cached support node outside arena")?;
            node.cell.records_present && self.grid.contains(node.cell.packed, point)
        } else {
            false
        };
        let node = if retained {
            cached.unwrap()
        } else {
            self.grid.query_nodes(|i| &self.nodes[i].cell, point)
        };
        let Some(indices) = &self.nodes[node].records else {
            return Ok((None, node));
        };
        let records = indices
            .iter()
            .map(|index| {
                polygons
                    .get(*index)
                    .map(|polygon| SupportLeafRecord {
                        record_type: 1,
                        polygon,
                    })
                    .ok_or_else(|| "tree polygon reference outside arena".to_string())
            })
            .collect::<Result<Vec<_>>>()?;
        Ok((
            select_support_polygon(&records, point).map(|record| indices[record]),
            node,
        ))
    }

    fn extent(&self, packed: u32) -> (f32, f32, f32) {
        let width = self.grid.widths[(packed >> 28) as usize];
        let x = ((packed & 0x3fff) as f64 * width as f64 - self.grid.half_extent as f64) as f32;
        let z =
            (((packed >> 14) & 0x3fff) as f64 * width as f64 - self.grid.half_extent as f64) as f32;
        (x, z, width)
    }

    /// 0x484320: inclusive center, then half-open AABB min / inclusive max.
    fn accepts_node(&self, node: usize, polygon: &SupportPolygon) -> bool {
        let points: &[[f32; 3]] = match &polygon.vertices {
            SupportVertices::Triangle(points) => points,
            SupportVertices::Quad(points) => points,
        };
        original_support_bounds::node_overlap(
            self.nodes[node].cell.packed,
            &self.grid.widths,
            self.grid.half_extent,
            points,
        )
    }

    /// Child filter in 0x484ae0 / 0x483df0 is inclusive at upper bounds.
    /// Allocation precedes the child's own 0x484320 check: an empty child
    /// can therefore remain allocated and must not be pruned from the arena.
    fn accepts_child(&self, node: usize, slot: usize, polygon: &SupportPolygon) -> bool {
        let (x, z, width) = self.extent(self.nodes[node].cell.packed);
        let half = (width as f64 * 0.5) as f32;
        let mid_x = (x as f64 + half as f64) as f32;
        let mid_z = (z as f64 + half as f64) as f32;
        let right = slot == 1 || slot == 3;
        let positive_z = slot == 0 || slot == 1;
        let lower_x = if right { mid_x } else { x } as f64;
        let lower_z = if positive_z { mid_z } else { z } as f64;
        let upper_x = if right {
            mid_x as f64 + half as f64
        } else {
            mid_x as f64
        };
        let upper_z = if positive_z {
            mid_z as f64 + half as f64
        } else if slot == 2 {
            z as f64 + half as f64
        } else {
            mid_z as f64
        };
        let [cx, _, cz] = polygon.center.map(f64::from);
        if lower_x <= cx && cx <= upper_x && lower_z <= cz && cz <= upper_z {
            return true;
        }
        let (lo, hi) = bounds(polygon);
        lo[0] as f64 <= upper_x
            && lo[2] as f64 <= upper_z
            && hi[0] as f64 >= lower_x
            && hi[2] as f64 >= lower_z
    }

    fn child(&mut self, node: usize, slot: usize) -> usize {
        if let Some(child) = self.nodes[node].cell.children[slot] {
            return child;
        }
        let child = self.nodes.len();
        self.nodes.push(SupportTreeNode {
            cell: SpatialNode::child(self.nodes[node].cell.packed, slot as u32),
            records: None,
        });
        self.nodes[node].cell.children[slot] = Some(child);
        child
    }

    fn distribute(&mut self, node: usize, polygons: &[SupportPolygon], index: usize) {
        // Source calls children in this order, not pointer-slot order.
        for slot in [2, 0, 1, 3] {
            if self.accepts_child(node, slot, &polygons[index]) {
                let child = self.child(node, slot);
                self.insert_at(child, polygons, index);
            }
        }
    }

    fn insert_at(&mut self, node: usize, polygons: &[SupportPolygon], index: usize) {
        if !self.accepts_node(node, &polygons[index]) {
            return;
        }
        if self.nodes[node].cell.children.iter().any(Option::is_some) {
            self.distribute(node, polygons, index);
            return;
        }
        let records = self.nodes[node]
            .records
            .get_or_insert_with(|| Vec::with_capacity(50));
        records.push(index);
        let split = records.len() > 48 && self.nodes[node].cell.packed >> 28 != 12;
        self.nodes[node].cell.records_present = true;
        if split {
            // Parent vector stays live during original redistribution, and
            // is released only after all records have been processed in order.
            let records = self.nodes[node].records.as_ref().unwrap().clone();
            for record in records {
                self.distribute(node, polygons, record);
            }
            self.nodes[node].records = None;
            self.nodes[node].cell.records_present = false;
        }
    }
}
