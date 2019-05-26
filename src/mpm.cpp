#include "mpm.h"

#include <Eigen/Dense>

using namespace mpm;

int mpm::some_func(int i) {
  Eigen::Matrix2f m;
  m << 1.0, 2.0, 3.0, 4.0;
  return i + 1;
}