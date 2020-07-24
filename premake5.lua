workspace "Synthetic"
	architecture "x64"

	configurations {
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "Synthetic/vendor/glfw/include"

include "Synthetic/vendor/glfw"

project "Synthetic"
	location "Synthetic"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-obj/" .. outputdir .. "/%{prj.name}")

	pchheader "pch.h"
	pchsource "Synthetic/src/pch.cpp"

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	defines {
		"_CRT_SECURE_NO_WARNINGS"
	}

	includedirs {
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}"
	}

	links {
		"GLFW",
		"opengl32.lib"
	}

	filter "system:windows"
		systemversion "latest"

		defines {
			"SYN_PLATFORM_WINDOWS",
			"SYN_BUILD_DLL"
		}

	filter "configurations:Debug"
		defines {
			"SYN_DEBUG",
			"SYN_ENABLE_ASSERTS"
		}
		symbols "on"

	filter "configurations:Release"
		defines "SYN_RELEASE"
		optimize "on"

	filter "configurations:Dist"
		defines "SYN_DIST"
		symbols "on"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-obj/" .. outputdir .. "/%{prj.name}")

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"Synthetic/src",
		"Synthetic/vendor/spdlog/include"
	}

	links {
		"Synthetic"
	}

	filter "system:windows"
		systemversion "latest"

		defines {
			"SYN_PLATFORM_WINDOWS",
		}

	filter "configurations:Debug"
		defines {
			"SYN_DEBUG",
			"SYN_ENABLE_ASSERTS"
		}
		symbols "on"

	filter "configurations:Release"
		defines "SYN_RELEASE"
		optimize "on"

	filter "configurations:Dist"
		defines "SYN_DIST"
		symbols "on"


