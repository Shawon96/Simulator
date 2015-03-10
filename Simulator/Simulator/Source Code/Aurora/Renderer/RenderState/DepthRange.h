#ifndef Renderer_RenderState_DepthRange_h
#define Renderer_RenderState_DepthRange_h

#include <memory>

namespace Aurora {
	namespace Renderer {
		class DepthRange
		{
		private:
			double near;
			double far;
		public:
			DepthRange()
			{
				near = 0.0;
				far = 1.0;
			}

			double Near() const {
				return near;
			}
			template<typename T>
			void Near(T &&value) {

				near = std::forward<T>(value);
			}

			double Far() const {
				return far;
			}
			template<typename T>
			void Far(T &&value) {
				

				near = std::forward<T>(value);
			}
			
		};

	};
};
#endif