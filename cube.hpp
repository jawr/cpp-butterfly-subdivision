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

typedef std::vector<utils::Face> Faces;
typedef std::tr1::shared_ptr<Faces> FacesPtr; // would prefer to be unique

class Cube
{
  //std::vector<utils::Face> faces;
  FacesPtr faces;
  std::tr1::shared_ptr<utils::Face> test;
public:
  Cube();
  void Draw();
  void Subdivide();
  void ButterflySubdivide();
  utils::Face& GetAdjacentFace(utils::EdgePtr& e);
  utils::Face& BuildFace(utils::Face& face, utils::EdgePtr& edge);
};

}
#endif
