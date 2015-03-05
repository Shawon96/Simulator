#include "Device.h"



namespace Aurora {
	namespace Renderer {



		std::shared_ptr<Device> Device::GetInstance()
		{
			if (instance == nullptr)
			{
				instance = std::make_shared<Device>();
			}
			/**/
			return instance;
		}

		std::shared_ptr<Device> Device::instance = nullptr;


	};
};
