#include "Grid.h"

using namespace mpm;

Grid::Grid(const Vector3f &center, const Vector3f &size, const Vector3u &resolution)
  : center(center), size(size) {

  // Initialize the resolutionn
  xres = resolution(0), yres = resolution(1), zres = resolution(2);
  totalCellAmount = xres * yres * zres;

  // Other parameters
  dx = size.x() / xres, dy = size.y() / yres, dz = size.z() / zres;
  invdx = 1.0f / dx, invdy = 1.0f / dy, invdz = 1.0f / dz;
  minCorner = center - size / 2.0f, maxCorner = center + size / 2.0f;

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

  // 4. Grid to Particle (G2P)
  g2p();
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

Cell &Grid::getCell(const Grid::Index &index) {
  auto [x, y, z] = index;
  return cells[x * yres * zres + y * zres + z];
}

Grid::Index Grid::getCellIndex(const Particle &p) const {
  const Vector3f diff = p.position - minCorner;
  return std::make_tuple(
    std::floor(diff.x() * invdx),
    std::floor(diff.y() * invdy),
    std::floor(diff.z() * invdz)
  );
}

void Grid::populateCellNeighbors(const Grid::Index &index, std::vector<Grid::Index> &neighbors) {
  auto [x, y, z] = index;
  for (int i = x - 1; i <= x + 1; i++) {
    for (int j = y - 1; j <= y + 1; j++) {
      for (int k = z - 1; k <= z + 1; k++) {
        if (i >= 0 && i < xres && j >= 0 && j < yres && k >= 0 && k < zres && (i != x || j != y || k != z)) {
          neighbors.push_back(std::make_tuple(i, j, k));
        }
      }
    }
  }
}