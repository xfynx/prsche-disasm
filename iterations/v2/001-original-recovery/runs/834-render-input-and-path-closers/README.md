# Run834: Render missing-setup abort, input bounds, and invalid module path closers

Recovers `render_missing_setup_00467535` (`00467535..0046754d` 25B cold block + `.data` literals `005cf78c` 38B and `005cf7b4` 7B), `input_negative_index_00532e10` and `input_unmapped_index_00532e10` (`00532e10` out-of-range slot guards), and `resource_invalid_module_path_0059d650` (`0059d687` no-backslash jump-through boundary; 0 new unresolved symbols).
Native comparison `local/experiments/v2-render-input-path-834/005/receipt.json` PASS (`4` cases / `4` events per `/Od` and `/O2`, `6/6` mutations killed).
REA `local/experiments/v2-render-input-path-834-rea/001/receipt.json` + `validation.json` PASS (`3` dossiers, `0` repeated equal).
