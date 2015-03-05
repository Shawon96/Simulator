#ifndef Renderer_Device_h
#define Renderer_Device_h

#include <memory>

namespace Aurora {
	namespace Renderer {
		enum class WindowType
		{
			Default = 0,
			FullScreen = 1
		};

		class Device
		{
			private:
				static std::shared_ptr<Device> instance;
			public:
				Device() = default;
				virtual ~Device() = default;

				std::shared_ptr<Device> GetInstance();

				//static void CreateWindow(int width, int height);

		};

	};
};
#endif