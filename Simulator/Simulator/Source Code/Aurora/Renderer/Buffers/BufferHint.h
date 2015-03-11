#ifndef Renderer_Buffers_BufferHint_h
#define Renderer_Buffers_BufferHint_h




namespace Aurora {
	namespace Renderer {
		namespace Buffers {
			enum class BufferHint
			{
				StreamDraw,
				StreamRead,
				StreamCopy,
				StaticDraw,
				StaticRead,
				StaticCopy,
				DynamicDraw,
				DynamicRead,
				DynamicCopy,
			};
		};
	};
};
#endif