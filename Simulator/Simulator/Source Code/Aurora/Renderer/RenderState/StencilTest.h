#ifndef Renderer_RenderState_StencilTest_h
#define Renderer_RenderState_StencilTest_h

#include "StencilTestFace.h"

namespace Aurora {
	namespace Renderer {
		class StencilTest
		{
		private:
			bool enabled;
			std::shared_ptr<StencilTestFace> frontFace;
			std::shared_ptr<StencilTestFace> backFace;
		public:
			StencilTest()
			{
				enabled = false;
				frontFace = std::make_shared<StencilTestFace>();
				backFace = std::make_shared<StencilTestFace>();
			}
			
			bool Enabled() const {
				return enabled;
			}
			template<typename T>
			void Enabled(T &&value) {
				enabled = std::forward<T>(value);
			}
			
			std::shared_ptr<StencilTestFace> FrontFace() const {
				return frontFace;
			}
			template<typename T>
			void FrontFace(T &&value) {
				frontFace = std::forward<T>(value);
			}
			
			std::shared_ptr<StencilTestFace> BackFace() const {
				return backFace;
			}
			template<typename T>
			void BackFace(T &&value) {
				backFace = std::forward<T>(value);
			}
		};

	};
};
#endif