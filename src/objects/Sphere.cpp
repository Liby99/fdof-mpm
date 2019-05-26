#include "Sphere.h"

using namespace mpm;

Sphere::Sphere() : Sphere(vec3(0, 0, 0), 1) {}

Sphere::Sphere(vec3 center, float radius) : center(center), radius(radius) {}

void Sphere::getBoundingVertices(std::vector<vec3> & bvs) {
  bvs.push_back(center + vec3(-radius, -radius, -radius));
  bvs.push_back(center + vec3(-radius, -radius, radius));
  bvs.push_back(center + vec3(-radius, radius, -radius));
  bvs.push_back(center + vec3(-radius, radius, radius));
  bvs.push_back(center + vec3(radius, -radius, -radius));
  bvs.push_back(center + vec3(radius, -radius, radius));
  bvs.push_back(center + vec3(radius, radius, -radius));
  bvs.push_back(center + vec3(radius, radius, radius));
}

bool Sphere::updateIntersect(Ray & ray, Intersection & itsct) const {

  vec3 &p0 = ray.origin;
  vec3 &p1 = ray.direction;

  float t;
  bool hit = false;
  float a = dot(p1, p1);
  float b = 2.0f * dot(p1, p0);
  float c = dot(p0, p0) - radius * radius;
  float t1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
  float t2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);

  if (t1 > 0 && t2 > 0) {
      t = std::min(t1, t2);
  }
  else if (t1 * t2 < 0) {
      t = std::max(t1, t2);
  }
  else {
      return false;
  }

  // Update the intersection
  vec3 position = ray.getPoint(t);

  // Return intersection update
  return itsct.update(t, position, position);
}
