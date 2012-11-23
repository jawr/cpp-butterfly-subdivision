#ifndef __GFX_MESH_HPP
#define __GFX_MESH_HPP

#ifdef __APPLE__
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#endif

#include <map>
#include <set>
#include <vector>
#include "vertex.hpp"
#include "edge.hpp"
#include "face.hpp"

namespace gfx
{

typedef std::map<Face, std::set<Edge> > FaceList;

struct EdgeList
{
  std::set<Vertex> vertices;
  std::set<Face> faces;
  std::set<Edge> edges;
};

typedef std::map<Edge, EdgeList> EdgeListMap;

typedef std::map<Vertex, std::set<Edge> > VertexList; 

/* based on wikipedia article http://en.wikipedia.org/wiki/Polygon_mesh */
class WingedEdge
{
  FaceList faceList;
  EdgeListMap edgeListMap;
  VertexList vertexList;

public:
  WingedEdge() {}

  Vertex AddVertex(GLfloat x, GLfloat y, GLfloat z);
  Edge AddEdge(Vertex& v1, Vertex& v2);
  Face AddFace(Edge& e1, Edge& e2, Edge& e3); 

  int NumVertices() const { return vertexList.size(); }
  int NumEdges() const { return edgeListMap.size(); }
  int NumFaces() const { return faceList.size(); }

  void Draw();
  
  WingedEdge Subdivide();
  Vertex SubdivideEdge(const Face& f1, Edge& e, Vertex& b1);

  const Face& GetAdjacentFace(const Face& f, Edge& e);
};

/* end */
}
#endif
