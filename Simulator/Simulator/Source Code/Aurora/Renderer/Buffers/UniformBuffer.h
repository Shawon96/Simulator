#ifndef Renderer_Buffers_UniformBuffer_h
#define Renderer_Buffers_UniformBuffer_h




namespace Aurora {
	namespace Renderer {
		namespace Buffers {
			template<typename T>
			class UniformBuffer
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
				BufferHint UsageHint() = 0;
			};

			template<typename T>
			std::shared_ptr<UniqueDynamicTypeVector<T>> Aurora::Renderer::Buffers::UniformBuffer<T>::CopyToSystemMemory()
			{
				return CopyToSystemMemory(0, SizeInBytes);
			}

			template<typename T>
			void Aurora::Renderer::Buffers::UniformBuffer<T>::CopyFromSystemMemory(const UniqueDynamicTypeVector<T> &bufferInSystemMemory, int destinationOffsetInBytes)
			{
				CopyFromSystemMemory<T>(bufferInSystemMemory, destinationOffsetInBytes, sizeof(UniqueDynamicTypeVector<T>) + (sizeof(T) * bufferInSystemMemory.size()));
			}

			template<typename T>
			void Aurora::Renderer::Buffers::UniformBuffer<T>::CopyFromSystemMemory(const UniqueDynamicTypeVector<T> &bufferInSystemMemory)
			{
				CopyFromSystemMemory(bufferInSystemMemory, 0);
			}
		};
	};
};
#endif