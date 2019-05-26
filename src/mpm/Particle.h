#ifndef MPM_PARTICLE_H
#define MPM_PARTICLE_H

#include <fdof/fdof.h>

#include "Math.h"

using namespace fdof;

namespace mpm {
  class Particle {
  public:
    Vector3f position, velocity;
    float mass;
  };
}

#endif