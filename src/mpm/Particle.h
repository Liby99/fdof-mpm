#ifndef MPM_PARTICLE_H
#define MPM_PARTICLE_H

#include <fdof/fdof.h>

using namespace fdof;

namespace mpm {
  class Particle {
  public:
    vec3 position, velocity;
    float mass;
  };
}

#endif