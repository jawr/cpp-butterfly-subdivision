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
  Edge e4 = mesh.AddEdge(v1, v3);
  Edge e5 = mesh.AddEdge(v3, v4);
  Edge e6 = mesh.AddEdge(v4, v1);

  Face f1 = mesh.AddFace(e1, e2, e3);
  Face f2 = mesh.AddFace(e1, e4, e3);
  }
}

void Cube::Draw()
{
  mesh.Draw();  
}

void Cube::Subdivide()
{
}

/* end */
}
