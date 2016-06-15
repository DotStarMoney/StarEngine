#include "se_texture.h"
#include "gfx.h"
#include "stb_image.h"

// how to categorize and catch errors?
// rethink how internal formats are specified.
// also consider texture file caching

namespace se
{
	namespace gfx
	{
		/*
		Texture::Texture(const std::string& _filename)
		{
			GLint in_format;
			// first fit scheme in memory pool, tracked in doubling container
			// if we need to insert, find least damaging region to boot out (compute while doing our first fit),
			//    so if first fit fails, we know where to drop the new block

			// DEBUG WARNING EXCEPTION: gl_id == 0;
			unknown_dimension = false;
			unknown_reference = false;
			ref_id = gfx_controller::texture_reference.acquire();
			glBindTexture(GL_TEXTURE_2D, gl_id);
			glGetTexLevelParameteriv(
				GL_TEXTURE_2D, 0, GL_TEXTURE_WIDTH, &((GLint&) width));
			glGetTexLevelParameteriv(
				GL_TEXTURE_2D, 0, GL_TEXTURE_HEIGHT, &((GLint&) height));
			glGetTexLevelParameteriv(
				GL_TEXTURE_2D, 0, GL_TEXTURE_INTERNAL_FORMAT, &in_format);
			format = glint_to_format(in_format);
		}
		Texture::Texture(
			const std::string& _filename,
			const ChannelFormat& _format)
		{
			glGenTextures(1, &(this->gl_id));
			ref_id = gfx_controller::texture_reference.acquire();
			format = _format;
			unknown_dimension = false;
			unknown_reference = false;
			// load texture and force to format
		}
		Texture::Texture(
			const std::string& _filename,
			SurfaceDimension _texw, SurfaceDimension _texh)
		{
			glGenTextures(1, &(this->gl_id));
			ref_id = gfx_controller::texture_reference.acquire();
			width = _texw;
			height = _texh;
			unknown_dimension = false;
			unknown_reference = false;
			// load texture and force to size
		}

		Texture::Texture(
			const std::string& _filename,
			SurfaceDimension _texw, SurfaceDimension _texh,
			const ChannelFormat& _format)
		{
			glGenTextures(1, &(this->gl_id));
			ref_id = gfx_controller::texture_reference.acquire();
			width = _texw;
			height = _texh;
			format = _format;
			unknown_dimension = false;
			unknown_reference = false;
			// load texture and force to format/size
		}
		Texture::Texture(const ChannelFormat& _format)
		{
			format = _format;
			unknown_dimension = true;
			unknown_reference = true;
		}
		Texture::Texture(SurfaceDimension _texw, SurfaceDimension _texh)
		{
			format = Default::ChannelFormat;
			width = _texw;
			height = _texh;
			unknown_dimension = false;
			unknown_reference = true;
		}
		Texture::Texture(
			SurfaceDimension _texw, SurfaceDimension _texh,
			const ChannelFormat& _format)
		{
			width = _texw;
			height = _texh;
			format = _format;
			unknown_dimension = false;
			unknown_reference = true;
		}
		Texture::Texture()
		{
			format = Default::ChannelFormat;
			unknown_dimension = true;
			unknown_reference = true;
		}
		Texture::~Texture()
		{	
			forego_reference();
		}
		Texture::Texture(const Texture& _tex)
		{
			if (this == &_tex) return;
			*this = _tex;
			if (!unknown_reference)
				gfx_controller::texture_reference.inc(ref_id);
		}
		Texture& Texture::operator=(const Texture& _tex)
		{
			if (this == &_tex) return *this;
			forego_reference();
			*this = _tex;
			if (!unknown_reference)
				gfx_controller::texture_reference.inc(ref_id);
			return *this;
		}
		void Texture::forego_reference()
		{
			if (!unknown_reference)
			{
				if (gfx_controller::texture_reference.dec(ref_id))
				{
					glDeleteTextures(1, &gl_id);
				}
			}
		}
		
		ChannelFormat glint_to_format(GLint _internal_format)
		{
			//
			return Default::ChannelFormat;
		}
		*/
	}
}