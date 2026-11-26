# Session records and wide locale comparison

[Build 001](build-001.json) compiled 499 translation units. The [shared audit](validation.json) passed 260 native comparisons and eight mutation controls with 1,238 source pins. The link reports **38 unresolved names / 40 references**. Startup and gameplay still require a linked executable.

- [Run859](../859-session-records/README.md) closes the child reached by the session reset gate, including its variable-length parser, comparator, x87 reciprocal and original qsort binding. The callback at `0040e5f0` was missing from the automatic index.
- [Run862](../862-wide-locale-compare/README.md) closes the wide environment comparison wrapper. The default comparison engine at `005ae901` and localized engine at `005ae6b6` are newly reachable. The native cases exercise both call contracts and the original lock and errno behavior.

The registry gained three indexed entries and one supplemental entry. [Acceptance inputs](acceptance.json) identify the source, native receipts and canonical compiled providers.
