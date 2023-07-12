#pragma once

#ifdef NT_PLATFORM_WINDOWS
	#ifdef NT_BUILD_DLL
		#define NEUTRON_API __declspec(dllexport)
	#else
		#define NEUTRON_API __declspec(dllimport)
	#endif

#else
	#error Neutron Only Supports Windows

#endif


#define BIT(x) (1 << x)
