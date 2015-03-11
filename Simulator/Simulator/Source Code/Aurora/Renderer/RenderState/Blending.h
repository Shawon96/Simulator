#ifndef Renderer_RenderState_Blending_h
#define Renderer_RenderState_Blending_h

#include "../../Globals/GlobalDatatypes.h"

using namespace Aurora::DataTypes;

namespace Aurora {
	namespace Renderer {
		namespace RenderState {
			enum class SourceBlendingFactor
			{
				Zero,
				One,
				SourceAlpha,
				OneMinusSourceAlpha,
				DestinationAlpha,
				OneMinusDestinationAlpha,
				DestinationColor,
				OneMinusDestinationColor,
				SourceAlphaSaturate,
				ConstantColor,
				OneMinusConstantColor,
				ConstantAlpha,
				OneMinusConstantAlpha
			};

			enum class DestinationBlendingFactor
			{
				Zero,
				One,
				SourceColor,
				OneMinusSourceColor,
				SourceAlpha,
				OneMinusSourceAlpha,
				DestinationAlpha,
				OneMinusDestinationAlpha,
				DestinationColor,
				OneMinusDestinationColor,
				ConstantColor,
				OneMinusConstantColor,
				ConstantAlpha,
				OneMinusConstantAlpha
			};

			enum class BlendEquation
			{
				Add,
				Minimum,
				Maximum,
				Subtract,
				ReverseSubtract
			};

			class Blending
			{
			private:
				bool enabled;
				Aurora::DataTypes::ColorFloat color;
				SourceBlendingFactor sourceRGBFactor;
				SourceBlendingFactor sourceAlphaFactor;
				DestinationBlendingFactor destinationRGBFactor;
				DestinationBlendingFactor destinationAlphaFactor;
				BlendEquation rgbEquation;
				BlendEquation alphaEquation;
			public:
				Blending()
				{
					enabled = false;
					sourceRGBFactor = SourceBlendingFactor::One;
					sourceAlphaFactor = SourceBlendingFactor::One;
					destinationRGBFactor = DestinationBlendingFactor::Zero;
					destinationAlphaFactor = DestinationBlendingFactor::Zero;
					rgbEquation = BlendEquation::Add;
					alphaEquation = BlendEquation::Add;
					color = Aurora::DataTypes::ColorFloat(0, 0, 0, 0);
				}



				bool Enabled() const {
					return enabled;
				}
				template<typename T>
				void Enabled(T &&value) {
					enabled = std::forward<T>(value);
				}

				Aurora::Renderer::RenderState::SourceBlendingFactor SourceRGBFactor() const {
					return sourceRGBFactor;
				}
				template<typename T>
				void SourceRGBFactor(T &&value) {
					sourceRGBFactor = std::forward<T>(value);
				}

				Aurora::Renderer::RenderState::SourceBlendingFactor SourceAlphaFactor() const {
					return sourceAlphaFactor;
				}
				template<typename T>
				void SourceAlphaFactor(T &&value) {
					sourceAlphaFactor = std::forward<T>(value);
				}

				Aurora::Renderer::RenderState::DestinationBlendingFactor DestinationRGBFactor() const {
					return destinationRGBFactor;
				}
				template<typename T>
				void DestinationRGBFactor(T &&value) {
					destinationRGBFactor = std::forward<T>(value);
				}

				Aurora::Renderer::RenderState::DestinationBlendingFactor DestinationAlphaFactor() const {
					return destinationAlphaFactor;
				}
				template<typename T>
				void DestinationAlphaFactor(T &&value) {
					destinationAlphaFactor = std::forward<T>(value);
				}

				Aurora::Renderer::RenderState::BlendEquation RgbEquation() const {
					return rgbEquation;
				}
				template<typename T>
				void RgbEquation(T &&value) {
					rgbEquation = std::forward<T>(value);
				}

				Aurora::Renderer::RenderState::BlendEquation AlphaEquation() const {
					return alphaEquation;
				}
				template<typename T>
				void AlphaEquation(T &&value) {
					alphaEquation = std::forward<T>(value);
				}

				Aurora::DataTypes::ColorFloat Color() const {
					return color;
				}
				template<typename T>
				void Color(T &&value) {
					color = std::forward<T>(value);
				}
			};
		};
	};
};
#endif