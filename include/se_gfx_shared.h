#ifndef SE_GFX_SHARED_H
#define SE_GFX_SHARED_H

#include "core.h"

namespace se
{
	namespace gfx
	{
		typedef unsigned short SurfaceDimension;
		typedef  unsigned char ChannelLayout_t;
		enum class ChannelLayout :ChannelLayout_t
		{
			R		= 1,
			x1		= 1,

			RG		= 2,
			x2		= 2,

			RGB		= 3,
			x3		= 3,
			
			RGBA	= 4,
			x4		= 4
		};

		const ChannelLayout DEFAULT_CHANNEL_LAYOUT = ChannelLayout::x4;
		typedef unsigned char ChannelType_t;
		enum class ChannelType :ChannelType_t
		{
			int8,
			int16,
			int32,

			float16,
			float32
		};
		const ChannelType DEFAULT_CHANNEL_TYPE = ChannelType::float32;
		class ChannelFormat
		{
		public:
			/// <summary>READ ONLY ChannelLayout&lt;unsigned char&gt;</summary>
			SE_CORE_READONLY_PROPERTY(ChannelFormat, ChannelLayout_t, layout);
			/// <summary>READ ONLY ChannelType&lt;unsigned char&gt;</summary>
			SE_CORE_READONLY_PROPERTY(ChannelFormat, ChannelType_t, type);
			ChannelFormat(ChannelLayout _layout, ChannelType _type)
			{
				layout.value = static_cast<ChannelLayout_t>(_layout);
				type.value = static_cast<ChannelType_t>(_type);
			}
			ChannelFormat()
			{
				layout.value = static_cast<ChannelLayout_t>(
					DEFAULT_CHANNEL_LAYOUT);
				type.value = static_cast<ChannelType_t>(
					DEFAULT_CHANNEL_TYPE);
			}
		};
		const ChannelFormat DEFAULT_CHANNEL_FORMAT =
			ChannelFormat(ChannelLayout::x4, ChannelType::float32);
		const SurfaceDimension DEFAULT_SCREEN_WIDTH = 640;
		const SurfaceDimension DEFAULT_SCREEN_HEIGHT = 480;
		const bool DEFAULT_SCREEN_FULLSCREEN_STATE = false;

	}
}


#endif