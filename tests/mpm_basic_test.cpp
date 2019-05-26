#include <fdof/fdof.h>
#include <mpm/Grid.h>

using namespace mpm;

int main() {
  Grid grid(vec3(1, 1, 1), vec3(2, 2, 2), vec3(100, 100, 100));
  grid.addParticle(Particle{vec3(1, 1, 1), vec3(0, 0, 0), 1.0f});

  std::cout << "Particle amount: " << grid.particles.size() << std::endl;

  grid.step();

  std::cout << "Cell amount: " << grid.totalCellAmount << std::endl;
}