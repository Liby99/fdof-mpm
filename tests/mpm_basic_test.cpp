#include <fdof/fdof.h>
#include <mpm/Grid.h>

using namespace mpm;

int main() {
  Grid grid(Vector3f(0, 0, 0), Vector3f(2, 2, 2), Vector3u(100, 100, 100));
  grid.addParticle(Particle());

  std::cout << "Particle amount: " << grid.particles.size() << std::endl;

  grid.step();

  std::cout << "Cell amount: " << grid.totalCellAmount << std::endl;
}