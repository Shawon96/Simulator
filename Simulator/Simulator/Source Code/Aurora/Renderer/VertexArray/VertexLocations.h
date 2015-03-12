#ifndef Renderer_RenderState_VertexLocations_h
#define Renderer_RenderState_VertexLocations_h




namespace Aurora {
	namespace Renderer {
		namespace VertexArray {
			class VertexLocations
			{
			public:
				static const int Position = 0;
				static const int  Normal = 2;
				static const int  TextureCoordinate = 3;
				static const int  Color = 4;

				//
				// Having Position and PositionHigh share the same location
				// allows different shaders to share the same vertex array,
				// even if one is using DSFUN90 and one is not.
				//
				// FYI There is/was an ATI bug where location was required:
				//
				// http://www.opengl.org/discussion_boards/ubbthreads.php?ubb=showflat&Number=286280
				//
				static const int  PositionHigh = Position;
				static const int  PositionLow = 1;
			};
		};
	};
};

#endif