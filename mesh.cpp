#include <iostream>
#include "mesh.hpp"

namespace gfx
{

Vertex WingedEdge::AddVertex(GLfloat x, GLfloat y, GLfloat z)
{
  Vertex v(x, y, z);
  return v;
}

Edge WingedEdge::AddEdge(const Vertex& v1, const Vertex& v2)
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

Face WingedEdge::AddFace(const Edge& e1, const Edge& e2, const Edge& e3)
{
  Face f(e1, e2, e3);

  faceList[f].insert(e1);
  faceList[f].insert(e2);
  faceList[f].insert(e3);

  edgeListMap[e1].faces.insert(f);
  edgeListMap[e2].faces.insert(f);
  edgeListMap[e3].faces.insert(f);

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
  std::cout << "FaceList: " << faceList.size() << std::endl;
  std::cout << "EdgeList: " << edgeListMap.size() << std::endl;
  std::cout << "VertexList: " << vertexList.size() << std::endl;
  EdgeListMap::const_iterator it;
  int i = 1;
  for (it = edgeListMap.begin(); it != edgeListMap.end(); ++it)
  {
    std::cout << i++ << std::endl;
    std::cout << it->first << std::endl;
    it->first.Draw();
  }
}

}
