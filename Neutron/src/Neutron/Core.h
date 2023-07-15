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

#ifdef NT_ENABLE_ASSERTS
	#define NT_ASSERT(x, ...) { if(!(x)) { NT_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define NT_CORE_ASSERT(x, ...) { if(!(x)) { NT_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS_); __debugbreak(); } }
#else
	#define NT_ASSERT(x, ...)
	#define NT_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)
