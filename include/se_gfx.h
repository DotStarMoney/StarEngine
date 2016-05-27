#ifndef SE_GFX_H
#define SE_GFX_H

#include <string>
#include "se_gfx_shared.h"
#include "se_texture.h"

namespace se
{
	namespace gfx
	{
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