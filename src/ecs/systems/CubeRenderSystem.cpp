#ifndef CubeRenderSystem_cpp
#define CubeRenderSystem_cpp

/*----------------------------------------------------------------|
--------------------- Module Description -------------------------|
system to render cubes
-----------------------------------------------------------------*/

#include <unordered_map>
#include <vector>
#include <ezprint.cpp>

#include "../System.cpp"
#include "cubeRenderFunctions.cpp"
#include "subsystems/simpleDrawingFunctions.cpp"

extern ControlPanel control;

namespace pce {
class CubeRenderSystem : public ISystem {
public:
  void PerformCubeOrganization() {
    for (auto const& entity : entities) {
      auto const& cube_vertex = control.GetComponent<pce::CubeVertex>(entity);
      cubes_[cube_vertex.parent_cube].push_back(entity);
    }
  }

  std::unordered_map<Entity, glm::dvec3> gatherCubeVertexLocations(uint32_t cube) const {
    std::unordered_map<Entity, glm::dvec3> vertices;
    const std::vector<Entity> vertex_entities = cubes_.at(cube);
    for (auto const& point : vertex_entities) {
      auto const& location = control.GetComponent<pce::Location>(point);
      vertices[point] = location.position;
    }
    return vertices;
  }

  void GetVisibleCubeFaces(uint32_t cube, const glm::dvec3& camera_location) {
    std::unordered_map<Entity, glm::dvec3> vertices = gatherCubeVertexLocations(cube);
    std::unordered_map<Entity, glm::dvec3> closest_vertices = pce::cube::getClosestCubePointsToCamera(
                                                   vertices, camera_location);
    std::unordered_map<Entity, glm::dvec3> vertices_to_draw = pce::cube::getCubeVerticesToDraw(
                                                   vertices, closest_vertices);
        
    cube_vertices_to_draw_ = vertices_to_draw;
  }

  void RenderCubes(const glm::dvec3& camera_location) { 
    // for (auto const& [key, value] : cubes_) {
      GetVisibleCubeFaces(1.0, camera_location);
      for (auto const& [key_a, value_a] : cube_vertices_to_draw_) {
        auto const& radar_a = control.GetComponent<pce::Radar>(key_a); 
        auto const& location_a = control.GetComponent<pce::Location>(key_a); 
        const std::vector<Entity> vertex_entities = cubes_.at(1.0);
        for (auto const& value_b : vertex_entities) {
          // if (key_a == key_b) {continue;}
          auto const& radar_b = control.GetComponent<pce::Radar>(value_b); 
          auto const& location_b = control.GetComponent<pce::Location>(value_b); 
          if ((location_a.position.x == location_b.position.x && location_a.position.y == location_b.position.y)
              || (location_a.position.y == location_b.position.y && location_a.position.z == location_b.position.z)
              || (location_a.position.z == location_b.position.z && location_a.position.x == location_b.position.x)) {
            pce::quickdraw::drawLine(radar_b.hitpoint_corresponding_pixel,
                                      radar_a.hitpoint_corresponding_pixel);
          }
        }
      // }
    }
  }

private: 
  std::unordered_map<uint32_t, std::vector<uint32_t>> cubes_;
  std::unordered_map<uint32_t, glm::dvec3> cube_vertices_to_draw_;
   
};
}
#endif /* CubeRenderSystem_cpp */
