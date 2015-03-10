#ifndef Renderer_Keyboard_h
#define Renderer_Keyboard_h

#include "KeyboardKeyEventArgs.h"

namespace Aurora {
	namespace Renderer {

		class Keyboard
		{
		private:

		public:
			Keyboard() = default;
			virtual ~Keyboard() = default;

			Event<KeyboardKeyEventArgs> KeyDown;
			Event<KeyboardKeyEventArgs> KeyUp;
		protected:
			virtual void OnKeyDown(const KeyboardKey &key)
			{
				KeyDown(KeyboardKeyEventArgs(KeyboardKeyEvent::Down, key));
			}

			virtual void OnKeyUp(const KeyboardKey &key)
			{
				KeyDown(KeyboardKeyEventArgs(KeyboardKeyEvent::Up, key));
			}
		};

	};
};
#endif