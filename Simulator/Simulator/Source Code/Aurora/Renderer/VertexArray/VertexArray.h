#ifndef Renderer_RenderState_VertexArray_h
#define Renderer_RenderState_VertexArray_h


#include "VertexBufferAttributes.h"
#include "../Buffers/BuffersOperations.h"

namespace Aurora {
	namespace Renderer {
		namespace VertexArray {
			using namespace Aurora::Renderer::Buffers;

			template<typename T>
			class VertexArray
			{
			private:
				bool disposeBuffers;
				IndexBuffer<T> indexBufferData;


			public:
				VertexArray() = default;
				virtual ~VertexArray() = default;

				virtual VertexBufferAttributes Attributes() = 0;

				IndexBuffer<T> IndexBufferData() const {
					return indexBufferData;
				}
				template<typename T>
				void IndexBufferData(T &&value) {
					indexBufferData = std::forward<T>(value);
				}

				bool DisposeBuffers() const {
					return disposeBuffers;
				}
				template<typename T>
				void DisposeBuffers(T &&value) {
					disposeBuffers = std::forward<T>(value);
				}
			};
		};
	};
};

#endif