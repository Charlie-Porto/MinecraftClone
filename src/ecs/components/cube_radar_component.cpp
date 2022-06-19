#ifndef cube_radar_component_cpp
#define cube_radar_component_cpp

#include <unordered_map>
#include <glm/vec3.hpp>

namespace pce {

struct CubeRadar {
  std::unordered_map<uint32_t, glm::dvec3> vertex_hitpoints;
  std::unordered_map<uint32_t, glm::dvec2> vertex_hitpoint_pixels;
};

}

#endif /* cube_radar_component_cpp */
