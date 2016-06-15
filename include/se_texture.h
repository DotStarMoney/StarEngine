#ifndef SE_TEXTURE_H
#define SE_TEXTURE_H

#include "surface.h"
#include "se_gfx_shared.h"
#include "GL\glew.h"
#include "GLFW\glfw3.h"
#include <string>
#include "referencetracker.h"


// core includes an asset cache, can flush individual items from there

namespace se
{
	namespace gfx
	{
		class Texture : public Surface
		{
		public:
			Texture(const std::string& _filename);
			Texture(
				const std::string& _filename, 
				const ChannelFormat& _format);
			Texture(
				const std::string& _filename,
				SurfaceDimension _texw, SurfaceDimension _texh);
			Texture(
				const std::string& _filename,
				SurfaceDimension _texw, SurfaceDimension _texh,
				const ChannelFormat& _format);
			Texture(const ChannelFormat& _format);
			Texture(SurfaceDimension _texw, SurfaceDimension _texh);
			Texture(
				SurfaceDimension _texw, SurfaceDimension _texh,
				const ChannelFormat& _format);
			Texture(const Texture& _tex);
			Texture();
			~Texture();
			Texture& operator=(const Texture& _tex);
			void convert_format(const ChannelFormat& _format);
			bool is_dimensionless();
		private:
			void forego_reference();
			static ChannelFormat glint_to_format(GLint _internal_format);
		private:
			bool unknown_dimension; // texture can adapt its size if dimension is unknown
			bool unknown_reference; // if the texture is not used by anything nor loaded from a file,
									//    we don't yet have a reference for it
			
			ReferenceTracker::key_t ref_id;
			SurfaceDimension width;
			SurfaceDimension height;
			ChannelFormat format;
			GLuint gl_id;

		};

	}

}


#endif