#ifndef CubeObjectFactory_cpp
#define CubeObjectFactory_cpp

/*----------------------------------------------------------------|
--------------------- Module Description -------------------------|
cube factory.
-----------------------------------------------------------------*/

#include <ezprint.cpp>

#include "VertexObjectFactory.cpp"
#include "cubeFactoryFunctions.cpp"

class CubeObjectFactory {
public:
  void MakeCube(const glm::dvec3& cube_center, const double& side_length) {
    std::vector<glm::dvec3> cube_points = pce::cube::getCubeVertexLocations(cube_center, side_length);
    for (auto const& vertex : cube_points) {
      vertex_factory_.MakeCubeVertex(vertex, 1);
    }
  }

private:
  VertexObjectFactory vertex_factory_;
  
};



#endif /* CubeObjectFactory_cpp */
