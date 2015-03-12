#ifndef Renderer_Shaders_ShaderVertexAttribute_h
#define Renderer_Shaders_ShaderVertexAttribute_h

#include "../../Globals/GlobalDatatypes.h"

namespace Aurora {
	namespace Renderer {
		namespace Shaders {
			using namespace Aurora::DataTypes;
			enum class ShaderVertexAttributeType
			{
				Float,
				FloatVector2,
				FloatVector3,
				FloatVector4,
				FloatMatrix22,
				FloatMatrix33,
				FloatMatrix44,
				Int,
				IntVector2,
				IntVector3,
				IntVector4
			};

			class ShaderVertexAttribute
			{
			private:
				std::string name;
				int location;
				ShaderVertexAttributeType type;
				int length;
			public:
				ShaderVertexAttribute(
					std::string name,
					int location,
					ShaderVertexAttributeType type,
					int length)
				{
					name = name;
					location = location;
					type = type;
					length = length;
				}

				virtual ~ShaderVertexAttribute() = default;

				std::string Name() const {
					return name;
				}
				template<typename T>
				void Name(T &&value) {
					name = std::forward<T>(value);
				}

				int Location() const {
					return location;
				}
				template<typename T>
				void Location(T &&value) {
					location = std::forward<T>(value);
				}

				Aurora::Renderer::Shaders::ShaderVertexAttributeType Type() const {
					return type;
				}
				template<typename T>
				void Type(T &&value) {
					type = std::forward<T>(value);
				}

				int Length() const {
					return length;
				}
				template<typename T>
				void Length(T &&value) {
					length = std::forward<T>(value);
				}	
			};
		};

	};
};
#endif