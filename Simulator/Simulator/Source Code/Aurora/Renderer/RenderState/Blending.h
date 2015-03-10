#ifndef Renderer_RenderState_Blending_h
#define Renderer_RenderState_Blending_h

#include "../../Globals/GlobalDatatypes.h"

using namespace Aurora::DataTypes;

namespace Aurora {
	namespace Renderer {
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
		public:
			Blending()
			{
				Enabled = false;
				SourceRGBFactor = SourceBlendingFactor::One;
				SourceAlphaFactor = SourceBlendingFactor::One;
				DestinationRGBFactor = DestinationBlendingFactor::Zero;
				DestinationAlphaFactor = DestinationBlendingFactor::Zero;
				RGBEquation = BlendEquation::Add;
				AlphaEquation = BlendEquation::Add;
				Color = Aurora::DataTypes::ColorFloat(0, 0, 0, 0);
			}

			bool Enabled;
			SourceBlendingFactor SourceRGBFactor;
			SourceBlendingFactor SourceAlphaFactor;
			DestinationBlendingFactor DestinationRGBFactor;
			DestinationBlendingFactor DestinationAlphaFactor;
			BlendEquation RGBEquation;
			BlendEquation AlphaEquation;
			Aurora::DataTypes::ColorFloat Color;
		};

	};
};
#endif