# ifndef escultor_hpp
#define sculptor_hpp _ 

estrutura  Voxel {
flutuar r, g, b; // núcleos
flutuar um; // transparência
show de bool ; // mostrado ou não
};

classe  Escultor {
privado:
  Voxel***v; // Ponteiro para ponteiro para ponteiro do tipo struct voxel
  int nx,ny,nz; // Dimensões da matriz
  flutuar r,g,b,a; // Definições dos núcleos vermelho, verde, azul e transparência dos voxels
público:
  Escultor ( int _nx, int _ny, int _nz); // Construtor responsável por iniciar o objeto
  ~Escultor (); // Destruidor responsável por encerrar o objeto
  void  setColor ( float r, float g, float b, float alfa); // Selecionado a cor e a transparência do voxel
  void  putVoxel ( int x, int y, int z); // Implementa um voxel em (x,y,z)
  void  cutVoxel ( int x, int y, int z); // Extrai um voxel em (x,y,z)
  void  putBox ( int x0, int x1, int y0, int y1, int z0, int z1); // Implementação de um bloco de voxels
  void  cutBox ( int x0, int x1, int y0, int y1, int z0, int z1); // Extração de um bloco de voxels
  void  putSphere ( int xcenter, int ycenter, int zcenter, int radius); // Implementação de um bloco de voxels em formato de esfera
  void  cutSphere ( int xcenter, int ycenter, int zcenter, int radius); // Extração de um bloco de voxels em formato de esfera
  void  putEllipsoid ( int xcenter, int ycenter, int zcenter, int rx, int ry, int rz); // Implementação de um bloco de voxels em formato elipsoide
  void  cutEllipsoid ( int xcenter, int ycenter, int zcenter, int rx, int ry, int rz); // Extração de um bloco de voxels em formato elipsoide
  void  writeOFF ( char * nome do arquivo); // Gravação da escultura em arquivo
};

#endif _
