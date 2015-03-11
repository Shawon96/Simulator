#ifndef Renderer_KeyboardKeyEventArgs_h
#define Renderer_KeyboardKeyEventArgs_h

#include "KeyboardKeyEvent.h"
#include "KeyboardKey.h"

namespace Aurora {
	namespace Renderer {
		namespace Input
		{

			class KeyboardKeyEventArgs
			{
			private:
				KeyboardKeyEvent keyboardEvent;
				KeyboardKey key;
			public:
				KeyboardKeyEventArgs(KeyboardKeyEvent keyboardEvent, KeyboardKey key)
				{
					keyboardEvent = keyboardEvent;
					key = key;
				}
				virtual ~KeyboardKeyEventArgs();

				Aurora::Renderer::KeyboardKeyEvent KeyboardEvent() const {
					return keyboardEvent;
				}

				Aurora::Renderer::KeyboardKey Key() const {
					return key;
				}

			};
		};
	};
};
#endif