#ifndef Renderer_GraphicsWindow_h
#define Renderer_GraphicsWindow_h

#include "../Globals/GlobalOperations.h"
#include "Input/InputOperations.h"
#include "Context.h"


namespace Aurora {
	namespace Renderer {
		using namespace Aurora::Global;
		using namespace Aurora::Renderer::Input;
		class GraphicsWindow
		{
			private:
				
			public:
				GraphicsWindow() = default;
				virtual ~GraphicsWindow() = default;;
				Event<void> Resize;
				Event<void> UpdateFrame;
				Event<void> PreRenderFrame;
				Event<void> RenderFrame;
				Event<void> PostRenderFrame;

				

				virtual void Run(double updateRate) = 0;
				virtual std::shared_ptr<Context> Context() const = 0;
				virtual int Width() const = 0;
				virtual int Height() const = 0;
				virtual std::shared_ptr<Mouse> Mouse() const = 0;
				virtual std::shared_ptr<Keyboard> Keyboard() const = 0;

		protected:
			virtual void OnResize();
			virtual void OnUpdateFrame();
			virtual void OnPreRenderFrame();
			virtual void OnRenderFrame();
			virtual void OnPostRenderFrame();
		};

	};
};
#endif