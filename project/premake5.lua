project "AnsiStyle"

	kind "StaticLib"
	language "C++"
	staticruntime "on"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin/intermediates/" .. outputdir .. "/%{prj.name}")

	AnsiStyleIncludeDirs = {}
	AnsiStyleIncludeDirs["AnsiStyle"] = "%{prj.location}/"

	files
	{
		"**.h",
		"**.cpp",
	}

	includedirs
	{
		AnsiStyleIncludeDirs,
	}

