# Campaign UI identity: 012 evidence and correction

## Confirmed original behavior

- `local/game/FEData/Layouts/GameSetup.lay:195-226` has separate buttons for Evolution (`stringID=12404`, `callback=SETTYPECAREERMODE`, position `9,119`) and Factory Driver (`stringID=12409`, `callback=SETTYPEFACTORYDRIVER`, position `50,95`). `local/game/FEData/Locale/festrings.csv:2231,2235` resolves those labels. Factory appears above Evolution in the original main-menu coordinates; the 011 button order was already correct.
- `local/game/FEData/Layouts/tournament.lay:1-9` uses `room=ID_GARAGE`, `callbacklist=ID_TOURNYSCREEN`; `garage.lay:1-8,32,46` uses `ID_GARAGE` and `OwnedCars.Car`. The garage connection is direct layout evidence; mapping each recovered tournament screen to Evolution still requires executable trace evidence.
- `local/game/FEData/Layouts/factorydriver.lay:1-18,36-41,147-151` uses `room=ID_FACTORY`, `callbacklist=ID_FACTORYCBL`, a mission briefing destination, team profiles destination, and `FactoryDriver.Car`. `missionbrief.lay:183-225` reads `Factory.Data(NARRNAME)` and `Factory.Data(MISSONDESC)`. This is a separate factory mission path.
- `local/game/FEData/Art/FactoryPeople.fsh` supplies the extracted `web/assets/people_rolp.png`; `local/game/FEData/Factory/0M01.fsh` corresponds to the extracted `web/assets/map_0m01.png` (the image is a numbered cone course). These images are Factory mission material. `GameSetup.lay:18-19` uses `MovieOval.fsh`; original layouts also refer to distinct garage and factory 3D rooms.

## Defect and 012 correction

- Copied `011/web/main.js` wired `#careerEvolutionBtn` straight to a hard-coded first 356 briefing even though `openEvolutionTournaments()` and the cups selector existed. In 012 it opens the cups selector. Selecting a cup still calls `showBriefing()` and keeps the existing race-start hook.
- The shared briefing previously showed Rolf, `map_0m01.png`, a cone-course caption, and `WEISSACH TEST CENTER` for Evolution races. `showBriefing()` now sets an explicit career mode. The Evolution variant hides the Factory portrait/map column and identifies the tournament; Factory missions retain those resources and their mission briefing. No asset from one mode is offered as the other's evidence.
- The web overlay remains a modern shared shell. Its pill buttons, dark card grids, specs, and 3D scene are not a pixel-accurate reconstruction of the original 640x480 FE layouts or the `ID_FACTORY`/`ID_GARAGE` rooms. The room geometry, FSH layering, transitions, and exact campaign screen flow remain to be recovered and visually checked against the original executable. No assumption about `MovieOval.fsh` art being a Factory/Evolution background was made.

## Source-derived 640x480 factory briefing layer

The 012 factory variant of `#eventBriefingModal` now uses a 4:3 virtual canvas. The following CSS placements reproduce source `missionbrief.lay` coordinates as fractions of 640x480; these are element origins as encoded in the layout, pending verification of the original control anchor convention:

- `missionbrief.lay:113-117`: `FACTORYPIC` at `(147,235)`, `56x63`; the current extracted Rolf image is placed there. `:179-189`: narrator name at `(174,300)`, `100x30`, `univers7b.ffn`.
- `missionbrief.lay:215-228`: mission description at `(219,187)`, `269x180`, `univers8b.ffn`, black. `:321-385`: translucent white Gouraud panels at `(210,178) 280x200`, `(211,182) 272x192`, and `(149,178) 61x200` are represented with corresponding alpha gradients.
- `missionbrief.lay:145-165`: Map button at `(280,406)`, `80x18`, routes to `missionmap`. `:287-307`: Done at `(281,125)`, `80x18`. In 012 Map switches a separate view that displays the mission map; `missionmap.lay:125-145,248-267` has the reciprocal Briefing/Done button positions. The browser Race button remains a web runtime hook; no matching button exists in `missionbrief.lay`.
- `GameSetup.lay:193-237` provides Factory at `(50,95)`, `162x18` and Evolution at `(9,119)`, `152x18`, with separate callbacks. `singleplayer.lay:1-7` is a different `ID_MOVIEOVAL` screen for other race modes and should not be used as either campaign's briefing. `factorydriver.lay:145-151` has a 3D car control at `(110,230)`, `420x180` in `ID_FACTORY`. These screens cannot be reproduced by repositioning the current generic menu alone.

**Still missing:** decoded `MovieOval.fsh` layers for GameSetup, the rendered `ID_GARAGE` and `ID_FACTORY` rooms from `FEData/Models/{garage,factory}.crp` and their TPG/FSH textures, original `Univers7b/8b.ffn` rasterization, control anchor semantics, and reference captures from the executable. The factory briefing background is a neutral placeholder while those are unavailable; it is not asserted as original art. Existing extracted FactoryPeople/mission map images were already in the web snapshot; 012 adds no copied game resources.

## Checks

012 extraction is reproducible with `scripts/extract-fe-ui.ps1`: 119 PNGs in
`local/derived/fe-ui`, served read-only at `/assets/` by the local helper. No game assets
remain inside the 012 source snapshot. Repeated four-character FSH IDs use the last
source entry, matching the inherited extractor's effective selection, and are logged;
this selection is not a claim about original runtime layer/animation semantics.

`web/ui.test.mjs` exercises menu routing and both briefing identities; `web/verify-browser.cjs` targets 012 and captures both modes with Playwright. A full browser run requires a current 012 WASM build and game resources served by `scripts/serve-web.py`.
