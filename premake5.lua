workspace "Neutron"
	architecture "x64"
	
	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

-- Include directories relative to the root folder	
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "Neutron/vendor/GLFW/include"
IncludeDir["Glad"] = "Neutron/vendor/Glad/include"

include "Neutron/vendor/GLFW"
include "Neutron/vendor/Glad"

project "Neutron"
	location "Neutron"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "ntpch.h"
	pchsource "Neutron/src/ntpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}"
	}

	links
	{
		"GLFW",
		"Glad",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"NT_PLATFORM_WINDOWS",
			"NT_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "NT_DEBUG"
		symbols "On"
		buildoptions "/MDd"


	filter "configurations:Release"
		defines "NT_RELEASE"
		optimize "On"
		buildoptions "/MD"
	
		
	filter "configurations:Dist"
		defines "NT_DIST"
		optimize "On"
		buildoptions "/MD"


project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")


	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"Neutron/vendor/spdlog/include",
		"Neutron/src"
	}

	links
	{
		"Neutron"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"NT_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "NT_DEBUG"
		symbols "On"
		buildoptions "/MDd"


	filter "configurations:Release"
		defines "NT_RELEASE"
		optimize "On"
		buildoptions "/MD"
	
		
	filter "configurations:Dist"
		defines "NT_DIST"
		optimize "On"
		buildoptions "/MD"


