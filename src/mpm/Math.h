#ifndef MPM_MATH_H
#define MPM_MATH_H

#include <Eigen/Dense>

namespace mpm {
  typedef Eigen::Vector4f Vector4f;
  typedef Eigen::Vector3f Vector3f;
  typedef Eigen::Vector2f Vector2f;

  typedef Eigen::Vector4i Vector4i;
  typedef Eigen::Vector3i Vector3i;
  typedef Eigen::Vector2i Vector2i;

  typedef Eigen::Matrix<uint32_t, 4, 1> Vector4u;
  typedef Eigen::Matrix<uint32_t, 3, 1> Vector3u;
  typedef Eigen::Matrix<uint32_t, 2, 1> Vector2u;

  typedef Eigen::Matrix4f Matrix4f;
  typedef Eigen::Matrix3f Matrix3f;
  typedef Eigen::Matrix2f Matrix2f;
}

#endif