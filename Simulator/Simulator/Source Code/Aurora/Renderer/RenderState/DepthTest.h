#ifndef Renderer_RenderState_DepthTest_h
#define Renderer_RenderState_DepthTest_h


namespace Aurora {
	namespace Renderer {
		namespace RenderState {

			enum class DepthTestFunction
			{
				Never,
				Less,
				Equal,
				LessThanOrEqual,
				Greater,
				NotEqual,
				GreaterThanOrEqual,
				Always
			};

			class DepthTest
			{
			private:
				bool enabled;
				DepthTestFunction function;
			public:
				DepthTest()
				{
					enabled = true;
					function = DepthTestFunction::Less;
				}
				virtual ~DepthTest();

				bool Enabled() const {
					return enabled;
				}
				template<typename T>
				void Enabled(T &&value) {
					enabled = std::forward<T>(value);
				}

				DepthTestFunction Function() const {
					return function;
				}
				template<typename T>
				void Function(T &&value) {
					function = std::forward<T>(value);
				}
			};
		};
	};
};
#endif