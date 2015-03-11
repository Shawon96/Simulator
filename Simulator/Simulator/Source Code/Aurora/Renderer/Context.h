#ifndef Renderer_Context_h
#define Renderer_Context_h

#include "RenderState/RenderStateOperations.h"
#include "../Math/Geometry/GeometryOperations.h"
#include "Buffers/BuffersOperations.h"
#include "VertexArray/VertexArrayOperations.h"

namespace Aurora {
	namespace Renderer {
		using namespace Aurora::Math::Geometry;
		using namespace Aurora::Renderer::Buffers;
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

				virtual void MakeCurrent() = 0;
				//virtual VertexArray CreateVertexArray(Mesh mesh, ShaderVertexAttributeCollection shaderAttributes, BufferHint usageHint);
		};

	};
};
#endif