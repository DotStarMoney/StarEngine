#ifndef SE_GFX_H
#define SE_GFX_H

#include <string>

namespace se
{
	namespace gfx
	{
		const int DEFAULT_SCREEN_WIDTH = 640;
		const int DEFAULT_SCREEN_HEIGHT = 480;
		const bool DEFAULT_SCREEN_FULLSCREEN_STATE = false;
		void screen(
			const char* _title,
			int _scrx,
			int _scry,
			bool _fullscreen);
		void screen(
			int _scrx,
			int _scry,
			bool _fullscreen);
		void screen(
			const char* _title,
			int _scrx,
			int _scry);
		void screen(
			int _scrx,
			int _scry);
		void screen();
		void set_window_title(const std::string& _title);
		const std::string& get_window_title();
		int get_screen_width();
		int get_screen_height();

	}
}

#endif