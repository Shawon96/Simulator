#ifndef Renderer_RenderState_FacetCulling_h
#define Renderer_RenderState_FacetCulling_h

#include "../../Math/Geometry/GeometryOperations.h"
using namespace Aurora::Math::Geometry;

namespace Aurora {
	namespace Renderer {
		namespace RenderState {
			enum class CullFace
			{
				Front,
				Back,
				FrontAndBack
			};

			class FacetCulling
			{
			private:
				bool enabled;
				CullFace face;
				WindingOrder frontFaceWindingOrder;
			public:
				FacetCulling()
				{
					enabled = true;
					face = CullFace::Back;
					frontFaceWindingOrder = WindingOrder::Counterclockwise;
				}


				bool Enabled() const {
					return enabled;
				}
				template<typename T>
				void Enabled(T &&value) {
					enabled = std::forward<T>(value);
				}


				CullFace Face() const {
					return face;
				}
				template<typename T>
				void Face(T &&value) {
					face = std::forward<T>(value);
				}
				Aurora::Math::Geometry::WindingOrder FrontFaceWindingOrder() const {
					return frontFaceWindingOrder;
				}
				template<typename T>
				void FrontFaceWindingOrder(T &&value) {
					frontFaceWindingOrder = std::forward<T>(value);
				}
			};
		};
	};
};
#endif