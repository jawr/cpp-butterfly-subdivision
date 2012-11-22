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

typedef std::tr1::shared_ptr<Edge> EdgePtr;

class Face
{
  /* simplifying a face to three edges
     using the following syntax:
     
          /\
        c/  \a
        /____\
          b
  */
  EdgePtr a; 
  EdgePtr b; 
  EdgePtr c; 
public:
  Face() {}
  Face (const EdgePtr& a, const EdgePtr& b, const EdgePtr& c) :
    a(a), b(b), c(c) {}
  Face (const VertexPtr& v1, const VertexPtr& v2, const VertexPtr& v3);
  ~Face() {} // need to do real cleanup

  void A(Edge* a) { this->a.reset(a); }
  void B(Edge* b) { this->b.reset(b); }
  void C(Edge* c) { this->c.reset(c); }

  EdgePtr& A() { return a; }
  EdgePtr& B() { return b; }
  EdgePtr& C() { return c; }
};

}

#endif
