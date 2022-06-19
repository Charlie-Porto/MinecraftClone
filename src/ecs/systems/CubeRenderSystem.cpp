#ifndef CubeRenderSystem_cpp
#define CubeRenderSystem_cpp

/*----------------------------------------------------------------|
--------------------- Module Description -------------------------|
system to render cubes
-----------------------------------------------------------------*/

#include <unordered_map>
#include <vector>
#include <ezprint.cpp>

#include <quaternion_funktions.cpp>

#include "../System.cpp"
#include "cubeRenderFunctions.cpp"
// #include "cubeRotationFunctions.cpp"
#include "subsystems/simpleDrawingFunctions.cpp"

extern ControlPanel control;

namespace pce {
class CubeRenderSystem : public ISystem {
public:


  std::unordered_map<Entity, glm::dvec3> GetVerticesToCertainlyDraw(Cube& cube_component, const glm::dvec3& camera_location) {
    std::unordered_map<Entity, glm::dvec3> closest_vertices = pce::cube::getClosestCubePointsToCamera(
      cube_component.original_vertices, camera_location);
    std::unordered_map<Entity, glm::dvec3> vertices_to_draw = pce::cube::getCubeVerticesToDraw(
                                             cube_component.original_vertices, closest_vertices);
    return vertices_to_draw; 
  }


  void RenderCubes(const glm::dvec3& camera_location) {
    for (auto const& entity : entities) {
      auto& cube = control.GetComponent<pce::Cube>(entity);
      auto& cube_radar = control.GetComponent<pce::CubeRadar>(entity);
      std::unordered_map<Entity, glm::dvec3> vertices_to_draw = GetVerticesToCertainlyDraw(
                                                                    cube, camera_location);
      for (auto const& [sure_key, sure_vertex] : vertices_to_draw) {
        for (auto const& [potential_key, potential_vertex] : cube.current_vertices) {
          ezp::print_labeled_item("vertex: ", potential_key);
          vezp::print_dvec3(potential_vertex);
          if ((cube.original_vertices.at(sure_key).x == cube.original_vertices.at(potential_key).x
               && cube.original_vertices.at(sure_key).y == cube.original_vertices.at(potential_key).y)
            || (cube.original_vertices.at(sure_key).x == cube.original_vertices.at(potential_key).x
               && cube.original_vertices.at(sure_key).z == cube.original_vertices.at(potential_key).z)
            || (cube.original_vertices.at(sure_key).z == cube.original_vertices.at(potential_key).z
               && cube.original_vertices.at(sure_key).y == cube.original_vertices.at(potential_key).y)
          ) {
            pce::quickdraw::drawLine(cube_radar.vertex_hitpoint_pixels.at(sure_key),
                                     cube_radar.vertex_hitpoint_pixels.at(potential_key)); 
          }
        }
      }
    }
  }

  
   
};
}
#endif /* CubeRenderSystem_cpp */
