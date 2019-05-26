#ifndef MPM_CELL_H
#define MPM_CELL_H

#include <fdof/fdof.h>

#include "Math.h"

using namespace fdof;

namespace mpm {
  class Cell {
  public:
    Vector3f velocity;
    float mass;

    void reset();
  };
}

#endif