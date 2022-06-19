#ifndef cubeFactoryFunctions_cpp
#define cubeFactoryFunctions_cpp

/*----------------------------------------------------------------|
--------------------- Module Description -------------------------|
free functions to assist the cube factor class
-----------------------------------------------------------------*/
#include <unordered_map>
#include <vector>

#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <ezprint.cpp>

namespace pce {
namespace cube {

std::unordered_map<uint32_t, glm::dvec3> getCubeVertexLocationMap(const glm::dvec3& center, const double side_length) {
  const double half_side_length = side_length/2.0; 
  const double y_above = center.y + half_side_length;
  const double y_below = center.y - half_side_length;
  const double x_left = center.x + half_side_length;
  const double x_right = center.x - half_side_length;
  const double z_left = center.z + half_side_length;
  const double z_right = center.z - half_side_length;

  std::unordered_map<uint32_t, glm::dvec3> map = {
      {1, glm::dvec3(x_left, z_left, y_above)},
      {2, glm::dvec3(x_right, z_left, y_above)},
      {3, glm::dvec3(x_left, z_right, y_above)},
      {4, glm::dvec3(x_right, z_right, y_above)},
      {5, glm::dvec3(x_left, z_left, y_below)},
      {6, glm::dvec3(x_right, z_left, y_below)},
      {7, glm::dvec3(x_left, z_right, y_below)},
      {8, glm::dvec3(x_right, z_right, y_below)}
  };

  return map;
}

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
