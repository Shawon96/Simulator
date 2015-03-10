#ifndef Renderer_Context_h
#define Renderer_Context_h

#include "RenderState/RenderStateOperations.h"

namespace Aurora {
	namespace Renderer {
		enum class ClearBuffers
		{
			ColorBuffer = 1,
			DepthBuffer = 2,
			StencilBuffer = 4,
			ColorAndDepthBuffer = ColorBuffer | DepthBuffer,
			All = ColorBuffer | DepthBuffer | StencilBuffer
		};

		class Context
		{
			private:

			public:
				Context() = default;
				virtual ~Context() = default;
		};

	};
};
#endif