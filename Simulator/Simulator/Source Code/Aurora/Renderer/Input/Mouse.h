#ifndef Renderer_Mouse_h
#define Renderer_Mouse_h

#include "MouseButtonEventArgs.h"

namespace Aurora {
	namespace Renderer {
		namespace Input
		{
			class Mouse
			{
			private:

			public:
				Mouse() = default;
				virtual ~Mouse() = default;

				Event<MouseButtonEventArgs> ButtonDown;
				Event<MouseButtonEventArgs> ButtonUp;
				Event<MouseMoveEventArgs> Move;

			protected:
				virtual void OnButtonDown(const Vector2DInt &point, MouseButton button)
				{
					ButtonDown(MouseButtonEventArgs(point, button, MouseButtonEvent::ButtonDown));
				}

				virtual void OnButtonUp(const Vector2DInt &point, MouseButton button)
				{
					ButtonUp(MouseButtonEventArgs(point, button, MouseButtonEvent::ButtonUp));
				}

				virtual void OnMove(const Vector2DInt &point)
				{
					Move(MouseMoveEventArgs(point));
				}
			};
		};
	};
};
#endif