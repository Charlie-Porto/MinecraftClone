#ifndef CubeMovementSystem_cpp
#define CubeMovementSystem_cpp

/*----------------------------------------------------------------|
--------------------- Module Description -------------------------|
system to move cubes
-----------------------------------------------------------------*/

#include <ezprint.cpp>
#include <glm/vec3.hpp>
#include <glm/ext/quaternion_double.hpp>
#include <quaternion_funktions.cpp>

#include "../System.cpp"

extern ControlPanel control;

namespace pce{
class CubeMovementSystem : public ISystem {
public:

void SetRotationVersor() {
  incremental_rotation_versor_ = qfunc::convertAngleAxisToQuaternion(2.0, glm::dvec3(-.5, -.4, .6));
}


void RotateCubes() {
  ezp::print_item("Rotating Cubes");
  for (auto const& entity : entities) {
    ezp::print_labeled_item("rotating entity: ", entity);
    auto& cube = control.GetComponent<pce::Cube>(entity);
    for (auto const& [key, value] : cube.current_vertices) {
      ezp::print_labeled_item("rotating vertex: ", key);
      ezp::print_item("before");
      vezp::print_dvec3(cube.current_vertices.at(key));
      cube.current_vertices.at(key) = qfunc::rotateVector3byQuaternion(
                                  cube.current_vertices.at(key), incremental_rotation_versor_);
      ezp::print_item("after");
      vezp::print_dvec3(cube.current_vertices.at(key));
    }
  }
}

private:
  glm::dquat incremental_rotation_versor_;
  

};
}
#endif /* CubeMovementSystem_cpp */
