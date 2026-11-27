# Sky texture reload

Scene sky update `00460cd0` calls `0044d9a0` with the texture node, replacement chunk, tag and mode. The 103-byte wrapper parses the chunk into a 28-byte local, reloads the node, frees both nonnull scratch pointers in order and restores format preference slots 4 and 6. The 135-byte node method `00536510` reads the primary and optional palette formats, sign-extends the 16-bit dimensions, allocates a missing texture and submits pixels and palette payloads at offset 16. Run799 owns descriptor parsing. Runs537, 577 and 791 own format lookup, texture transfer and preference state.

[Native inputs](native-config.json) pin both complete original bodies. Attempt 001 passed 64 cases at each optimization level and detected five mutations. The fixture compares node bytes and state at each callback for existing textures, failed allocations, alternate descriptors, palettes and independently allocated scratch buffers. Driver calls are observed through controlled endpoints.
