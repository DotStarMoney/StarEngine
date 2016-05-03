#ifndef GFX_H
#define GFX_H

#include <string>
#include "GL\glew.h"
#include "GLFW\glfw3.h"

namespace se
{
	class gfx_controller
	{
	public:
		static void screen(
			const char* _title,
			int _scrx,
			int _scry,
			bool _fullscreen);
		static void set_window_title(const std::string& _title);
		static const std::string& get_window_title();
		static int get_screen_width();
		static int get_screen_height();
	private:
		class static_init
		{
		public:
			static_init();
			~static_init();
		};
		static static_init static_init_object;
		struct context_info
		{
			std::string window_title;
			bool exists;
			bool fullscreen;
			GLFWwindow* window;
			int scrx;
			int scry;
		};
		static context_info context;

	};

}

#endif