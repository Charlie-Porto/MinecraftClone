#ifndef VertexObjectFactory_cpp
#define VertexObjectFactory_cpp

/*----------------------------------------------------------------|
--------------------- Module Description -------------------------|
class for making vertexes
-----------------------------------------------------------------*/

#include <ezprint.cpp>

extern ControlPanel control; 

class VertexObjectFactory {
public:
  uint32_t MakeVertexObject(const glm::dvec3& location) {
    Entity object = control.CreateEntity();
    control.AddComponent(object, pce::Location{
      .position = location
    });
    control.AddComponent(object, pce::RotatedLocation{});
    control.AddComponent(object, pce::SphereBody{.radius = 0.1});
    control.AddComponent(object, pce::Radar{});
    control.AddComponent(object, pce::Surface{
      .natural_color = {20, 240, 120, 255}, 
      .luminosity = 0.0,
      .superimposed = false
    });
    return object;
  }
  

  uint32_t MakeCubeVertex(const glm::dvec3& location, uint32_t parent_cube) {
    Entity vertex = MakeVertexObject(location);
    control.AddComponent(vertex, pce::CubeVertex{
      .parent_cube = parent_cube
    });
    return vertex;
  }

};



#endif /* VertexObjectFactory_cpp */
