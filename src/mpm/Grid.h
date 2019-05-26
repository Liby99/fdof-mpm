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

    vec3 center, size;
    unsigned int xres, yres, zres, totalCellAmount;
    float dx, dy, dz, invdx, invdy, invdz;
    vec3 minCorner, maxCorner;

    std::vector<Particle> particles;
    Cell *cells;

    Grid(const vec3 &center, const vec3 &size, const vec3 &resolution);
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