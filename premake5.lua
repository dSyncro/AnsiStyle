include "./third-party/Premaker/customization/solution_items.lua"

workspace "AnsiStyle"

	startproject "AnsiStyle"

	solution_items 
	{
		".gitignore",
		".editorconfig",
	}
	
	flags
	{
		"MultiProcessorCompile"
	}

	outputdir = "%{cfg.architecture}/%{cfg.system}/%{cfg.buildcfg}"

	include "./third-party/Premaker/configurations.lua"

include "third-party/Premaker"
include "project"