#ifndef Renderer_Buffers_IndexBuffer_h
#define Renderer_Buffers_IndexBuffer_h


#include "BufferHint.h"

namespace Aurora {
	namespace Renderer {
		namespace Buffers {
			enum class IndexBufferDatatype
			{
				//
				// OpenGL supports byte indices but D3D does not.  We do not use them 
				// because they are unlikely to have a speed or memory benefit:
				//
				// http://www.opengl.org/discussion_boards/ubbthreads.php?ubb=showflat&Number=285547
				//

				UnsignedShort,
				UnsignedInt
			};

			template<typename T>
			class IndexBuffer
			{
			public:
				virtual void CopyFromSystemMemory(const UniqueDynamicTypeVector<T> &bufferInSystemMemory);
				

				virtual void CopyFromSystemMemory(const UniqueDynamicTypeVector<T> &bufferInSystemMemory, int destinationOffsetInBytes);

				void CopyFromSystemMemory(
					std::shared_ptr<UniqueDynamicTypeVector<T>> bufferInSystemMemory,
					int destinationOffsetInBytes,
					int lengthInBytes) = 0;

				virtual std::shared_ptr<UniqueDynamicTypeVector<T>> CopyToSystemMemory();

				std::shared_ptr<UniqueDynamicTypeVector<T>> CopyToSystemMemory(int offsetInBytes, int sizeInBytes) = 0;

				int SizeInBytes() = 0;
				IndexBufferDatatype Datatype() = 0;
				BufferHint UsageHint() = 0;
			};

			template<typename T>
			std::shared_ptr<UniqueDynamicTypeVector<T>> Aurora::Renderer::Buffers::IndexBuffer<T>::CopyToSystemMemory()
			{
				return CopyToSystemMemory(0, SizeInBytes);
			}

			template<typename T>
			void Aurora::Renderer::Buffers::IndexBuffer<T>::CopyFromSystemMemory(const UniqueDynamicTypeVector<T> &bufferInSystemMemory, int destinationOffsetInBytes)
			{
				CopyFromSystemMemory<T>(bufferInSystemMemory, destinationOffsetInBytes, sizeof(UniqueDynamicTypeVector<T>) + (sizeof(T) * bufferInSystemMemory.size()));
			}

			template<typename T>
			void Aurora::Renderer::Buffers::IndexBuffer<T>::CopyFromSystemMemory(const UniqueDynamicTypeVector<T> &bufferInSystemMemory)
			{
				CopyFromSystemMemory(bufferInSystemMemory, 0);
			}

		};
	};
};
#endif