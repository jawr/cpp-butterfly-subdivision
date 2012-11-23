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
  Edge AddEdge(const Vertex& v1, const Vertex& v2);
  Face AddFace(const Edge& e1, const Edge& e2, const Edge& e3); 

  void Draw();
};

/* end */
}
#endif
