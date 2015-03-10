#ifndef Renderer_RenderState_PrimitiveRestart_h
#define Renderer_RenderState_PrimitiveRestart_h

namespace Aurora {
	namespace Renderer {

		class PrimitiveRestart
		{
		private:
			bool enabled;
			int index;
		public:
			PrimitiveRestart()
			{
				enabled = false;
				index = 0;
			}

			virtual ~PrimitiveRestart() = default;

			int Index() const {
				return index;
			}
			template<typename T>
			void Index(T &&value) {
				index = std::forward<T>(value);
			}

			bool Enabled() const {
				return enabled;
			}
			template<typename T>
			void Enabled(T &&value) {
				enabled = std::forward<T>(value);
			}
		};
	};
};
#endif