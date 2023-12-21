#include "pch.h"
#include "CppUnitTest.h"
#include "../GraphLab4/GraphMatrix.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MatrixUnitTests
{
	TEST_CLASS(MatrixUnitTests)
	{
	public:

		TEST_METHOD(IsEmptyUTest)
		{
			GraphMatrix<int> graph;
			bool isEmpty = graph.isEmpty();
			Assert::IsTrue(isEmpty);
		}

		TEST_METHOD(ClearMatrixUTest)
		{
			GraphMatrix<int> graph;
			graph.addVertex();
			graph.clearMatrix();
			bool isEmptyAfterClearing = graph.isEmpty();
			Assert::IsTrue(isEmptyAfterClearing);
		}

		TEST_METHOD(AddVertexUTest)
		{
			GraphMatrix<int> graph;
			graph.addVertex();
			Assert::IsTrue(graph.vertexCount() == 1);
		}
		
		TEST_METHOD(AddEdgeUTest)
		{
			GraphMatrix<int> graph;
			graph.addVertex();
			graph.addVertex();
			graph.addEdge(0, 1, 1);
			Assert::IsTrue(graph.hasEdge(0, 1));
		}

		TEST_METHOD(RemoveEdgeUTest)
		{
			GraphMatrix<int> graph;
			graph.addVertex();
			graph.addVertex();
			graph.addEdge(0, 1, 1);
			graph.removeEdge(0, 1);
			Assert::IsFalse(graph.hasEdge(0, 1));
		}

		TEST_METHOD(RemoveVertexUTest)
		{
			GraphMatrix<int> graph;
			graph.addVertex();
			graph.addVertex();
			graph.addEdge(0, 1, 1);
			graph.removeVertex(0);
			Assert::IsTrue(graph.hasVertex(0));
			Assert::IsFalse(graph.hasEdge(0, 1));
		}

		TEST_METHOD(HasEdgeUTest)
		{
			GraphMatrix<int> graph;
			graph.addVertex();
			graph.addVertex();
			graph.addEdge(0, 1, 1);
			bool exists = graph.hasEdge(0, 1);
			Assert::IsTrue(exists);
		}

		TEST_METHOD(HasVertexUTest)
		{
			GraphMatrix<int> graph;
			graph.addVertex();
			bool exists = graph.hasVertex(0);
			Assert::IsTrue(exists);
		}

		TEST_METHOD(ComparisonOperatorUTest)
		{
			GraphMatrix<int> graph1, graph2;
			graph1.addVertex();
			graph1.addVertex();
			graph1.addEdge(0, 1, 1);
			graph2.addVertex();
			graph2.addVertex();
			graph2.addEdge(0, 1, 1);
			bool areEqual = (graph1 == graph2);
			Assert::IsTrue(areEqual);
		}

		TEST_METHOD(GreaterOrComparisonThanOperatorUTest)
		{
			GraphMatrix<int> graph1, graph2;
			graph1.addVertex();
			graph1.addVertex();
			graph1.addEdge(0, 1, 1);
			graph2.addVertex();
			graph2.addVertex();
			graph2.addEdge(0, 1, 1);
			graph2.addEdge(0, 1, 2);
			bool isSmaller = (graph1 >= graph2);
			Assert::IsTrue(isSmaller);
		}
		TEST_METHOD(SmallerOrComparisonThanOperatorUTest)
		{
			GraphMatrix<int> graph1, graph2;
			graph1.addVertex();
			graph1.addVertex();
			graph1.addEdge(0, 1, 1);
			graph2.addVertex();
			graph2.addVertex();
			graph2.addEdge(0, 1, 1);
			graph2.addEdge(0, 1, 2);
			bool isSmaller = (graph1 <= graph2);
			Assert::IsTrue(isSmaller);
		}
		TEST_METHOD(VertexCountUTest)
		{
			GraphMatrix<int> graph;
			graph.addVertex();
			graph.addVertex();
			size_t count = graph.vertexCount();
			Assert::AreEqual((size_t)2, count);
		}

		TEST_METHOD(EdgeCountUTest)
		{
			GraphMatrix<int> graph;
			graph.addVertex();
			graph.addVertex();
			graph.addEdge(0, 1, 1);
			size_t count = graph.edgeCount();
			Assert::AreEqual((size_t)1, count);
		}

		TEST_METHOD(VertexDegreeUTest)
		{
			GraphMatrix<int> graph;
			graph.addVertex();
			graph.addVertex();
			graph.addVertex();
			graph.addEdge(0, 1, 5);
			graph.addEdge(0, 2, 7);
			size_t degree = graph.vertexDegree(0);
			Assert::AreEqual((size_t)2, degree);
		}

		TEST_METHOD(EdgeDegreeUTest)
		{
			GraphMatrix<int> graph;
			graph.addVertex();
			graph.addVertex();
			graph.addEdge(0, 1, 5);
			int degree = graph.edgeDegree(0, 1);
			Assert::AreEqual((int)5, degree);
		}

	};
}
