#include <iostream>
#include "cube.hpp"
#include "vertex.hpp"

namespace shapes
{

Cube::Cube()
{
  using namespace gfx;
  { 
  /* front face */
  Vertex v1 = mesh.AddVertex(10, 10, 10);
  Vertex v2 = mesh.AddVertex(20, 10, 10);
  Vertex v3 = mesh.AddVertex(20,  0, 10);
  Vertex v4 = mesh.AddVertex(10,  0, 10);

  Edge e1 = mesh.AddEdge(v1, v2);
  Edge e2 = mesh.AddEdge(v2, v3);
  Edge e3 = mesh.AddEdge(v3, v1);
  Edge e4 = mesh.AddEdge(v3, v4);
  Edge e5 = mesh.AddEdge(v4, v1);

  mesh.AddFace(e2, e3, e1);
  mesh.AddFace(e3, e4, e5);
  }

  std::cout << "VertexList: " << mesh.NumVertices() << std::endl;
  std::cout << "EdgeList: " << mesh.NumEdges() << std::endl;
  std::cout << "FaceList: " << mesh.NumFaces() << std::endl;

  {
  /* top face */
  Vertex v1 = mesh.AddVertex(10, 10, 10);
  Vertex v2 = mesh.AddVertex(20, 10, 10);
  Vertex v3 = mesh.AddVertex(20, 10, 0);
  Vertex v4 = mesh.AddVertex(10, 10, 0);

  Edge e1 = mesh.AddEdge(v1, v2);
  Edge e2 = mesh.AddEdge(v2, v3);
  Edge e3 = mesh.AddEdge(v3, v1);
  Edge e4 = mesh.AddEdge(v3, v4);
  Edge e5 = mesh.AddEdge(v4, v1);

  mesh.AddFace(e1, e2, e3);
  mesh.AddFace(e3, e4, e5);
  }

  std::cout << "VertexList: " << mesh.NumVertices() << std::endl;
  std::cout << "EdgeList: " << mesh.NumEdges() << std::endl;
  std::cout << "FaceList: " << mesh.NumFaces() << std::endl;

  {
  /* back face */
  Vertex v1 = mesh.AddVertex(10, 10, 0);
  Vertex v2 = mesh.AddVertex(20, 10, 0);
  Vertex v3 = mesh.AddVertex(20, 0,  0);
  Vertex v4 = mesh.AddVertex(10, 0,  0);

  Edge e1 = mesh.AddEdge(v1, v2);
  Edge e2 = mesh.AddEdge(v2, v3);
  Edge e3 = mesh.AddEdge(v3, v1);
  Edge e4 = mesh.AddEdge(v3, v4);
  Edge e5 = mesh.AddEdge(v4, v1);

  mesh.AddFace(e1, e2, e3);
  mesh.AddFace(e3, e4, e5);
  }

  std::cout << "VertexList: " << mesh.NumVertices() << std::endl;
  std::cout << "EdgeList: " << mesh.NumEdges() << std::endl;
  std::cout << "FaceList: " << mesh.NumFaces() << std::endl;

  /* bottom face */
  {
  Vertex v1 = mesh.AddVertex(10, 0, 10);
  Vertex v2 = mesh.AddVertex(20, 0, 10);
  Vertex v3 = mesh.AddVertex(20, 0,  0);
  Vertex v4 = mesh.AddVertex(10, 0,  0);

  Edge e1 = mesh.AddEdge(v1, v2);
  Edge e2 = mesh.AddEdge(v2, v3);
  Edge e3 = mesh.AddEdge(v3, v1);
  Edge e4 = mesh.AddEdge(v3, v4);
  Edge e5 = mesh.AddEdge(v4, v1);

  mesh.AddFace(e1, e2, e3);
  mesh.AddFace(e3, e4, e5);
  }

  std::cout << "VertexList: " << mesh.NumVertices() << std::endl;
  std::cout << "EdgeList: " << mesh.NumEdges() << std::endl;
  std::cout << "FaceList: " << mesh.NumFaces() << std::endl;

  /* left face */
  {
  Vertex v1 = mesh.AddVertex(10, 10, 0);
  Vertex v2 = mesh.AddVertex(10, 10, 10);
  Vertex v3 = mesh.AddVertex(10, 0,  10);
  Vertex v4 = mesh.AddVertex(10, 0,  0);

  Edge e1 = mesh.AddEdge(v1, v2);
  Edge e2 = mesh.AddEdge(v2, v3);
  Edge e3 = mesh.AddEdge(v3, v1);
  Edge e4 = mesh.AddEdge(v3, v4);
  Edge e5 = mesh.AddEdge(v4, v1);

  mesh.AddFace(e1, e2, e3);
  mesh.AddFace(e3, e4, e5);
  }

  std::cout << "VertexList: " << mesh.NumVertices() << std::endl;
  std::cout << "EdgeList: " << mesh.NumEdges() << std::endl;
  std::cout << "FaceList: " << mesh.NumFaces() << std::endl;

  /* right face */
  {
  Vertex v1 = mesh.AddVertex(20, 10, 0);
  Vertex v2 = mesh.AddVertex(20, 10, 10);
  Vertex v3 = mesh.AddVertex(20, 0,  10);
  Vertex v4 = mesh.AddVertex(20, 0,  0);

  Edge e1 = mesh.AddEdge(v1, v2);
  Edge e2 = mesh.AddEdge(v2, v3);
  Edge e3 = mesh.AddEdge(v3, v1);
  Edge e4 = mesh.AddEdge(v3, v4);
  Edge e5 = mesh.AddEdge(v4, v1);

  mesh.AddFace(e1, e2, e3);
  mesh.AddFace(e3, e4, e5);
  }

  std::cout << "VertexList: " << mesh.NumVertices() << std::endl;
  std::cout << "EdgeList: " << mesh.NumEdges() << std::endl;
  std::cout << "FaceList: " << mesh.NumFaces() << std::endl;

  Subdivide();
  
}

void Cube::Draw()
{
  mesh.Draw();  
}

void Cube::Subdivide()
{
  mesh = mesh.Subdivide();
}

/* end */
}
