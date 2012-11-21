#ifndef __UTIL_CLASSES_HPP
#define __UTIL_CLASSES_HPP

#include <iostream>
#include <tr1/memory>
#include <vector>

namespace utils
{

class Vertex;

typedef std::tr1::shared_ptr<Vertex> VertexPtr;

class Vertex
{
  GLfloat x;
  GLfloat y;
  GLfloat z;
  int valences; // controlled in the edge
public:
  Vertex(GLfloat x, GLfloat y, GLfloat z) : x(x), y(y), z(z), valences(0) {}

  const GLfloat& X() const { return x; }
  const GLfloat& Y() const { return y; }
  const GLfloat& Z() const { return z; }

  // valence control, prefer prefix overload
  // needs boundary check?
  Vertex& operator++() 
  { 
    ++valences; 
    return *this;
  }
  Vertex& operator--() 
  { 
    --valences; 
    return *this;
  } 
};

class Edge
{
  VertexPtr p1; // would want to use a shared_ptr here
  VertexPtr p2;
public:
  Edge(VertexPtr p1, VertexPtr p2) : p1(p1), p2(p2) 
  {
    // control vertex's valences, have to use our initalized copies
    ++(*p1);
    ++(*p2);
  }
  ~Edge() 
  {
    // control vertex's valences
    --(*p1);
    --(*p2);
  }

  void Draw() const;

  VertexPtr P1() { return p1; }
  VertexPtr P2() { return p2; }

  VertexPtr Midpoint();
  
};

class Face
{
  // don't think it's possible to store ptr containers in stl
  std::vector<Edge*> edges;
public:
  Face() {}
  ~Face() {} // need to do real cleanup

  void AddEdge(Edge* edge) { edges.push_back(edge); }
  int Size() const { return edges.size(); }

  std::vector<Edge*>::const_iterator CBegin() const { return edges.begin(); }
  std::vector<Edge*>::const_iterator CEnd() const { return edges.end(); }
};

}

#endif
