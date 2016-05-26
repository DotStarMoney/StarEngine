#ifndef TEXTURE_H
#define TEXTURE_H

#include "surface.h"
#include "gfx_shared.h"
#include <string>

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
			Texture(const ChannelFormat& _format);
			Texture(SurfaceDimension _texw, SurfaceDimension _texh);
			Texture(
				SurfaceDimension _texw, 
				SurfaceDimension _texh,
				const ChannelFormat& _format);
			Texture(const Texture& _tex);
			Texture();
			~Texture();

		};

	}

}


#endif