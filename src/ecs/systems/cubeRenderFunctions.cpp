#ifndef cubeRenderFunctions_cpp
#define cubeRenderFunctions_cpp

/*----------------------------------------------------------------|
--------------------- Module Description -------------------------|
free functions to assist the cube render system
-----------------------------------------------------------------*/
#include <vector>
#include <glm/vec3.hpp>
#include <vector3_functions.cpp>

#include <ezprint.cpp>

namespace pce {
namespace cube {

std::unordered_map<Entity, glm::dvec3> getClosestCubePointsToCamera(
    const std::unordered_map<Entity, glm::dvec3>& vertices, const glm::dvec3& camera_position) {
  std::unordered_map<Entity, glm::dvec3> closest_points;
  double closest_distance = 0.0;
  ezp::print_item("--------");
  for (auto const& [key, value] : vertices) {
    const double distance = vfunc::calculateDistanceBetweenPosition3Vectors(value, camera_position);
    if (closest_distance == 0.0) {
      closest_distance = distance; 
      closest_points[key] = value;
    } else if (closest_distance > distance) {
      closest_distance = distance;
      closest_points.clear();
      closest_points[key] = value;
    } else if (closest_distance == distance) {
      closest_points[key] = value;
    }
  }
  for (auto const& [key, value] : closest_points) {
    ezp::print_item(key);
    vezp::print_dvec3(value);
  }
  return closest_points;
}


std::unordered_map<Entity, glm::dvec3> getCubeVerticesToDraw(
    const std::unordered_map<Entity, glm::dvec3>& vertices, 
    const std::unordered_map<Entity, glm::dvec3>& closest_vertices) {
  std::unordered_map<Entity, glm::dvec3> vertices_to_draw;
  for (auto const& [key, value] : vertices) {
    bool if_draw = true;
    for (auto const [key_closest, value_closest] : closest_vertices) {
      if (value == value_closest) {
        if_draw = false;
        break;
      } else if ((value.x == value_closest.x && value.y == value_closest.y)
              || (value.x == value_closest.x && value.z == value_closest.z)
              || (value.y == value_closest.y && value.z == value_closest.z)) {
        continue;
      } else {if_draw = false; break;}
    }
    if (if_draw) {
      ezp::print_labeled_item("Vertex to Certainly Draw: ", key);
      vezp::print_dvec3(value);
      vertices_to_draw[key] = value;
    }
  }
  return vertices_to_draw;
}



}
}




#endif /* cubeRenderFunctions_cpp */
