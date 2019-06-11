#include "Cell.h"

using namespace mpm;

void Cell::reset() {
  momentum = Vector3f::Zero();
  velocity = Vector3f::Zero();
  mass = 0.0f;
  particles.clear();
}