#ifndef __GFX_VERTEX_HPP
#define __GFX_VERTEX_HPP
#include <iostream>
#ifdef __APPLE__
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#endif

namespace gfx
{

class Vertex
{
  GLfloat x;
  GLfloat y;
  GLfloat z;

public:
  Vertex(GLfloat x, GLfloat y, GLfloat z) : x(x), y(y), z(z) {}

  const GLfloat X() const { return x; }
  const GLfloat Y() const { return y; }
  const GLfloat Z() const { return z; }

  /* used to use Vertex as key in a map */
  bool operator<(const Vertex& v) const
  {
    if (x < v.X()) return true;
    else if (y < v.Y()) return true;
    else if (z < v.Z()) return true;
    return false;
  }

  bool operator==(const Vertex& v) const
  {
    return (x == v.X() && y == v.Y() && z == v.Z());
  }

  bool operator!=(const Vertex& v) const
  {
    return !(x == v.X() && y == v.Y() && z == v.Z());
  }

  friend std::ostream& operator<<(std::ostream& os, const Vertex& v)
  {
    os << "X: " << v.X() << " Y: " << v.Y() << " Z: " << v.Z();
    return os;
  }
};


/* end */
}
#endif

