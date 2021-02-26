#pragma once
#ifdef ME_PLATFORM_WINDOWS
	#ifdef ME_BUILD_DLL
		#define MIDESTINYENGINE_API __declspec(dllexport)
	#else
		#define MIDESTINYENGINE_API __declspec(dllimport)
	#endif
#else
	#error Midestiny Engine only supports windows
#endif