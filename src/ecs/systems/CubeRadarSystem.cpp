#ifndef CubeRadarSystem_cpp
#define CubeRadarSystem_cpp

/*----------------------------------------------------------------|
--------------------- Module Description -------------------------|
radar for entities with cube components.
-----------------------------------------------------------------*/

#include <ezprint.cpp>

#include "../System.cpp"
#include "objectRadarDetectorFunctions.cpp"

extern ControlPanel control;

namespace pce {
class CubeRadarSystem : public ISystem {
public:
  CubeRadarSystem() { ezp::print_item("creating Cube Radar System"); }

void UpdateCubeRadar(const double camera_pos_scalar, const glm::dquat rotation_versor,
                     const glm::dvec3& camera_focus_position) {
  for (auto const& entity : entities) {
    // ezp::print_labeled_item("updating Cube Radar for entity: ", entity);
    auto& cube = control.GetComponent<pce::Cube>(entity);
    auto& cube_radar = control.GetComponent<pce::CubeRadar>(entity);
    const std::unordered_map<uint32_t, glm::dvec3> vertices = cube.original_vertices;
    for (auto const& [key, value] : vertices) {
      cube.current_vertices[key] = pce::radar::rotateObjectCenterPoint(cube.original_vertices.at(key),
                                                                       rotation_versor);
      cube_radar.vertex_hitpoints[key] = pce::radar::calculateObjectRadarLocation(
                                      cube.current_vertices.at(key),
                                      camera_pos_scalar);
      cube_radar.vertex_hitpoint_pixels[key] = pce::pix_map::convertPointOnViewSphereToPixel(
                                                   cube_radar.vertex_hitpoints.at(key),
                                                   glm::dvec3(0, 0, camera_pos_scalar));
      // ezp::print_labeled_item("vertex: ", key);
      // vezp::print_dvec3(value);
      // ezp::print_labeled_item("rotated vertex: ", key);
      // vezp::print_dvec3(cube.current_vertices.at(key));
      pce::quickdraw::drawCircleAtVec2(cube_radar.vertex_hitpoint_pixels.at(key));
    }
  }
}

private:
};
}
#endif /* CubeRadarSystem_cpp */
