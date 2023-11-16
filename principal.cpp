#include <iostream>
#include "sculptor.hpp"

int main() {
  
  // Cria um escultor cuja matriz tem 10x10x10 voxels
  Sculptor s(10,10,10);
  
  // Serve para adicionar e mudar as corres do voxel
  s.setColor(0,0,1.0,1.0); // azul

  s.putEllipsoid(6,6,6,4,3,3);
  
  s.writeOFF("Ellipsoid.off");
}
