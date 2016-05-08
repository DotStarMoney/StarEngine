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
			Texture(SurfaceDimension _texx, SurfaceDimension _texy);
			Texture(
				SurfaceDimension _texx, 
				SurfaceDimension _texy,
				const ChannelFormat& _format);
			Texture();
			~Texture();

		};

	}

}


#endif