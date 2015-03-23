#ifndef Renderer_RenderState_ScissorTest_h
#define Renderer_RenderState_ScissorTest_h

#include "../../Math/DataTypes/Rectangle.h"

namespace Aurora {
	namespace Renderer {
		namespace RenderState {

			using namespace Aurora::Math;
			using namespace Aurora::Math::DataTypes;
			class ScissorTest
			{

			private:
				bool enabled;

				Aurora::Math::DataTypes::Rectangle<int> rectangle;
			public:
				ScissorTest()
				{
					enabled = false;
					//rectangle = Rectangle<int>(0, 0, 0, 0);
					rectangle = Aurora::Math::DataTypes::Rectangle<int>(0,0,0,0);
				}

				virtual ~ScissorTest() = default;

				bool Enabled() const {
					return enabled;
				}
				template<typename T>
				void Enabled(T &&value) {
					enabled = std::forward<T>(value);
				}

				Aurora::Math::DataTypes::Rectangle<int> Rectangle() const {
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