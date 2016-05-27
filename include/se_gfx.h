#ifndef SE_GFX_H
#define SE_GFX_H

#include <string>
#include "se_gfx_shared.h"
#include "texture.h"

namespace se
{
	namespace gfx
	{
		const SurfaceDimension DEFAULT_SCREEN_WIDTH = 640;
		const SurfaceDimension DEFAULT_SCREEN_HEIGHT = 480;
		const bool DEFAULT_SCREEN_FULLSCREEN_STATE = false;
		const ChannelFormat DEFAULT_CHANNEL_FORMAT = 
			ChannelFormat(ChannelLayout::x4, ChannelType::float32);
		void screen(
			const char* _title,
			SurfaceDimension _scrx,
			SurfaceDimension _scry,
			bool _fullscreen);
		void screen(
			SurfaceDimension _scrx,
			SurfaceDimension _scry,
			bool _fullscreen);
		void screen(
			const char* _title,
			SurfaceDimension _scrx,
			SurfaceDimension _scry);
		void screen(
			SurfaceDimension _scrx,
			SurfaceDimension _scry);
		void screen();
		void set_window_title(const std::string& _title);
		const std::string& get_window_title();
		SurfaceDimension get_screen_width();
		SurfaceDimension get_screen_height();

	}
}

#endif