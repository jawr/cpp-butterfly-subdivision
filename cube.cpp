#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "cube.hpp"

namespace shapes
{

Cube::Cube()
{
  using namespace utils;

 
  // front face
  {
    Vertex* v1 = new Vertex(10, 10, 10);
    Vertex* v2 = new Vertex(20, 10, 10);
    Vertex* v3 = new Vertex(20, 0,  10);
    Vertex* v4 = new Vertex(10, 0,  10);
 
    Face f1;
    f1.AddEdge(new Edge(v1, v2));
    f1.AddEdge(new Edge(v2, v3));
    f1.AddEdge(new Edge(v3, v1));
    faces.push_back(f1);

    Face f2;
    f2.AddEdge(new Edge(v1, v3));
    f2.AddEdge(new Edge(v3, v4));
    f2.AddEdge(new Edge(v4, v1));
    faces.push_back(f2);
  }

  // back face
  {
    Vertex* v1 = new Vertex(10, 10, 0);
    Vertex* v2 = new Vertex(20, 10, 0);
    Vertex* v3 = new Vertex(20, 0,  0);
    Vertex* v4 = new Vertex(10, 0,  0);
 
    Face f1;
    f1.AddEdge(new Edge(v1, v2));
    f1.AddEdge(new Edge(v2, v3));
    f1.AddEdge(new Edge(v3, v1));
    faces.push_back(f1);

    Face f2;
    f2.AddEdge(new Edge(v1, v3));
    f2.AddEdge(new Edge(v3, v4));
    f2.AddEdge(new Edge(v4, v1));
    faces.push_back(f2);
  }

  // top face
  {
    Vertex* v1 = new Vertex(10, 10, 10);
    Vertex* v2 = new Vertex(20, 10, 10);
    Vertex* v3 = new Vertex(20, 10, 0);
    Vertex* v4 = new Vertex(10, 10, 0);
 
    Face f1;
    f1.AddEdge(new Edge(v1, v2));
    f1.AddEdge(new Edge(v2, v3));
    f1.AddEdge(new Edge(v3, v1));
    faces.push_back(f1);

    Face f2;
    f2.AddEdge(new Edge(v1, v3));
    f2.AddEdge(new Edge(v3, v4));
    f2.AddEdge(new Edge(v4, v1));
    faces.push_back(f2);
  }

  // bottom face
  {
    Vertex* v1 = new Vertex(10, 0, 10);
    Vertex* v2 = new Vertex(20, 0, 10);
    Vertex* v3 = new Vertex(20, 0,  0);
    Vertex* v4 = new Vertex(10, 0,  0);
 
    Face f1;
    f1.AddEdge(new Edge(v1, v2));
    f1.AddEdge(new Edge(v2, v3));
    f1.AddEdge(new Edge(v3, v1));
    faces.push_back(f1);

    Face f2;
    f2.AddEdge(new Edge(v1, v3));
    f2.AddEdge(new Edge(v3, v4));
    f2.AddEdge(new Edge(v4, v1));
    faces.push_back(f2);
  }

  // left face
  {
    Vertex* v1 = new Vertex(10, 10, 0);
    Vertex* v2 = new Vertex(10, 10, 10);
    Vertex* v3 = new Vertex(10, 0,  10);
    Vertex* v4 = new Vertex(10, 0,  0);
 
    Face f1;
    f1.AddEdge(new Edge(v1, v2));
    f1.AddEdge(new Edge(v2, v3));
    f1.AddEdge(new Edge(v3, v1));
    faces.push_back(f1);

    Face f2;
    f2.AddEdge(new Edge(v1, v3));
    f2.AddEdge(new Edge(v3, v4));
    f2.AddEdge(new Edge(v4, v1));
    faces.push_back(f2);
  }

  // right face
  {
    Vertex* v1 = new Vertex(20, 10, 0);
    Vertex* v2 = new Vertex(20, 10, 10);
    Vertex* v3 = new Vertex(20, 0,  10);
    Vertex* v4 = new Vertex(20, 0,  0);
 
    Face f1;
    f1.AddEdge(new Edge(v1, v2));
    f1.AddEdge(new Edge(v2, v3));
    f1.AddEdge(new Edge(v3, v1));
    faces.push_back(f1);

    Face f2;
    f2.AddEdge(new Edge(v1, v3));
    f2.AddEdge(new Edge(v3, v4));
    f2.AddEdge(new Edge(v4, v1));
    faces.push_back(f2);
  }
}

void Cube::Draw()
{
  using namespace utils;
  std::vector<Face>::const_iterator it;
  for (it = faces.begin(); it != faces.end(); ++it)
  {
    std::vector<Edge*>::const_iterator jt;
    for (jt = (*it).CBegin(); jt != (*it).CEnd(); ++jt)
    {
      (*jt)->Draw();
    }
  }
}

}

