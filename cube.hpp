#ifndef __SHAPES_CUBE_HPP
#define __SHAPES_CUBE_HPP

#include <vector>
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
public:
    Cube();
    void Draw();
};

}
#endif
