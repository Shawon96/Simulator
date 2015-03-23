#ifndef Renderer_Context_h
#define Renderer_Context_h

#include "RenderState/RenderStateOperations.h"
//#include "../Math/Geometry/GeometryOperations.h"
#include "Buffers/BuffersOperations.h"
#include "VertexArray/VertexArrayOperations.h"
#include "ShaderVertexAttributeCollection.h"

namespace Aurora {
	namespace Renderer {
		using namespace Aurora::Math::Geometry;
		using namespace Aurora::Renderer::Buffers;
		using namespace Aurora::Renderer::VertexArray;
		enum class ClearBuffers
		{
			ColorBuffer = 1,
			DepthBuffer = 2,
			StencilBuffer = 4,
			ColorAndDepthBuffer = ColorBuffer | DepthBuffer,
			All = ColorBuffer | DepthBuffer | StencilBuffer
		};

		template<typename Type>
		class Context
		{
			private:

			public:
				Context() = default;
				virtual ~Context() = default;

				virtual void MakeCurrent() = 0;
				//virtual VertexArray<Type> CreateVertexArray(const Mesh &mesh, SharedShaderVertexAttributeCollection shaderAttributes, BufferHint usageHint);
				
		};

	};
};
#endif