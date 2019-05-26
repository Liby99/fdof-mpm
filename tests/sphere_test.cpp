#include <fdof/fdof.h>
#include <objects/Sphere.h>

using namespace fdof;
using namespace mpm;

int main() {

  PathTracer pt;
  pt.setSuperSampling(512);

  Scene scn;
  scn.background = Color(0.7, 0.8, 0.9);
  scn.getCamera().setPosition(vec3(-3, 1, 5));
  scn.getCamera().setFocalDistance(6);
  scn.getCamera().setAperture(0.1);

  DirectLight dl;
  dl.color = Color(0.8, 0.8, 0.8);
  scn.addLight(dl);

  Lambert lbt(Color(0.3, 0.3, 0.4));

  Sphere sphere;
  sphere.setMaterial(lbt);
  scn.addObject(sphere);

  Cube flr(5, 0.01, 5);
  flr.transform.setPosition(vec3(0, -0.5, 0));
  flr.setMaterial(lbt);
  scn.addObject(flr);

  Image img(640, 480);
  pt.render(scn, img);
  img.save("basictest.bmp");

  system("open basictest.bmp");
}
