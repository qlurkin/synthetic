#pragma once

#ifdef SYN_PLATFORM_WINDOWS
	
#else
	#error Synthetic only support Windows for now...
#endif

#ifdef SYN_ENABLE_ASSERTS
	#define SYN_ASSERT(x, ...) { if(!(x)) { SYN_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define SYN_CORE_ASSERT(x, ...) { if(!(x)) { SYN_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak; } }
#else
	#define SYN_ASSERT(x, ...)
	#define SYN_CORE_ASSERT(x, ...)
#endif
