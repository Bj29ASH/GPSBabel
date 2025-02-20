/*
 * gbversion.h is generated from gbversion.h.in which uses autoconf voodoo
 * to get the version number from configure.ac.
 *
 * Isn't simplification via automation grand?
 */
#ifdef RC_INVOKED
// These defines are for the Microsoft resource compiler scripts
// win32/gpsbabel.rc and gui/app.rc
#define VER_FILE 1,9,0,33
#define VER_PRODUCT 1,9,0,33
#define VER_FILE_STR "1.9.0"
#define VER_PRODUCT_STR "1.9.0"
#define VER_COPYRIGHT_STR L"\x00a9 2002-2024 Robert Lipe"
#else
#define VERSION "1.9.0"
constexpr char kVersionSHA[] = "";
constexpr char kVersionDate[] = "";
#define WEB_DOC_DIR "https://www.gpsbabel.org/htmldoc-1.9.0"
#endif
