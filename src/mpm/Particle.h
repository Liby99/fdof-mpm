#ifndef MPM_PARTICLE_H
#define MPM_PARTICLE_H

#include <fdof/fdof.h>

#include "Math.h"

using namespace fdof;

namespace mpm
{
  class Particle {
  public:
    Vector3f position, velocity;
    float mass;
    Matrix3f F; // Deformation gradient
    Matrix3f C; // Affine momentum of APIC
    float Jp; // Determinant of the deformation gradient
    Matrix3f W; // Kernel Function

    Particle(): position(Vector3f::Zero()), velocity(Vector3f::Zero()),
                mass(1.0f), F(Matrix3f::Identity()), C(Matrix3f::Zero()), Jp(1.0f), W(Matrix3f::Zero()) {
    }
  };
}

#endif
