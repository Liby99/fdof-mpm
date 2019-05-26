#ifndef MPM_CELL_H
#define MPM_CELL_H

#include <fdof/fdof.h>

using namespace fdof;

namespace mpm {
  class Cell {
  public:
    vec3 velocity;
    float mass;

    void reset();
  };
}

#endif