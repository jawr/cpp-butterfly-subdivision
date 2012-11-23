#ifndef __GFX_EDGE_HPP
#define __GFX_EDGE_HPP
#ifdef __APPLE__
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#endif

namespace gfx
{

class Edge
{
  Vertex v1;
  Vertex v2;

public:
  Edge(const Vertex& v1, const Vertex& v2) : v1(v1), v2(v2) {}

  const Vertex& V1() const { return v1; }
  const Vertex& V2() const { return v2; }

  void Draw() const
  {
    glBegin(GL_LINES);
    glVertex3f(v1.X(), v1.Y(), v1.Z());
    glVertex3f(v2.X(), v2.Y(), v2.Z());
    glEnd();
  }


  /* used to use Edge as key in map */
  bool operator<(const Edge& e) const
  {
    if (v1 < e.V1()) return true;
    else if (v2 < e.V2()) return true;
    return false;
  }

  bool operator==(const Edge& e) const
  {
    return (v1 == e.V1() && v2 == e.V2());
  }

  bool operator!=(const Edge& e) const
  {
    return !(*this == e);
  }

  Edge& operator=(const Edge& e)
  {
    if (*this == e) return *this;

    v1 = e.v1;
    v2 = e.v2;

    return *this;
  }

  friend std::ostream& operator<<(std::ostream& os, const Edge& v)
  {
    os << "Edge:\n" << v.V1() << " :: " << v.V2();
    return os;
  }
  
};

/* end */
}
#endif
