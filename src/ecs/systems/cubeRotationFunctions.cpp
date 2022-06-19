#ifndef cubeRotationFunctions_cpp
#define cubeRotationFunctions_cpp

/*----------------------------------------------------------------|
--------------------- Module Description -------------------------|
free functions to make cubes rotate, yo
-----------------------------------------------------------------*/

#include <glm/vec3.hpp> 
#include <glm/ext/quaternion_double.hpp>
#include <quaternion_funktions.cpp>
#include <ezprint.cpp>

namespace pce {
namespace cube {


std::unordered_map<Entity, glm::dvec3> getCubeRotatedVertices(
    const std::unordered_map<Entity, glm::dvec3>& vertices, const glm::dquat& rotation_versor) {
  std::unordered_map<Entity, glm::dvec3> rotated_vertices;
  for (auto const& [key, value] : vertices) {
    rotated_vertices[key] = qfunc::rotateVector3byQuaternion(value, rotation_versor);
  }
  return rotated_vertices;
}

}
}


#endif /* cubeRotationFunctions_cpp */
