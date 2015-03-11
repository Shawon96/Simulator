#ifndef Renderer_RenderState_ScissorTest_h
#define Renderer_RenderState_ScissorTest_h

#include "../../Math/MathDataTypes.h"

namespace Aurora {
	namespace Renderer {
		namespace RenderState {

			using namespace Aurora::Math;
			class ScissorTest
			{

			private:
				bool enabled;

				Aurora::Math::Rectangle<int> rectangle;
			public:
				ScissorTest()
				{
					enabled = false;
					rectangle = Aurora::Math::Rectangle<int>(0, 0, 0, 0);
				}

				virtual ~ScissorTest() = default;

				bool Enabled() const {
					return enabled;
				}
				template<typename T>
				void Enabled(T &&value) {
					enabled = std::forward<T>(value);
				}

				Aurora::Math::Rectangle<int> Rectangle() const {
					return rectangle;
				}
				template<typename T>
				void Rectangle(T &&value) {
					rectangle = std::forward<T>(value);
				}
			};
		};
	};
};
#endif