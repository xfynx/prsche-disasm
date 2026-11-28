# Run 893 - Render depthconv and codec closure

- `render_depthconv_codecs_893.{hpp,cpp}` recovers `?render_shape_convert_type_00534d40` (`857B`), `?render_texture_depth_convert_005350e0` (`608B`), `00571330` (`107B`), `005713a0` (`121B`), `00571470` (`19B`), BPE `00593640`/`00593790` (`439B`), Huffman `00593800` (`3,029B`), DXT1 `00594400`/`00594490` (`853B`), and RefPack `00594760`/`005948c0`/`005948f0`/`00594960` (`509B`) — 14 functions (`6,542B` total).
- Native differential verification (`local/experiments/v2-render-depthconv-codecs-893/012/receipt.json`): PASS under `/Od` and `/O2` (`9` cases/variant, `16/16` mutations killed).
- REA evidence (`local/experiments/v2-render-input-893-rea/001/receipt.json`, `validation.json`): PASS (`14` dossiers, `0` `repeated_equal`).
