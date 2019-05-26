#ifndef MPM_SPHERE_H
#define MPM_SPHERE_H

#include <fdof/fdof.h>

using namespace fdof;

namespace mpm {
  class Sphere : public Object {
  public:
    float radius;
    vec3 center;

    Sphere();
    Sphere(vec3 center, float radius);

  protected:
    virtual void getBoundingVertices(std::vector<vec3> & bvs) override;
    virtual bool updateIntersect(Ray & ray, Intersection & itsct) const override;
  };
}

#endif