#ifndef CubeObjectFactory_cpp
#define CubeObjectFactory_cpp

/*----------------------------------------------------------------|
--------------------- Module Description -------------------------|
cube factory.
-----------------------------------------------------------------*/

#include <ezprint.cpp>

// #include "VertexObjectFactory.cpp"
#include "cubeFactoryFunctions.cpp"

class CubeObjectFactory {
public:
  // void MakeCube(const glm::dvec3& cube_center, const double& side_length, uint32_t parent_cube) {
  //   std::vector<glm::dvec3> cube_points = pce::cube::getCubeVertexLocations(cube_center, side_length);
  //   for (auto const& vertex : cube_points) {
  //     vertex_factory_.MakeCubeVertex(vertex, parent_cube);
  //   }
  // }


  void MakeModernCube(const glm::dvec3& cube_center, const double& side_length) {
    Entity object = control.CreateEntity();
    control.AddComponent(object, pce::Location{
      .position = cube_center
    });
    control.AddComponent(object, pce::RotatedLocation{});
    control.AddComponent(object, pce::SphereBody{.radius = 0.1});
    control.AddComponent(object, pce::Radar{});
    control.AddComponent(object, pce::Surface{
      .natural_color = {20, 240, 120, 255}, 
      .luminosity = 0.0,
      .superimposed = false
    });
    std::unordered_map<uint32_t, glm::dvec3> cube_points = pce::cube::getCubeVertexLocationMap(cube_center, side_length);
    control.AddComponent(object, pce::Cube{
      .original_vertices = cube_points, 
      .current_vertices = cube_points, 
      .rotation_versor = glm::dquat(0, 0, 0, 1.0)
    });
    control.AddComponent(object, pce::CubeRadar{});
  }

private:
  // VertexObjectFactory vertex_factory_;
  
};



#endif /* CubeObjectFactory_cpp */
