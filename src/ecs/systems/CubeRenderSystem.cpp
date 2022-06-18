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

  void RenderCubes() { for (auto const& [key, value] : cubes_) {
      for (auto const& vertex : value) {
        // ezp::print_item("printing a vertex");
        auto const& radar_a = control.GetComponent<pce::Radar>(vertex); 
        auto const& location_a = control.GetComponent<pce::Location>(vertex); 
        for (auto const& other_vertex : value) {
          if (vertex == other_vertex) {continue;}
          auto const& radar_b = control.GetComponent<pce::Radar>(other_vertex); 
          auto const& location_b = control.GetComponent<pce::Location>(other_vertex); 
          if ((location_a.position.x == location_b.position.x && location_a.position.y == location_b.position.y)
              || (location_a.position.y == location_b.position.y && location_a.position.z == location_b.position.z)
              || (location_a.position.z == location_b.position.z && location_a.position.x == location_b.position.x)) {
            pce::quickdraw::drawLine(radar_b.hitpoint_corresponding_pixel,
                                     radar_a.hitpoint_corresponding_pixel);
          }
        }
      }
    }
  }

private: 
  std::unordered_map<uint32_t, std::vector<uint32_t>> cubes_;
   
};
}
#endif /* CubeRenderSystem_cpp */
