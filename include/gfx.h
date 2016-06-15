#ifndef GFX_H
#define GFX_H

#include "se_gfx_shared.h"
#include <string>
#include "GL\glew.h"
#include "GLFW\glfw3.h"
#include "referencetracker.h"

namespace se
{
	namespace gfx
	{


		class gfx_controller
		{
			friend class Texture;
		public:
			static void screen(
				const char* _title,
				gfx::SurfaceDimension _scrx,
				gfx::SurfaceDimension _scry,
				bool _fullscreen);
			static void set_window_title(const std::string& _title);
			static const std::string& get_window_title();
			static gfx::SurfaceDimension get_screen_width();
			static gfx::SurfaceDimension get_screen_height();
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
				gfx::SurfaceDimension scrx;
				gfx::SurfaceDimension scry;
			};
			static context_info context;
			static ReferenceTracker texture_reference;

		};
	}
}

#endif