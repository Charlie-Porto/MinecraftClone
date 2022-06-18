#ifndef cubeFactoryFunctions_cpp
#define cubeFactoryFunctions_cpp

/*----------------------------------------------------------------|
--------------------- Module Description -------------------------|
free functions to assist the cube factor class
-----------------------------------------------------------------*/
#include <vector>

#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <ezprint.cpp>

namespace pce {
namespace cube {

std::vector<glm::dvec3> getCubeVertexLocations(const glm::dvec3& center, const double side_length) {
  const double half_side_length = side_length/2.0; 
  const double y_above = center.y + half_side_length;
  const double y_below = center.y - half_side_length;
  const double x_left = center.x + half_side_length;
  const double x_right = center.x - half_side_length;
  const double z_left = center.z + half_side_length;
  const double z_right = center.z - half_side_length;

  return {
    glm::dvec3(x_left, z_left, y_above),
    glm::dvec3(x_left, z_left, y_below),
    glm::dvec3(x_right, z_left, y_above),
    glm::dvec3(x_right, z_left, y_below),
    glm::dvec3(x_left, z_right, y_above),
    glm::dvec3(x_left, z_right, y_below),
    glm::dvec3(x_right, z_right, y_above),
    glm::dvec3(x_right, z_right, y_below)
  };
}


}
}


#endif /* cubeFactoryFunctions_cpp */
