#ifndef Renderer_RenderState_StencilTestFace_h
#define Renderer_RenderState_StencilTestFace_h

namespace Aurora {
	namespace Renderer {
		namespace RenderState {
			enum class StencilOperation
			{
				Zero,
				Invert,
				Keep,
				Replace,
				Increment,
				Decrement,
				IncrementWrap,
				DecrementWrap
			};

			enum class StencilTestFunction
			{
				Never,
				Less,
				Equal,
				LessThanOrEqual,
				Greater,
				NotEqual,
				GreaterThanOrEqual,
				Always,
			};

			class StencilTestFace
			{
			private:
				StencilOperation stencilFailOperation;
				StencilOperation depthFailStencilPassOperation;
				StencilOperation depthPassStencilPassOperation;
				StencilTestFunction function;
				int referenceValue;
				int mask;

			public:
				StencilTestFace()
				{
					stencilFailOperation = StencilOperation::Keep;
					depthFailStencilPassOperation = StencilOperation::Keep;
					depthPassStencilPassOperation = StencilOperation::Keep;
					function = StencilTestFunction::Always;
					referenceValue = 0;
					mask = ~0;
				}
				virtual ~StencilTestFace() = default;

				Aurora::Renderer::RenderState::StencilOperation StencilFailOperation() const {
					return stencilFailOperation;
				}
				template<typename T>
				void StencilFailOperation(T &&value) {
					stencilFailOperation = std::forward<T>(value);
				}

				Aurora::Renderer::RenderState::StencilOperation DepthFailStencilPassOperation() const {
					return depthFailStencilPassOperation;
				}
				template<typename T>
				void DepthFailStencilPassOperation(T &&value) {
					depthFailStencilPassOperation = std::forward<T>(value);
				}

				Aurora::Renderer::RenderState::StencilOperation DepthPassStencilPassOperation() const {
					return depthPassStencilPassOperation;
				}
				template<typename T>
				void DepthPassStencilPassOperation(T &&value) {
					depthPassStencilPassOperation = std::forward<T>(value);
				}

				Aurora::Renderer::RenderState::StencilTestFunction Function() const {
					return function;
				}
				template<typename T>
				void Function(T &&value) {
					function = std::forward<T>(value);
				}

				int ReferenceValue() const {
					return referenceValue;
				}
				template<typename T>
				void ReferenceValue(T &&value) {
					function = std::forward<T>(value);
				}

				int Mask() const {
					return mask;
				}
				template<typename T>
				void Mask(T &&value) {
					function = std::forward<T>(value);
				}


			};
		};
	};
};
#endif