#ifndef MPM_CELL_H
#define MPM_CELL_H

#include <fdof/fdof.h>

#include "Math.h"
#include "Particle.h"

using namespace fdof;

namespace mpm {
  class Cell {
  public:
    Vector3f momentum;
    Vector3f velocity;
    float mass;

    std::vector<Particle *> particles;

    void reset();
  };
}

#endif