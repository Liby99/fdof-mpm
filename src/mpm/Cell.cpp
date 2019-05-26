#include "Cell.h"

using namespace mpm;

void Cell::reset() {
  velocity = Vector3f::Zero();
  mass = 0.0f;
}