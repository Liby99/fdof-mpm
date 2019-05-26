#ifndef MPM_GRID_H
#define MPM_GRID_H

#include <tuple>

#include <fdof/fdof.h>
#include "Cell.h"
#include "Particle.h"

using namespace fdof;

namespace mpm {
  class Grid {
  public:
    typedef std::tuple<int, int, int> Index;

    Vector3f center, size;
    Vector3f minCorner, maxCorner;
    unsigned int xres, yres, zres, totalCellAmount;
    float dx, dy, dz, invdx, invdy, invdz;

    std::vector<Particle> particles;
    Cell *cells;

    Grid(const Vector3f &center, const Vector3f &size, const Vector3u &resolution);
    ~Grid();

    void addParticle(const Particle &particle);

    void step();

  private:
    void resetCells();
    void p2g();
    void updateGrid();
    void g2p();

    Cell &getCell(const Grid::Index &index);
    Index getCellIndex(const Particle &p) const;
    void populateCellNeighbors(const Index &index, std::vector<Index> &neighbors);
  };
}

#endif