#ifndef Renderer_MouseMoveEventArgs_h
#define Renderer_MouseMoveEventArgs_h

#include "../../Math/Vector2D.h"

using namespace Aurora::Math;

namespace Aurora {
	namespace Renderer {
		class MouseMoveEventArgs
		{
		private:
			Vector2DInt point;
			
		public:
			MouseMoveEventArgs(const Aurora::Math::Vector2DInt &point)
			{
				this->point = point;
			}
			virtual ~MouseMoveEventArgs() = default;

			Vector2DInt Point() const {
				return point;
			}
		};

	};
};
#endif