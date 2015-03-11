#ifndef Renderer_Buffers_WritePixelBuffer_h
#define Renderer_Buffers_WritePixelBuffer_h




namespace Aurora {
	namespace Renderer {
		namespace Buffers {
			template<typename T>
			class WritePixelBuffer
			{
			public:
				virtual void CopyFromSystemMemory(const std::vector<T> &bufferInSystemMemory);


				virtual void CopyFromSystemMemory(const std::vector<T> &bufferInSystemMemory, int destinationOffsetInBytes);

				void CopyFromSystemMemory(
					std::shared_ptr<std::vector<T>> bufferInSystemMemory,
					int destinationOffsetInBytes,
					int lengthInBytes) = 0;

				virtual std::shared_ptr<std::vector<T>> CopyToSystemMemory();

				std::shared_ptr<std::vector<T>> CopyToSystemMemory(int offsetInBytes, int sizeInBytes) = 0;

				Bitmap CopyToBitmap(int width, int height, PixelFormat pixelFormat) = 0;
				void CopyFromBitmap(Bitmap bitmap) = 0;

				int SizeInBytes() = 0;
				PixelBufferHint UsageHint() = 0;
			};

			template<typename T>
			std::shared_ptr<std::vector<T>> Aurora::Renderer::Buffers::WritePixelBuffer<T>::CopyToSystemMemory()
			{
				return CopyToSystemMemory(0, SizeInBytes);
			}

			template<typename T>
			void Aurora::Renderer::Buffers::WritePixelBuffer<T>::CopyFromSystemMemory(const std::vector<T> &bufferInSystemMemory, int destinationOffsetInBytes)
			{
				CopyFromSystemMemory<T>(bufferInSystemMemory, destinationOffsetInBytes, sizeof(std::vector<T>) + (sizeof(T) * bufferInSystemMemory.size()));
			}

			template<typename T>
			void Aurora::Renderer::Buffers::WritePixelBuffer<T>::CopyFromSystemMemory(const std::vector<T> &bufferInSystemMemory)
			{
				CopyFromSystemMemory(bufferInSystemMemory, 0);
			}
		};
	};
};
#endif