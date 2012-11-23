#include <assert.h>
#include <iostream>
#include "mesh.hpp"
#include "error.hpp"

namespace gfx
{

Vertex WingedEdge::AddVertex(GLfloat x, GLfloat y, GLfloat z)
{
  Vertex v(x, y, z);
  vertexList[v]; /* ensure the key exists */
  return v;
}

Edge WingedEdge::AddEdge(Vertex& v1, Vertex& v2)
{
  Edge e(v1, v2);

  /* get them in the vertexList */

  vertexList[v1].insert(e);
  vertexList[v2].insert(e);

  /* setup edge list */
  edgeListMap[e].edges.insert(e);
  edgeListMap[e].vertices.insert(v1);
  edgeListMap[e].vertices.insert(v2);

  return e;
}

Face WingedEdge::AddFace(Edge& e1, Edge& e2, Edge& e3)
{
  Face f(e1, e2, e3);

  faceList[f].insert(e1);
  faceList[f].insert(e2);
  faceList[f].insert(e3);

  std::cout << "Adding faces" << std::endl;
  std::cout << edgeListMap[e1].faces.size() << std::endl;
  std::cout << edgeListMap[e2].faces.size() << std::endl;
  std::cout << edgeListMap[e3].faces.size() << std::endl;

  edgeListMap[e1].faces.insert(f);
  edgeListMap[e2].faces.insert(f);
  edgeListMap[e3].faces.insert(f);

  std::cout << "Added faces" << std::endl;
  std::cout << edgeListMap[e1].faces.size() << std::endl;
  std::cout << edgeListMap[e2].faces.size() << std::endl;
  std::cout << edgeListMap[e3].faces.size() << std::endl;

  edgeListMap[e1].vertices.insert(e1.V1());
  edgeListMap[e1].vertices.insert(e1.V2());
  edgeListMap[e2].vertices.insert(e2.V1());
  edgeListMap[e2].vertices.insert(e2.V2());
  edgeListMap[e3].vertices.insert(e3.V1());
  edgeListMap[e3].vertices.insert(e3.V2());

  return f;
}

void WingedEdge::Draw()
{
  for (auto& edge: edgeListMap)
    edge.first.Draw();
}

WingedEdge WingedEdge::Subdivide()
{
  WingedEdge mesh;
  for (auto& face: faceList)
  {
    /* massive assumption that there is 3 edges in our face */
    Edge e1;
    Edge e2;
    Edge e3;
    {
      std::cout << face.second.size() << std::endl;
      auto it = face.second.begin();
      e1 = *it++;
      e2 = *it++;
      e3 = *it;
    }

    /* might need to verify this doesn't pick duplicates */
    Vertex v1 = e1.Smallest();
    Vertex v2 = e1.Largest();
    Vertex v3 = (e2.V1() == v1 || e2.V1() == v2) ? e2.V2() : e2.V1();

    /* guarantee we know what e2 is */
    if (v1 == e3.V1() || v1 == e3.V2()) 
    {
      Edge tmp = e3;
      e3 = e2;
      e2 = tmp;
    }

    Vertex v4 = SubdivideEdge(face.first, e1, v3);
    Vertex v5 = SubdivideEdge(face.first, e2, v2);
    Vertex v6 = SubdivideEdge(face.first, e3, v1);

    {
    e1 = mesh.AddEdge(v1, v4);
    e2 = mesh.AddEdge(v1, v5);
    e3 = mesh.AddEdge(v5, v4);
    mesh.AddFace(e1, e2, e3);
    }

    {
    e1 = mesh.AddEdge(v4, v2);
    e2 = mesh.AddEdge(v4, v6);
    e3 = mesh.AddEdge(v6, v2);
    mesh.AddFace(e1, e2, e3);
    }

    {
    e1 = mesh.AddEdge(v5, v6);
    e2 = mesh.AddEdge(v5, v3);
    e3 = mesh.AddEdge(v3, v6);
    mesh.AddFace(e1, e2, e3);
    }

    {
    e1 = mesh.AddEdge(v6, v5);
    e2 = mesh.AddEdge(v6, v4);
    e3 = mesh.AddEdge(v4, v5);
    mesh.AddFace(e1, e2, e3);
    }


  }
  std::cout << "VertexList: " << mesh.NumVertices() << std::endl;
  std::cout << "EdgeList: " << mesh.NumEdges() << std::endl;
  std::cout << "FaceList: " << mesh.NumFaces() << std::endl;
  
  return mesh;
}

Vertex WingedEdge::SubdivideEdge(const Face& f1, Edge& e, Vertex& b1)
{
  /* divide by 2 (a) */
  Vertex v = e.Midpoint();

  try
  {  
    const Face& f2 = GetAdjacentFace(f1, e); 

    Vertex b2;
    if (f2.E1() != e)
      b2 = (f2.E1().V1() == e.V1()) ? f2.E1().V2() : f2.E1().V1();
    else if (f2.E2() != e)
      b2 = (f2.E2().V1() == e.V1()) ? f2.E2().V2() : f2.E2().V1();
    else if (f2.E3() != e)
      b2 = (f2.E3().V1() == e.V1()) ? f2.E3().V2() : f2.E3().V1();

    std::cout << "a1: " << e.V1() << std::endl;
    std::cout << "a2: " << e.V2() << std::endl;
    std::cout << "b1: " << b1 << std::endl;
    std::cout << "b2: " << b2 << std::endl;

    b1 = b1 / 8.0;
    b1 = b1 + 2.0;

    b2 = b2 / 8.0;
    b2 = b2 + 2.0;

    Edge bEdge(b1, b2);

    return bEdge.Midpoint();
  }
  catch (const RuntimeError& e)
  {
    std::cout << "Couldn't fit b to template." << std::endl;
  }
  
  return v;
}

const Face& WingedEdge::GetAdjacentFace(const Face& f, Edge& e)
{
  EdgeList edgeList = edgeListMap[e];
  std::set<Face>::const_iterator it;
  std::cout << "edge faces: " << edgeList.faces.size() << std::endl;
  for (it = edgeList.faces.begin(); it != edgeList.faces.end(); ++it)
    if (*it != f) return *it;
  std::cout << "Didn't find a face." << std::endl;
  throw RuntimeError("Error getting adjacent face.");
}

/* end */
}
