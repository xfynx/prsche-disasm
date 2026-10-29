# PR #26 integration review

Reviewed author head: `5ad7ab9c746abcafa5be0eae3939269c84c32a29`,
[PR #26](https://github.com/xfynx/prsche-disasm/pull/26), by
[paceholder](https://github.com/paceholder), against maintainer baseline `9061cf6`.
This intake concerns the experimental Rust iteration 012 and research recorders.
It does not accept new C++ game bodies or close startup, gameplay or visual fidelity.
Contributor scope is recorded in [LICENSING.md](../../LICENSING.md).

## Provenance and evidence boundaries

The local physics review verified the indexed binary identities: `nfs5.exe`
(2,002,989 bytes), SHA256
`c318af393d4c2b7071a820ca3d69e956bbd94769b6e5c2e3e49f498ecbc94906`,
and `Porsche.exe` (2,129,965 bytes), SHA256
`ddd748fdbe6d2030e31f9257a4e01852749460b6b58560a6b4a8559d3799ff39`.
The relevant indexed function ranges were compared between the two modules,
including input `00412e70`, object response `00498280/00498aa0/00498690`,
body contact `00496610`, seed `004a4780`, damage helper `004938a0`, body setup
`0049abc0`, start placement `0049b090`, object pass `00498de0`, impact `00494500`
and barrier pass `00495020`. Raw spans additionally cover `004a1030`, `00487290`
and `00411c20`. These bytes agree; the whole `.text` images differ at six bytes
starting `0055609e`. Whole-module equivalence is not claimed.

- **Recorded:** keyboard chain from raw key bytes through polling, input queue,
  input reading and planar stepping; source domain is 9 runs, 679 polls and
  1,376 body steps. Window key storage, real main-loop scheduling and config
  parsing remain outside the executable comparison; shift suppression is a
  harness input, not recovered modifier transport.
- **Recorded:** synthetic object kernels contain 780 near/cylinder/box rows and
  150 dynamics rows. Response tolerance is `2e-6` relative; resource-pointer
  input is excluded, the other-car pointer is compared as a boolean, and dynamics
  checks velocity, angular velocity and sleep state. This does not prove the
  object-world builder, tree query or full collision-pass composition.
- **Recorded domain:** the launch recorder defines **19 runs: 8 launch and 11
  barrier**, rather than the PR description's 23. They use Castle/Alps support,
  993 and 356 A geometry, with damage disabled. Body contact, hard-landing reset,
  body-point order and barrier impact are covered in this controlled composition;
  the live support-normal binding and damage-on gameplay require separate proof.
- **Read or inferred:** damage helper, seed algorithm, start placement, options,
  weather, particles, sky, water, reflections, sun/flare and front-end changes
  retain that evidence class. Synthetic tests and screenshots do not turn them
  into original-execution comparisons. Wheel-article classification remains an
  installed-data inference. The no-parts engine helper is a bounded domain.

Game-derived recordings remain ignored local files. The committed object fixture
uses synthetic inputs. The [local recording guide](../../iterations/012-campaign-fidelity/LOCAL-FIXTURES.md)
describes regeneration; missing-recording tests can return successfully after a
`SKIPPED` message, so counts alone are insufficient for acceptance.

## Corrections and default behavior

- Player collision writeback now preserves the nine pair-owned damage zones,
  including barrier-only calls without an object world, while retaining car zone
  9. Added composed regressions cover barrier damage on/off and player-car impact.
- Cargo feature `experimental-original-port` is disabled by default in assets
  and viewer. It gates the new object-world collision integration as a whole
  (including A177 sign hulls and A178 bush response), fixed installed seed 8165
  (A202), AI node-up start frame (A211), cached-normal tilted contact (A235),
  and new sky mapping/drift assumptions (A194/A195). Kernels, parsers, research
  helpers and explicit recording comparison entry points remain available.
- Water alpha classification keeps the source render method; the A190 pixel
  distribution heuristic is removed. Missing `lens` artwork is left unresolved
  instead of substituting `FLR1` (A272).
- Car reflections are off by default in renderer, browser and web state. `Y` or
  `?reflection=1` explicitly enables the approximate A71 blend. Shader validation
  includes both the baseline and experimental sky sources.

These controls preserve the existing prototype's other documented limits; they
do not establish full original behavior for the remaining read-only ports.

The same feature also gates the renderer's alternate collision path and awake
smackables, guessed crate playback (A172), particle culling/blending (A250/A252),
precipitation initialization (A280), sun/flare blending (A270), compare-camera and
hinge animation (A230/A232), and the flat animated track wall (A220). Static cars
and objects and the existing spark path remain available in the default build.
The web front end reads the compiled feature flag from WASM; it cannot silently
activate these experiments. Runtime reflection remains a separate explicit opt-in.

The loopback development server now accepts a larger pending-connection queue.
The initial browser run hit two refused resource connections during the parallel
track load with the old five-connection queue; the final server loaded the track
and original front end without browser errors.

## Validation and next acceptance

Local validation passes in the review worktree against the indexed game assets:

- **610 distinct Rust tests in each feature mode**, including damage writeback,
  keyboard, object, shader and road comparisons. Three existing Vulkan/resource
  diagnostics remain explicitly ignored; no missing-fixture/asset skips occurred.
  The workspace's 606 passing tests and the final road target's eight tests overlap
  in four unchanged road tests. The initial three pending road tests were executed
  after recording, and one new NaN comparison guard test was added.
- **19 recorded drives / 3,840 body steps**: eight launch runs (1,376 body / 688
  dynamics rows) and eleven barrier runs (2,464 / 1,232). The launch recorder's
  determinism check completed. After a chat interruption, two independent
  `--only barrier --once` runs wrote separate directories; all three output files
  compare byte for byte. The recording processes ran hidden and independently of
  the chat to preserve their outputs.
- The `alps/wall_90` original produces a NaN heading. TSV stores only `NaN`, losing
  its sign/payload. Only that heading field accepts any NaN encoding when the
  recorded value is `NaN`; finite values, signed zero and all other fields retain
  exact bit checks. Negative controls prevent this from becoming a general float
  tolerance. This fixture does not prove NaN payload identity.
- All **43 local fixture files** are present. After LF normalization, 42 match the
  author's manifest; `vehicle-sim.tsv` retains the already reviewed
  `928coupeGTS54.sim` input revision difference from PR25. Four unchanged support
  recordings reuse PR25's accepted files and hashes; other recordings were
  generated locally. The **930 synthetic object runs** regenerate exactly.
- Native workspace/all-target checks, release tests in both modes, default and
  experimental release WASM builds, and experimental WASM workspace check pass.
  All **45 web tests** and snapshot-isolation checks pass.
- Browser WebGPU smoke passes in both feature modes: Alps Quick Race reaches green,
  the car accelerates, the track/cars/sky/HUD render without browser errors. The
  default original front end also renders. Screenshots are retained locally.
  These are smoke checks, not full native visual, weather, career or fidelity
  acceptance. The default WASM package remains separate from the opt-in package.

Repeat with generated fixtures and `NFS_LOCAL_FIXTURES` set to their directory:

```text
cargo test --release --locked --offline --workspace -- --nocapture
cargo test --release --locked --offline --workspace --all-features -- --nocapture
cargo check --locked --offline --workspace --target wasm32-unknown-unknown --all-features
node --test web/*.test.mjs
```

Run Cargo/Node commands from `iterations/012-campaign-fidelity`; snapshot isolation
uses `py -3 scripts/test_iterations.py` at the repository root. Source whitespace
checks exclude TSV: trailing tabs preserve empty fixture columns and must not be
trimmed. No original game files or asset-derived recordings are added to Git.

PR metadata, description, diff and check logs are retained under ignored repository
`local/reports/pr26-review-20261028/`; the worktree's
`local/reports/pr26-physics-review.json` records scoped byte comparisons and review
findings. `fixture-hashes-final.json` pins generated file hashes and row counts;
the final Cargo logs and browser screenshots identify the reviewed checkout.

Some `A<n>` and `docs/re/*.md`, `docs/approximations.md` and
`docs/implementation-status.md` references still point to the author's separate
research workspace. They are unresolved external documentation, not repository
evidence. Obtain those notes or trace the relevant original consumers before
promoting their algorithms or enabling gated approximations by default. C++ intake
must continue through the [binary index](../../research/binary-index/README.md),
canonical owners and original-x86/native comparisons, one subsystem batch at a time.
Complete careers, full UI, live audio/devices, native visuals and full-game
acceptance remain open.
