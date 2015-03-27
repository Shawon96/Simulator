#ifndef Math_Polygons_EarClipping_H
#define Math_Polygons_EarClipping_H

#include <memory>
#include <array>
#include "../Geometry/Indices/IndicesOperations.h"
#include "../Vectors/EmulatedVector3D.h"
#include "../CollisionDetection/CollisionDetectionOperations.h"
#include "IndexedVector.h"


namespace Aurora
{

	namespace Math
	{
		namespace Polygons
		{
			using namespace Aurora::Math::Geometry;
			using namespace Aurora::Math::CollisionDetection;
			using namespace Aurora::Math;
			class EarClipping
			{
			public:
				static std::shared_ptr<IndicesUnsignedInt> Triangulate(const UniqueVector2DDoubleVector &positions)
				{
					
					//
					// O(n^3)
					//
					// There are several optimization opportunities:
					//   * http://www.geometrictools.com/Documentation/TriangulationByEarClipping.pdf
					//   * http://cgm.cs.mcgill.ca/~godfried/publications/triangulation.held.ps.gz
					//   * http://blogs.agi.com/insight3d/index.php/2008/03/20/triangulation-rhymes-with-strangulation/
					//

					/*if (positions == null)
					{
						throw new ArgumentNullException("positions");
					}*/

					//
					// Doubly linked list.  This would be a tad cleaner if it were also circular.
					//
					
					DynamicTypeArrayIndexedVector2DDouble remainingPositions(positions.size());

					int index = 0;
					for(auto &position : positions)
					{
						auto arrayIndex = index;
						remainingPositions[arrayIndex] = IndexedVector2DDouble(*position, index++);
					}

					if (remainingPositions.Size() < 3)
					{
						throw std::bad_function_call("Positions: At least three positions are required.");
					}

					std::shared_ptr<IndicesUnsignedInt> indices = std::make_shared<IndicesUnsignedInt>(3 * (remainingPositions.Size() - 2));

					///////////////////////////////////////////////////////////////////
					DynamicTypeArrayIndexedVector2DDouble::iterator remainingPositionsIterator = remainingPositions.begin();

					// Notice that we are referencing the unique pointers and also later we will check which elements is where by address for speed
					IndexedVector2DDouble &previousNode = *remainingPositionsIterator; remainingPositionsIterator++;
					IndexedVector2DDouble &node = *remainingPositionsIterator; remainingPositionsIterator++;
					IndexedVector2DDouble &nextNode = *remainingPositionsIterator;

					int bailCount = remainingPositions.Size() * remainingPositions.Size();

					while (remainingPositions.Size() > 3)
					{
						Vector2DDouble &p0 = previousNode.Vector();
						Vector2DDouble &p1 = node.Vector();
						Vector2DDouble &p2 = nextNode.Vector();

						if (IsTipConvex(p0, p1, p2))
						{
							bool isEar = true;
							// Go to the element after the nextNode to identify the start position for the for element
							remainingPositionsIterator++;
							for (DynamicTypeArrayIndexedVector2DDouble::iterator n = ((remainingPositionsIterator != remainingPositions.end()) ? remainingPositionsIterator : remainingPositions.begin());
								// Notice here we check that the previous node and present node by address
								n != &previousNode;
							// Go the next element, check if it is not the last element(empty element or the end of the list), if not then process the current element or start from the beginning
							n = (((remainingPositionsIterator++) != remainingPositions.end()) ? remainingPositionsIterator : remainingPositions.begin()))
							{
								
								if (ContainmentTests::PointInsideTriangle((*n).Vector(), p0, p1, p2))
								{
									isEar = false;
									break;
								}
							}

							if (isEar)
							{
								// TODO: Optimize here memory usage
								indices->AddTriangle(TriangleIndicesUnsignedInt(previousNode.Index(), node.Index(), nextNode.Index()));
								remainingPositions.remove(node.lock());

								node = nextNode;
								nextNode = (((remainingPositionsIterator++) != remainingPositions.end()) ? *remainingPositionsIterator : *remainingPositions.begin());
								continue;
							}
						}

						previousNode = (previousNode.Next != null) ? previousNode.Next : remainingPositions.First;
						node = (node.Next != null) ? node.Next : remainingPositions.First;
						nextNode = (nextNode.Next != null) ? nextNode.Next : remainingPositions.First;

						if (--bailCount == 0)
						{
							break;
						}
					}

					LinkedListNode<IndexedVector<Vector2D>> n0 = remainingPositions.First;
					LinkedListNode<IndexedVector<Vector2D>> n1 = n0.Next;
					LinkedListNode<IndexedVector<Vector2D>> n2 = n1.Next;
					indices.AddTriangle(new TriangleIndicesUnsignedInt(n0.Value.Index, n1.Value.Index, n2.Value.Index));

					return indices;
				}

				private:
					static bool IsTipConvex(const Vector2DDouble &p0, const Vector2DDouble & p1, const Vector2DDouble & p2)
				{
					Vector2DDouble u = p1 - p0;
					Vector2DDouble v = p2 - p1;

					//
					// Use the sign of the z component of the cross product
					//
					return ((u.X * v.Y) - (u.Y * v.X)) >= 0.0;
				}
			};
		};
	};
};

#endif