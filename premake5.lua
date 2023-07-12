workspace "Neutron"
	architecture "x64"
	
	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Neutron"
	location "Neutron"
	kind "SharedLib"
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
		"%{prj.name}/vendor/spdlog/include"
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


	filter "configurations:Release"
		defines "NT_RELEASE"
		optimize "On"
	
		
	filter "configurations:Dist"
		defines "NT_DIST"
		optimize "On"


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


	filter "configurations:Release"
		defines "NT_RELEASE"
		optimize "On"
	
		
	filter "configurations:Dist"
		defines "NT_DIST"
		optimize "On"


