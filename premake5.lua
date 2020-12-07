include "./third-party/Premaker/customization/solution_items.lua"

workspace "AnsiStyle"

	architecture "x86_64"
	startproject "AnsiStyle"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

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

group "Build"
	include "third-party/Premaker"

group ""
	include "project"