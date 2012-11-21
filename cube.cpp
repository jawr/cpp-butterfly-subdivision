#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "cube.hpp"

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
 
    Face f1;
    f1.AddEdge(new Edge(v1, v2));
    f1.AddEdge(new Edge(v2, v3));
    f1.AddEdge(new Edge(v3, v1));
    faces->push_back(f1);

    Face f2;
    f2.AddEdge(new Edge(v1, v3));
    f2.AddEdge(new Edge(v3, v4));
    f2.AddEdge(new Edge(v4, v1));
    faces->push_back(f2);
  }

  // back face
  {
    VertexPtr v1(new Vertex(10, 10, 0));
    VertexPtr v2(new Vertex(20, 10, 0));
    VertexPtr v3(new Vertex(20, 0,  0));
    VertexPtr v4(new Vertex(10, 0,  0));
 
    Face f1;
    f1.AddEdge(new Edge(v1, v2));
    f1.AddEdge(new Edge(v2, v3));
    f1.AddEdge(new Edge(v3, v1));
    faces->push_back(f1);

    Face f2;
    f2.AddEdge(new Edge(v1, v3));
    f2.AddEdge(new Edge(v3, v4));
    f2.AddEdge(new Edge(v4, v1));
    faces->push_back(f2);
  }

  // top face
  {
    VertexPtr v1(new Vertex(10, 10, 10));
    VertexPtr v2(new Vertex(20, 10, 10));
    VertexPtr v3(new Vertex(20, 10, 0));
    VertexPtr v4(new Vertex(10, 10, 0));
 
    Face f1;
    f1.AddEdge(new Edge(v1, v2));
    f1.AddEdge(new Edge(v2, v3));
    f1.AddEdge(new Edge(v3, v1));
    faces->push_back(f1);

    Face f2;
    f2.AddEdge(new Edge(v1, v3));
    f2.AddEdge(new Edge(v3, v4));
    f2.AddEdge(new Edge(v4, v1));
    faces->push_back(f2);
  }

  // bottom face
  {
    VertexPtr v1(new Vertex(10, 0, 10));
    VertexPtr v2(new Vertex(20, 0, 10));
    VertexPtr v3(new Vertex(20, 0,  0));
    VertexPtr v4(new Vertex(10, 0,  0));
 
    Face f1;
    f1.AddEdge(new Edge(v1, v2));
    f1.AddEdge(new Edge(v2, v3));
    f1.AddEdge(new Edge(v3, v1));
    faces->push_back(f1);

    Face f2;
    f2.AddEdge(new Edge(v1, v3));
    f2.AddEdge(new Edge(v3, v4));
    f2.AddEdge(new Edge(v4, v1));
    faces->push_back(f2);
  }

  // left face
  {
    VertexPtr v1(new Vertex(10, 10, 0));
    VertexPtr v2(new Vertex(10, 10, 10));
    VertexPtr v3(new Vertex(10, 0,  10));
    VertexPtr v4(new Vertex(10, 0,  0));
 
    Face f1;
    f1.AddEdge(new Edge(v1, v2));
    f1.AddEdge(new Edge(v2, v3));
    f1.AddEdge(new Edge(v3, v1));
    faces->push_back(f1);

    Face f2;
    f2.AddEdge(new Edge(v1, v3));
    f2.AddEdge(new Edge(v3, v4));
    f2.AddEdge(new Edge(v4, v1));
    faces->push_back(f2);
  }

  // right face
  {
    VertexPtr v1(new Vertex(20, 10, 0));
    VertexPtr v2(new Vertex(20, 10, 10));
    VertexPtr v3(new Vertex(20, 0,  10));
    VertexPtr v4(new Vertex(20, 0,  0));
 
    Face f1;
    f1.AddEdge(new Edge(v1, v2));
    f1.AddEdge(new Edge(v2, v3));
    f1.AddEdge(new Edge(v3, v1));
    faces->push_back(f1);

    Face f2;
    f2.AddEdge(new Edge(v1, v3));
    f2.AddEdge(new Edge(v3, v4));
    f2.AddEdge(new Edge(v4, v1));
    faces->push_back(f2);
  }
}

void Cube::Draw()
{
  using namespace utils;
  std::vector<Face>::const_iterator it;
  for (it = faces->begin(); it != faces->end(); ++it)
  {
    std::vector<Edge*>::const_iterator jt;
    for (jt = (*it).CBegin(); jt != (*it).CEnd(); ++jt)
    {
      // draw edge
      (*jt)->Draw();
    }
  }
}

// could probably refactor the above and below into one function where we loop
// over faces/edges and supply a function to do on each.. be more functional

void Cube::Subdivide()
{
  using namespace utils;  

  FacesPtr newFaces(new Faces);
  Faces::const_iterator it;

  for (it = faces->begin(); it != faces->end(); ++it)
  {
    std::vector<Edge*>::const_iterator jt = (*it).CBegin();
    
    // get v1 & v2 of face
    VertexPtr v1 = (*jt)->P1();
    VertexPtr v4 = (*jt)->Midpoint();
    ++jt;
    VertexPtr v2 = (*jt)->P1();
    VertexPtr v5 = (*jt)->Midpoint();
    ++jt;
    VertexPtr v3 = (*jt)->P1();
    VertexPtr v6 = (*jt)->Midpoint();

    // let's create our new faces
    {
      utils::Face newFace;
      newFace.AddEdge(new Edge(v1, v4));
      newFace.AddEdge(new Edge(v4, v6));
      newFace.AddEdge(new Edge(v6, v1));
      newFaces->push_back(newFace);
    }

    {
      utils::Face newFace;
      newFace.AddEdge(new Edge(v4, v2));
      newFace.AddEdge(new Edge(v2, v5));
      newFace.AddEdge(new Edge(v5, v4));
      newFaces->push_back(newFace);
    }

    {
      utils::Face newFace;
      newFace.AddEdge(new Edge(v5, v3));
      newFace.AddEdge(new Edge(v3, v6));
      newFace.AddEdge(new Edge(v6, v5));
      newFaces->push_back(newFace);
    }

    // middle face
    {
      utils::Face newFace;
      newFace.AddEdge(new Edge(v4, v5));
      newFace.AddEdge(new Edge(v5, v6));
      newFace.AddEdge(new Edge(v6, v4));
      newFaces->push_back(newFace);
    }
  } 
  // switcharoo 
  faces.swap(newFaces);
}

}

