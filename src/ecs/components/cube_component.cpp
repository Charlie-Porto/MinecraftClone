#ifndef cube_component_cpp
#define cube_component_cpp

#include <unordered_map>
#include <glm/vec3.hpp>
#include <glm/ext/quaternion_double.hpp>

namespace pce {
struct Cube {
  std::unordered_map<uint32_t, glm::dvec3> original_vertices;
  std::unordered_map<uint32_t, glm::dvec3> current_vertices;
  std::unordered_map<uint32_t, glm::dvec3> camera_rotated_vertices;
  glm::dquat rotation_versor;
};

}

#endif /* cube_component_cpp */
