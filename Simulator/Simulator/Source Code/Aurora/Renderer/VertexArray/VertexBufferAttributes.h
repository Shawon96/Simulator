#ifndef Renderer_RenderState_VertexBufferAttributes_h
#define Renderer_RenderState_VertexBufferAttributes_h

#include "VertexBufferAttribute.h"


namespace Aurora {
	namespace Renderer {
		namespace VertexArray {
			template<typename ComponentDataType>
			class VertexBufferAttributes
			{
			public:
				virtual std::shared_ptr<VertexBufferAttribute<ComponentDataType>> VertexBufferAttributesCollection() = 0;
				virtual int Count() = 0;
				virtual int MaximumCount() = 0;
			};
		};
	};
};

#endif