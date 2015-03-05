#ifndef Renderer_GraphicsWindow_h
#define Renderer_GraphicsWindow_h



namespace Aurora {
	namespace Renderer {
		class GraphicsWindow
		{
			private:

			public:
				virtual void Run(double updateRate) = 0;
		};

	};
};
#endif