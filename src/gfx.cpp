#include "gfx.h"
#include "se_gfx.h"
#include "core.h"
#include "debug.h"
#include "referencetracker.h"
#include "GL\glew.h"
#include "GLFW\glfw3.h"

namespace se
{
	namespace gfx
	{

		se::ReferenceTracker gfx_controller::texture_reference;

		void screen(
			const char* _title,
			gfx::SurfaceDimension _scrx,
			gfx::SurfaceDimension _scry,
			bool _fullscreen)
		{
			gfx_controller::screen(_title, _scrx, _scry, _fullscreen);
		}
		void screen(
			gfx::SurfaceDimension _scrx,
			gfx::SurfaceDimension _scry,
			bool _fullscreen)
		{
			gfx_controller::screen(se::VERSION_STRING,
				_scrx,
				_scry,
				_fullscreen);
		}
		void screen(
			const char* _title,
			gfx::SurfaceDimension _scrx,
			gfx::SurfaceDimension _scry)
		{
			gfx_controller::screen(se::VERSION_STRING,
				_scrx,
				_scry,
				Default::FULLSCREEN_STATE);
		}
		void screen(
			gfx::SurfaceDimension _scrx,
			gfx::SurfaceDimension _scry)
		{
			gfx_controller::screen(se::VERSION_STRING,
				_scrx,
				_scry,
				Default::FULLSCREEN_STATE);
		}
		void screen()
		{
			gfx_controller::screen(se::VERSION_STRING,
				Default::SCREEN_WIDTH ,
				Default::SCREEN_HEIGHT,
				Default::FULLSCREEN_STATE);
		}
		void set_window_title(const std::string& _title)
		{
			gfx_controller::set_window_title(_title);
		}
		const std::string& get_window_title()
		{
			return gfx_controller::get_window_title();
		}
		gfx::SurfaceDimension get_screen_width()
		{
			return gfx_controller::get_screen_width();
		}
		gfx::SurfaceDimension get_screen_height()
		{
			return gfx_controller::get_screen_width();
		}


		gfx_controller::context_info gfx_controller::context;
		gfx_controller::static_init gfx_controller::static_init_object;
		gfx_controller::static_init::static_init()
		{
			DEBUG_ASSERT(glfwInit(), "Unable to initialize GLFW.");
#ifdef __APPLE__
			glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
			glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
			glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
			glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#endif
			context.exists = false;
			glewExperimental = GL_TRUE;
		}
		gfx_controller::static_init::~static_init()
		{
			if (context.exists)
			{
				glfwDestroyWindow(context.window);
			}
			glfwTerminate();
		}
		void gfx_controller::screen(
			const char* _title,
			gfx::SurfaceDimension _scrx,
			gfx::SurfaceDimension _scry,
			bool _fullscreen)
		{
			GLFWmonitor* fscreen_ptr;
			if (context.exists && (context.fullscreen != _fullscreen))
			{
				glfwDestroyWindow(context.window);
				context.exists = false;
			}
			if (!context.exists)
			{
				if (_fullscreen)
				{
					fscreen_ptr = glfwGetPrimaryMonitor();
					context.fullscreen = true;
				}
				else
				{
					fscreen_ptr = nullptr;
					context.fullscreen = false;
				}
				glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
				context.window = glfwCreateWindow(
					_scrx,
					_scry,
					_title,
					fscreen_ptr,
					nullptr);
				if (context.window)
				{
					glfwMakeContextCurrent(context.window);
					context.scrx = _scrx;
					context.scry = _scry;
					context.window_title = _title;
					if (glewInit() == GLEW_OK)
					{
						context.exists = true;
						//TODO: Other gl initialization
						//TODO: Screen resize notification
					}
					else
					{
						glfwDestroyWindow(context.window);
						// WARNING: glew unable to initialize
					}
				}
				else
				{
					// WARNING: glfw unable to open window
				}
			}
			else
			{
				if ((_scrx != context.scrx) || (_scry != context.scry))
				{
					glfwSetWindowSize(context.window, _scrx, _scry);
					context.scrx = _scrx;
					context.scry = _scry;
					//TODO: Screen resize notification
				}
				context.window_title = _title;
				glfwSetWindowTitle(context.window, _title);
			}
		}
		void gfx_controller::set_window_title(const std::string& _title)
		{
#ifdef DEBUG_ERROR_MISUSE
			if (!context.exists) {
				// WARNING: No context available upon which to set window title
				return;
			}
#endif
			context.window_title = _title;
			glfwSetWindowTitle(context.window, _title.c_str());
		}
		const std::string& gfx_controller::get_window_title()
		{
#ifdef DEBUG_ERROR_MISUSE
			if (!context.exists) {
				// WARNING: No context available from which to get window title
				return;
			}
#endif
			return context.window_title;
		}
		gfx::SurfaceDimension gfx_controller::get_screen_width()
		{
#ifdef DEBUG_ERROR_MISUSE
			if (!context.exists) {
				// WARNING: No context available from which to get screen width
				return;
			}
#endif
			return context.scrx;
		}
		gfx::SurfaceDimension gfx_controller::get_screen_height()
		{
#ifdef DEBUG_ERROR_MISUSE
			if (!context.exists) {
				// WARNING: No context available from which to get screen height
				return;
			}
#endif
			return context.scry;
		}
	}
}