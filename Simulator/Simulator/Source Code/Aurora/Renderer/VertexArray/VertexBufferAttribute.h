#ifndef Renderer_RenderState_VertexBufferAttribute_h
#define Renderer_RenderState_VertexBufferAttribute_h


#include "../Buffers/BuffersOperations.h"
#include "ComponentDatatype.h"

namespace Aurora {
	namespace Renderer {
		namespace VertexArray {
			using namespace Aurora::Renderer::Buffers;
			template<typename ComponentDatatype>
			class VertexBufferAttribute
			{
			private:
				std::shared_ptr<VertexBuffer<ComponentDatatype>> vertexBuffer;
				
				int numberOfComponents;
				bool normalize;				
				int offsetInBytes;
				int strideInBytes;
			public:
				VertexBufferAttribute() = default;
				virtual ~VertexBufferAttribute() = default;
				VertexBufferAttribute(const VertexBufferAttribute &value) : vertexBuffer(value.VertexBuffer()), numberOfComponents(value.numberOfComponents), offsetInBytes(value.offsetInBytes), normalize(value.normalize), strideInBytes(value.strideInBytes)
				{

				}
				VertexBufferAttribute(VertexBufferAttribute &&value) : vertexBuffer(std::move(value.VertexBuffer())), numberOfComponents(value.numberOfComponents), offsetInBytes(value.offsetInBytes), normalize(value.normalize), strideInBytes(value.strideInBytes)
				{
					value.VertexBuffer(nullptr);
				}
				VertexBufferAttribute &operator=(VertexBufferAttribute && value)
				{
					if (this == &value)
						return *this;

					return *this;
				}
				VertexBufferAttribute& operator=(const VertexBufferAttribute& value)
				{
					if (this == &value)
						return *this;

					return *this;
				}

				VertexBufferAttribute(std::shared_ptr<VertexBuffer<ComponentDatatype>> vertexBuffer, int numberOfComponents) : this(vertexBuffer, numberOfComponents, false, 0, 0)
				{
				}

				VertexBufferAttribute(std::shared_ptr<VertexBuffer<ComponentDatatype>> vertexBuffer, int numberOfComponents, bool normalize, int offsetInBytes, int strideInBytes)
				{
					if (numberOfComponents <= 0)
					{
						throw std::bad_function_call("numberOfComponents: numberOfComponents must be greater than zero.");
					}

					if (offsetInBytes < 0)
					{
						throw std::bad_function_call("offsetInBytes: offsetInBytes must be greater than or equal to zero.");
					}

					if (strideInBytes < 0)
					{
						throw std::bad_function_call("stride: stride must be greater than or equal to zero.");
					}

					vertexBuffer = vertexBuffer;
					numberOfComponents = numberOfComponents;
					normalize = normalize;
					offsetInBytes = offsetInBytes;

					if (strideInBytes == 0)
					{
						//
						// Tightly packed
						//
						strideInBytes = sizeof(std::vector<T>) + (sizeof(T) * numberOfComponents);
					}
					else
					{
						strideInBytes = strideInBytes;
					}
				}
				
				std::shared_ptr<VertexBuffer<ComponentDatatype>> VertexBuffer() const {
					return vertexBuffer;
				}


				template<typename T>
				void VertexBuffer(T &&value) {
					vertexBuffer = std::forward<T>(value);
				}

				int NumberOfComponents() const {
					return numberOfComponents;
				}

				bool Normalize() const {
					return normalize;
				}

				int OffsetInBytes() const {
					return offsetInBytes;
				}

				int StrideInBytes() const {
					return strideInBytes;
				}

			};
		};
	};
};

#endif