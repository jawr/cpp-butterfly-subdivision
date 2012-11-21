#ifndef __SHAPES_CUBE_HPP
#define __SHAPES_CUBE_HPP

#include <vector>
#include <tr1/memory>
#ifdef __APPLE__
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#endif
#include "classes.hpp"

namespace shapes
{

class Cube
{
  std::vector<utils::Face> faces;
  std::tr1::shared_ptr<utils::Face> test;
public:
  Cube();
  void Draw();
  void Subdivide();
};

}
#endif
