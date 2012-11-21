#ifdef __APPLE__
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#endif
#include "classes.hpp"

namespace utils
{

void Edge::Draw() const
{
  glBegin(GL_LINES);
  glVertex3f(p1->X(), p1->Y(), p1->Z());
  glVertex3f(p2->X(), p2->Y(), p2->Z());
  glEnd();
}

Vertex* Edge::Midpoint()
{
  GLfloat x = p1->X() + p2->X();
  GLfloat y = p1->Y() + p2->Y();
  GLfloat z = p1->Z() + p2->Z();
  return new Vertex(x/2.0, y/2.0, z/2.0);
}

}
