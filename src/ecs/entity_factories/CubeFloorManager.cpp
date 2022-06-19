#ifndef CubeFloorManager_cpp
#define CubeFloorManager_cpp

/*----------------------------------------------------------------|
--------------------- Module Description -------------------------|

-----------------------------------------------------------------*/

#include <ezprint.cpp>
#include "CubeObjectFactory.cpp"

class CubeFloorManager {
public:
CubeFloorManager() { cube_number_ = 1; }

void GenerateCubeFloor(const double cube_quantity_edge, const double cube_side_length) {
  double starting_x_and_z = cube_quantity_edge * cube_side_length + cube_side_length/2.0;
  double i = -starting_x_and_z;
  while (i <= starting_x_and_z) {
    double j = -starting_x_and_z;
    while (j <= starting_x_and_z) {
      // cube_factory_.MakeCube(glm::dvec3(i, j, -cube_side_length), cube_side_length, cube_number_);
      j += cube_side_length;
      ++cube_number_;
    }
    i += cube_side_length;
  }
}

private:
uint32_t cube_number_;
CubeObjectFactory cube_factory_;

};


#endif /* CubeFloorManager_cpp */
