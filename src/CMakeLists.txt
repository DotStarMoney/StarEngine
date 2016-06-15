cmake_minimum_required(VERSION 3.2)
project(StarEngine)


set(SRC_FILES 
	
	main.cpp 
	gfx.cpp
	core.cpp
	texture.cpp
	referencetracker.cpp
	datacache.cpp
		
	PARENT_SCOPE)

source_group("Source Files" FILES ${SRC_FILES})