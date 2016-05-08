#ifndef GFX_SHARED_H
#define GFX_SHARED_H

namespace se
{
	namespace gfx
	{
		typedef unsigned short SurfaceDimension;

		enum class ChannelLayout :unsigned char
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
		enum class ChannelType :unsigned char
		{
			int8,
			int16,
			int32,

			float16,
			float32
		};
		class ChannelFormat
		{
			friend class Texture;
		public:
			ChannelFormat(ChannelLayout _layout, ChannelType _type)
			{
				layout_ = _layout;
				type_ = _type;
			}
			ChannelLayout layout() { return layout_; }
			ChannelType type() { return type_; }
		private:
			ChannelLayout layout_;
			ChannelType type_;
		};

	}
}


#endif