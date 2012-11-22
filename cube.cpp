#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "cube.hpp"
#include "error.hpp"

namespace shapes
{

Cube::Cube() : faces(new Faces)
{
  using namespace utils;

  // front face
  {
    VertexPtr v1(new Vertex(10, 10, 10));
    VertexPtr v2(new Vertex(20, 10, 10));
    VertexPtr v3(new Vertex(20, 0,  10));
    VertexPtr v4(new Vertex(10, 0,  10));
 
    faces->push_back(Face(v1, v2, v3));
    faces->push_back(Face(v1, v3, v4));
  }

  // back face
  {
    VertexPtr v1(new Vertex(10, 10, 0));
    VertexPtr v2(new Vertex(20, 10, 0));
    VertexPtr v3(new Vertex(20, 0,  0));
    VertexPtr v4(new Vertex(10, 0,  0));
 
    faces->push_back(Face(v1, v2, v3));
    faces->push_back(Face(v1, v3, v4));
  }

  // top face
  {
    VertexPtr v1(new Vertex(10, 10, 10));
    VertexPtr v2(new Vertex(20, 10, 10));
    VertexPtr v3(new Vertex(20, 10, 0));
    VertexPtr v4(new Vertex(10, 10, 0));
 
    faces->push_back(Face(v1, v2, v3));
    faces->push_back(Face(v1, v3, v4));
  }

  // bottom face
  {
    VertexPtr v1(new Vertex(10, 0, 10));
    VertexPtr v2(new Vertex(20, 0, 10));
    VertexPtr v3(new Vertex(20, 0,  0));
    VertexPtr v4(new Vertex(10, 0,  0));
 
    faces->push_back(Face(v1, v2, v3));
    faces->push_back(Face(v1, v3, v4));
  }

  // left face
  {
    VertexPtr v1(new Vertex(10, 10, 0));
    VertexPtr v2(new Vertex(10, 10, 10));
    VertexPtr v3(new Vertex(10, 0,  10));
    VertexPtr v4(new Vertex(10, 0,  0));
 
    faces->push_back(Face(v1, v2, v3));
    faces->push_back(Face(v1, v3, v4));
  }

  // right face
  {
    VertexPtr v1(new Vertex(20, 10, 0));
    VertexPtr v2(new Vertex(20, 10, 10));
    VertexPtr v3(new Vertex(20, 0,  10));
    VertexPtr v4(new Vertex(20, 0,  0));
 
    faces->push_back(Face(v1, v2, v3));
    faces->push_back(Face(v1, v3, v4));
  }
}

void Cube::Draw()
{
  using namespace utils;
  std::vector<Face>::iterator it;
  for (it = faces->begin(); it != faces->end(); ++it)
  {
    it->A()->Draw();
    it->B()->Draw();
    it->C()->Draw();
  }
}

/* could probably refactor the above and below into one function where we loop
   over faces/edges and supply a function to do on each.. be more functional
*/

void Cube::Subdivide()
{
  using namespace utils;  

  FacesPtr newFaces(new Faces);
  Faces::iterator it;

  for (it = faces->begin(); it != faces->end(); ++it)
  {
    EdgePtr a = it->A();
    EdgePtr b = it->B();
    EdgePtr c = it->C();

    VertexPtr v1 = a->P1();
    VertexPtr v2 = a->P2();
    VertexPtr v3 = b->P2();
    VertexPtr v4 = c->Midpoint();
    VertexPtr v5 = a->Midpoint();
    VertexPtr v6 = b->Midpoint();

    newFaces->push_back(Face(v1, v5, v4));
    newFaces->push_back(Face(v5, v2, v6));
    newFaces->push_back(Face(v4, v6, v3));
    newFaces->push_back(Face(v4, v5, v6));
  } 
  // switcharoo 
  faces.swap(newFaces);
}

void Cube::ButterflySubdivide()
{
  using namespace utils;  

  FacesPtr newFaces(new Faces);
  Faces::iterator it;

  for (it = faces->begin(); it != faces->end(); ++it)
  {
    EdgePtr a = it->A();
    EdgePtr b = it->B();
    EdgePtr c = it->C();

    Face& adj = GetAdjacentFace(e);

    newFaces->push_back(BuildFace(*it, a));
    newFaces->push_back(BuildFace(*it, b));
    newFaces->push_back(BuildFace(*it, c));
  } 
  // switcharoo 
  faces.swap(newFaces);
}

utils::Face& Cube::BuildFace(utils::Face& face, utils::EdgePtr& edge)
{
  using namespace utils;

  VertexPtr a1 = b->P1();
  VertexPtr a2 = a->P2();

  VertexPtr b1 = a->P1();
  VertexPtr b2 = adj.A()->P1();


  VertexPtr v1 = a->Midpoint();
  VertexPtr v2(new Vertex(
    (b1->X()/8.0)+(b2->X()/8.0),
    (b1->Y()/8.0)+(b2->Y()/8.0),
    (b1->Z()/8.0)+(b2->Z()/8.0)));
}

utils::Face& Cube::GetAdjacentFace(utils::EdgePtr& e)
{
  using namespace utils;
  Faces::iterator it;
  for (it = faces->begin(); it != faces->end(); ++it)
  {
    EdgePtr a = it->A();
    EdgePtr b = it->B();
    EdgePtr c = it->C();

    if (e == a || e == b || e == c) return *it;
  }
  throw RuntimeError("No edge found!");
}

}

