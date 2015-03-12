#ifndef Renderer_ShaderVertexAttributeCollection_h
#define Renderer_ShaderVertexAttributeCollection_h

#include "Shaders/ShadersOperations.h"
#include "../Globals/GlobalOperations.h"
namespace Aurora {
	namespace Renderer {
		using namespace Aurora::Renderer::Shaders;
		using namespace Aurora::DataTypes;
		
		using ShaderVertexAttributeCollection = std::map < std::string, ShaderVertexAttribute > ;
	};
};
#endif