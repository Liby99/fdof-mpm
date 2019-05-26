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

    vec3 center, size, resolution;
    unsigned int xres, yres, zres, totalCellAmount;
    float dx, dy, dz;
    vec3 minCorner, macCorner;

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

    Index getCellIndex(const Particle &p) const;
  };
}

#endif