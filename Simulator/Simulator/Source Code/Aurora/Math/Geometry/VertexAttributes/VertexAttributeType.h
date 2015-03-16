#ifndef GeometryOperations_VertexAttributes_VertexAttributeType_H
#define GeometryOperations_VertexAttributes_VertexAttributeType_H


namespace Aurora
{
	namespace Math
	{
		namespace Geometry
		{
			enum class VertexAttributeType
			{
				UnsignedByte,
				HalfFloat,
				HalfFloatVector2,
				HalfFloatVector3,
				HalfFloatVector4,
				Float,
				FloatVector2,
				FloatVector3,
				FloatVector4,
				EmulatedDoubleVector3
			};
		};
	};
};

#endif