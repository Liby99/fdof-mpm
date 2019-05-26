#include "Cell.h"

using namespace mpm;

void Cell::reset() {
  velocity = vec3(0, 0, 0);
  mass = 0.0f;
}