#ifndef Renderer_Buffers_PixelBufferHint_h
#define Renderer_Buffers_PixelBufferHint_h

#include "../../IO/IOOperations.h"
#include "../../Globals/GlobalOperations.h"

namespace Aurora {
	namespace Renderer {
		namespace Buffers {
			using namespace Aurora::IO;
			using namespace Aurora::Global;
			enum class PixelBufferHint
			{
				Stream,
				Static,
				Dynamic,
			};

			
		};
	};
};
#endif