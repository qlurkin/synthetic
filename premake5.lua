workspace "Synthetic"
	architecture "x64"

	configurations {
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Synthetic"
	location "Synthetic"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-obj/" .. outputdir .. "/%{prj.name}")

	pchheader "pch.h"
	pchsource "Synthetic/src/pch.cpp"

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"%{prj.name}/src",
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines {
			"SYN_PLATFORM_WINDOWS",
			"SYN_BUILD_DLL"
		}

		postbuildcommands {
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "SYN_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "SYN_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "SYN_DIST"
		symbols "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-obj/" .. outputdir .. "/%{prj.name}")

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"Synthetic/src"
	}

	links {
		"Synthetic"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines {
			"SYN_PLATFORM_WINDOWS",
		}

	filter "configurations:Debug"
		defines "SYN_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "SYN_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "SYN_DIST"
		symbols "On"


