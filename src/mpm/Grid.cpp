#include "Grid.h"

using namespace mpm;

Grid::Grid(const vec3 &center, const vec3 &size, const vec3 &resolution)
  : center(center), size(size), resolution(resolution) {

  // Initialize the resolutionn
  xres = resolution.x, yres = resolution.y, zres = resolution.z;
  totalCellAmount = xres * yres * zres;

  // Other parameters
  dx = size.x / xres, dy = size.y / yres, dz = size.z / zres;

  // Initialize the cells grid
  cells = new Cell[totalCellAmount];
}

Grid::~Grid() {
  delete[] cells;
}

void Grid::addParticle(const Particle &particle) {
  particles.push_back(particle);
}

void Grid::step() {

  // 1. Clear all cells
  resetCells();

  // 2. Particle to Grid (P2G)
  p2g();

  // 3. Update grid values (velocity)
  updateGrid();
}

void Grid::resetCells() {
  for (int i = 0; i < totalCellAmount; i++) {
    cells[i].reset();
  }
}

void Grid::p2g() {
  for (Particle &p : particles) {
    auto [x, y, z] = getCellIndex(p);
  }
}

void Grid::updateGrid() {
  for (int i = 0; i < totalCellAmount; i++) {
    // TODO
  }
}

void Grid::g2p() {
  for (Particle &p : particles) {
    // 4.1: update particle's deformation gradient using MLS-MPM's velocity gradient estimate
    // Reference: MLS-MPM paper, Eq. 17

    // 4.2: calculate neighbouring cell weights as in step 2.1.
    // note: our particle's haven't moved on the grid at all by this point, so the weights will be identical

    // 4.3: calculate our new particle velocities
    for (int i = 0; i < totalCellAmount; i++) {
      // 4.3.1:
      // get this cell's weighted contribution to our particle's new velocity
    }

    // 4.4: advect particle positions by their velocity
  }
}

Grid::Index Grid::getCellIndex(const Particle &p) const {
  return std::make_tuple(0, 0, 0);
}