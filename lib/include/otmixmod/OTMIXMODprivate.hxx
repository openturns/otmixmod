
#ifndef OTMIXMOD_PRIVATE_HXX
#define OTMIXMOD_PRIVATE_HXX

/* From http://gcc.gnu.org/wiki/Visibility */
/* Generic helper definitions for shared library support */
#if defined(_WIN32) || defined(__CYGWIN__)
#define OTMIXMOD_HELPER_DLL_IMPORT __declspec(dllimport)
#define OTMIXMOD_HELPER_DLL_EXPORT __declspec(dllexport)
#define OTMIXMOD_HELPER_DLL_LOCAL
#else
#ifdef __GNUC__
#define OTMIXMOD_HELPER_DLL_IMPORT __attribute__ ((visibility ("default")))
#define OTMIXMOD_HELPER_DLL_EXPORT __attribute__ ((visibility ("default")))
#define OTMIXMOD_HELPER_DLL_LOCAL  __attribute__ ((visibility ("hidden")))
#else
#define OTMIXMOD_HELPER_DLL_IMPORT
#define OTMIXMOD_HELPER_DLL_EXPORT
#define OTMIXMOD_HELPER_DLL_LOCAL
#endif
#endif

/* Now we use the generic helper definitions above to define OTMIXMOD_API and OTMIXMOD_LOCAL.
 * OTMIXMOD_API is used for the public API symbols. It either DLL imports or DLL exports (or does nothing for static build)
 * OTMIXMOD_LOCAL is used for non-api symbols. */

#ifndef OTMIXMOD_STATIC /* defined if OT is compiled as a DLL */
#ifdef OTMIXMOD_DLL_EXPORTS /* defined if we are building the OT DLL (instead of using it) */
#define OTMIXMOD_API OTMIXMOD_HELPER_DLL_EXPORT
#else
#define OTMIXMOD_API OTMIXMOD_HELPER_DLL_IMPORT
#endif /* OTMIXMOD_DLL_EXPORTS */
#define OTMIXMOD_LOCAL OTMIXMOD_HELPER_DLL_LOCAL
#else /* OTMIXMOD_STATIC is defined: this means OT is a static lib. */
#define OTMIXMOD_API
#define OTMIXMOD_LOCAL
#endif /* !OTMIXMOD_STATIC */


#endif // OTMIXMOD_PRIVATE_HXX

