#ifndef Renderer_MouseButtonEventArgs_h
#define Renderer_MouseButtonEventArgs_h

#include "MouseMoveEventArgs.h"
#include "MouseButton.h"
#include "MouseButtonEvent.h"

namespace Aurora {
	namespace Renderer {
		namespace Input
		{
			class MouseButtonEventArgs
			{
			private:
				Vector2DInt point;
				MouseButton button;
				MouseButtonEvent buttonEvent;
			public:
				MouseButtonEventArgs(const Vector2DInt &point, MouseButton button, MouseButtonEvent buttonEvent)
				{
					this->point = point;
					this->button = button;
					this->buttonEvent = buttonEvent;
				}
				virtual ~MouseButtonEventArgs() = default;

				Vector2DInt Point() const {
					return point;
				}

				Aurora::Renderer::MouseButtonEvent ButtonEvent() const {
					return buttonEvent;
				}

				Aurora::Renderer::MouseButton Button() const {
					return button;
				}
			};
		};
	};
};
#endif