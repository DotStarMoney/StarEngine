#ifndef SE_GFX_SHARED_H
#define SE_GFX_SHARED_H

#include "core.h"

namespace se
{
	namespace gfx
	{
		typedef unsigned int SurfaceDimension;
		typedef unsigned char ChannelLayout_t;
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
		namespace Default
		{
			const se::gfx::ChannelLayout ChannelLayout = 
				se::gfx::ChannelLayout::RGBA;
		}
		typedef unsigned char ChannelType_t;
		enum class ChannelType :ChannelType_t
		{
			int8,
			int16,
			int32,

			float16,
			float32
		};
		namespace Default
		{
			const se::gfx::ChannelType ChannelType = 
				se::gfx::ChannelType::float32;
		}
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
					Default::ChannelLayout);
				type.value = static_cast<ChannelType_t>(
					Default::ChannelType);
			}
		};
		namespace Default
		{
			const se::gfx::ChannelFormat ChannelFormat =
			se::gfx::ChannelFormat
			(
				Default::ChannelLayout, 
				Default::ChannelType
			);
			const SurfaceDimension SCREEN_WIDTH = 640;
			const SurfaceDimension SCREEN_HEIGHT = 480;
			const bool FULLSCREEN_STATE = false;
		}

	}
}


#endif