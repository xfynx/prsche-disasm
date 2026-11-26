# Run862: locale-sensitive wide comparison wrapper

Recovers complete `crt_wcsnicoll_005ad68c` (`005ad68c..005ad76c`, 225 bytes) and binds the symbol reached by Run857. The implementation preserves zero-count short-circuiting, canonical reader/writer synchronization, original interlocked function pointers, lock 19, locale/codepage forwarding, locale reread after locking, all release paths, the `CompareString`-style `result - 2` bias, and failure return `INT_MAX` with errno 22.

Native attempt 002 passes ten relocated original-x86/C++ cases at `/Od` and `/O2` with 42 events per variant and detects all five material mutations. The matrix covers default and localized engines, results 0/1/2/3, writer/no-writer paths, and locale mutation while acquiring the lock.

The wrapper closes `crt_wcsnicoll_005ad68c`. Its two original engines remain explicit next dependencies: `crt_wcsnicoll_default_005ae901` and `crt_wcsnicoll_locale_005ae6b6`. Neither is replaced with a host CRT or ASCII approximation.
