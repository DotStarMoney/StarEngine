cmake_minimum_required(VERSION 3.2)
project(StarEngine)


set(HDR_FILES 
	
	debug.h
	core.h
	gfx.h
	se_gfx.h 
	se_texture.h
	surface.h
	se_gfx_shared.h
	referencetracker.h
	noncopyable.h
	datacache.h
	
	PARENT_SCOPE)

source_group("Header Files" FILES ${HDR_FILES})