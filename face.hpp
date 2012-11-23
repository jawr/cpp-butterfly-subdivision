#ifndef __GFX_FACE_HPP
#define __GFX_FACE_HPP

#include "edge.hpp"

namespace gfx
{

/* for ease assuming it's a triangle */
class Face
{
  Edge e1;
  Edge e2;
  Edge e3;

public:
  Face(const Edge& e1, const Edge& e2, const Edge& e3) : e1(e1), e2(e2), e3(e3) {}
  
  const Edge& E1() const { return e1; }
  const Edge& E2() const { return e2; }
  const Edge& E3() const { return e3; }

  /* used to use Edge as key in map */
  bool operator<(const Face& f) const
  {
    if (e1 < f.E1()) return true;
    else if (e2 < f.E2()) return true;
    else if (e3 < f.E3()) return true;
    return false;
  }

  bool operator==(const Face& f) const
  {
    return (e1 == f.E1() && e2 == f.E2() && e3 == f.E3());
  }

  bool operator!=(const Face& f) const
  { 
    return !(*this == f);
  }
};

/* end */
}
#endif
