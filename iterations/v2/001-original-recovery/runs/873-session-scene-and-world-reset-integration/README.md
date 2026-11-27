# Session scene and world reset

[Build 001](build-001.json) compiled 506 translation units in eight projects. All ten direct session-reset callees now have compiled providers. The full link moved from 37 unresolved names / 39 references to **39 names / 42 references**. The former direct dependency at `004690a0` closed. Two route sample getters and the emitter reset at `004581a0` became reachable, and the scene route binder gained one caller.

[Run869](../869-selected-player-scene-reset/README.md) selects the player after world and scene callbacks. [Run870](../870-world-list-reset/README.md) traverses world rows and releases their nested records. [Run872](../872-world-row-reset/README.md) recovers each row's initializer and radius. [Run871](../871-scene-records-reset/README.md) initializes two emitter records and provides three x87 samplers.

The [audit](validation.json) passed 2,554 native comparisons and 16 mutation controls with 1,255 source pins. Nine indexed entries were added. No executable was produced. [Acceptance inputs](acceptance.json)
