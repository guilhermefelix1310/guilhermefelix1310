#incluir " escultor.hpp " _ 
#inclui <iostream> _  _ _
#inclui <cmath> _  _ _
#inclui <fstream> _  _ _
#include <iomanip> _  _ _
usando  namespace  std ;

Sculptor::Sculptor ( int _nx, int _ny, int _nz){ // instância de classe e alocação da matriz
     nx = _nx;
     ny = _ny;
     nz = _nz;

     r = 0 ;
     g = 0 ;
     b = 0 ;
     uma = 0 ;

     v = novo Voxel**[_nx]; // alocação de memória da 1 dimensão da matriz
     for ( int i= 0 ; i<_nx; i++){
         v[i] = novo Voxel*[_ny]; // alocação de memória da 2ª dimensão da matriz

         for ( int j= 0 ; j<_ny; j++){
             v[i][j] = novo Voxel [_nz]; // alocação de memória da 3ª dimensão da matriz

             for ( int k= 0 ; k<_nz; k++){
                 isto -> v[i][j][k]. r = 0 ;
                 isto -> v[i][j][k]. g = 0 ;
                 isto -> v[i][j][k]. b = 0 ;
                 isto -> v[i][j][k]. uma = 0 ;
                 isto -> v[i][j][k]. mostrar = falso ;
             }
         }
     }

}

Sculptor::~Sculptor (){ // liberação da memória alocada
    for ( int i= 0 ; i<nx; i++){
        for ( int j= 0 ; j<ny; j++){
            excluir [] v[i][j]; // liberação da última alocação
        }
        excluir [] v[i]; // liberação da penúltima
    }
    excluir [] v; // liberação da primeira
}


void  Sculptor::setColor ( float vermelho, float verde, float azul, float alfa){
    // atribuição das cores a partir dos parâmetros
    isto -> r = vermelho;
    isto -> g = verde;
    isto -> b = azul;
    isto -> a = alfa;

}

void  Escultor::putVoxel ( int x, int y, int z){
    // ativação de um único voxel
    isto -> v [x][y][z]. r = isto -> r;
    isto -> v [x][y][z]. g = isto -> g;
    isto -> v [x][y][z]. b = isto -> b;
    isto -> v [x][y][z]. uma = isto -> uma;
    isto -> v [x][y][z]. mostrar = verdadeiro ;

}

void  Escultor::cutVoxel ( int x, int y, int z){
    isto -> v [x][y][z]. mostrar = falso ; // desativação de um único voxel
}

// ativação de um bloco de voxels
void  Escultor::putBox ( int x0, int x1, int y0, int y1, int z0, int z1){
    if (( this -> nx >= x0 && this -> nx >= x1) && ( this -> ny >= y0 && this -> ny >= y1 ) && ( this -> nz >= z0 && this -> nz >= z1)){
        for ( int i = x0; i <x1 ; i++){
            for ( int j = y0 ; j < y1 ; j++){
                for ( int k = z0; k <z1 ; k++){
                    isto -> v [i][j][k]. r = isto -> r;
                    isto -> v [i][j][k]. g = isto -> g;
                    isto -> v [i][j][k]. b = isto -> b;
                    isto -> v [i][j][k]. uma = isto -> uma;
                    isto -> v [i][j][k]. mostrar = verdadeiro ;
                }
            }
        }
    }

}
// desativação de um bloco de voxel
void  Escultor::cutBox ( int x0, int x1, int y0, int y1, int z0, int z1){
    if (( this -> nx >= x0 && this -> nx >= x1) && ( this -> ny >= y0 && this -> ny >= y1 ) && ( this -> nz >= z0 && this -> nz >= z1)){
     for ( int i = x0; i <x1 ; i++){
            for ( int j = y0 ; j < y1 ; j++){
                for ( int k = z0; k <z1 ; k++){
                    isto -> v [i][j][k]. mostrar = falso ;
                }
            }
        }
    }
}
// ativação de um bloco de voxels em forma de esfera
void  Escultor::putSphere ( int xcentro, int ycentro, int zcentro, int raio){
         for ( int i = 0 ; i <nx ; i++){
            for ( int j = 0 ; j < ny; j++){
                for ( int k = 0 ; k <nz; k++){
                   if (( pow (i-xcenter, 2 ) + pow (j-ycenter, 2 ) + pow (k-zcenter, 2 )) <= pow (raio, 2 )){
                        isto -> v [i][j][k]. r = isto -> r;
                        isto -> v [i][j][k]. g = isto -> g;
                        isto -> v [i][j][k]. b = isto -> b;
                        isto -> v [i][j][k]. uma = isto -> uma;
                        isto -> v [i][j][k]. mostrar = verdadeiro ;
                    }
                }

            }

        }

}
// desativação de um bloco de voxels em forma de esfera
void  Escultor::cutSphere ( int xcentro, int ycentro, int zcentro, int raio){
     for ( int i = 0 ; i <nx ; i++){
            for ( int j = 0 ; j < ny; j++){
                for ( int k = 0 ; k <nz; k++){
                   if (( pow (i-xcenter, 2 ) + pow (j-ycenter, 2 ) + pow (k-zcenter, 2 )) <= pow (raio, 2 )){
                        isto -> v [i][j][k]. mostrar = falso ;
                    }
                }
            }
        }
}
// ativação de um bloco de voxels em forma de elipsoide
void  Escultor::putEllipsoid ( int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
     for ( int i = 0 ; i <nx ; i++){
            for ( int j = 0 ; j < ny; j++){
                for ( int k = 0 ; k <nz; k++){
                   if ((( pow (i-xcentro, 2 )/ pow (rx, 2 )) + ( pow (j-ycentro, 2 )/ pow (ry, 2 ))+
                   ( pow (k-zcenter, 2 )/ pow (rz, 2 ))) <= 1 ){
                        isto -> v [i][j][k]. r = isto -> r;
                        isto -> v [i][j][k]. g = isto -> g;
                        isto -> v [i][j][k]. b = isto -> b;
                        isto -> v [i][j][k]. uma = isto -> uma;
                        isto -> v [i][j][k]. mostrar = verdadeiro ;
                    }
                }

            }

        }
}

// desativação de um bloco de voxels em forma de elipsoide
void  Escultor::cutEllipsoid ( int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
    for ( int i = 0 ; i <nx ; i++){
            for ( int j = 0 ; j < ny; j++){
                for ( int k = 0 ; k <nz; k++){
                   if ((( pow (i-xcentro, 2 )/ pow (rx, 2 )) + ( pow (j-ycentro, 2 )/ pow (ry, 2 ))+
                   ( pow (k-zcenter, 2 )/ pow (rz, 2 ))) <= 1 ){
                        isto -> v [i][j][k]. mostrar = falso ;
                    }
                }
            }
        }
}
// gravação do arquivo
void  Escultor::writeOFF ( char *nome do arquivo){
    int total_vox= 0 , cont_vox= 0 ;

    arquivo ofstream; // objeto da classe ofstream
    arquivo. abrir (nome do arquivo); // abre o fluxo para o arquivo

    for ( int i = 0 ; i < nx ; i++){
        for ( int j = 0 ; j < ny; j++){
            for ( int k = 0 ; k < nz; k++){
                if ( this -> v[i][j][k]. show == true ){
                        total_vox++;
                    }
                }
            }
        }

    arquivo << " OFF " << endl;
    arquivo << 8 * total_vox << "  " << 6 * total_vox << "  " << " 0 " <<endl;

 // definindo as coordenadas dos vértices do voxel
    for ( int i = 0 ; i <nx ; i++){
        for ( int j = 0 ; j <ny; j++){
            for ( int k = 0 ; k <nz; k++){
                  if ( this -> v [i][j][k]. show == true ){

                     arquivo << i - 0,5 << "  " << j + 0,5 << "  " << k - 0,5 <<endl;
                     arquivo << i - 0,5 << "  " << j - 0,5 << "  " << k - 0,5 <<endl;
                     arquivo << i + 0,5 << "  " << j - 0,5 << "  " << k - 0,5 <<endl;
                     arquivo << i + 0,5 << "  " << j + 0,5 << "  " << k - 0,5 <<endl;
                     arquivo << i - 0,5 << "  " << j + 0,5 << "  " << k + 0,5 <<endl;
                     arquivo << i - 0,5 << "  " << j - 0,5 << "  " << k + 0,5 <<endl;
                     arquivo << i + 0,5 << "  " << j - 0,5 << "  " << k + 0,5 <<endl;
                     arquivo << i + 0,5 << "  " << j + 0,5 << "  " << k + 0,5 <<endl;

                  }
                }
            }
        }
            arquivo << setiosflags (ios::fixed);
    // especificações das faces e apresentação dos núcleos no formato RGBA
        for ( int i = 0 ; i <nx ; i++){
            for ( int j = 0 ; j <ny; j++){
                for ( int k = 0 ; k <nz; k++){
                    if ( this -> v [i][j][k]. show == true ){

                        arquivo << " 4 " << "  " << 8 * cont_vox + 0 << "  " << 8 * cont_vox + 3 << "  " << 8 * cont_vox + 2 << "  "   << 8 * cont_vox + 1 << "  " << v [i][j][k]. r << "  " << v [i][j][k]. g << "  " << v [i][j][k]. b << "  " << v [i][j][k]. um << fim;
                        arquivo << " 4 " << "  " << 8 * cont_vox + 4 << "  " << 8 * cont_vox + 5 << "  " << 8 * cont_vox + 6 << "  "   << 8 * cont_vox + 7 << "  " << v [i][j][k]. r << "  " << v [i][j][k]. g << "  " << v [i][j][k]. b << "  " << v [i][j][k]. um << fim;
                        arquivo << " 4 " << "  " << 8 * cont_vox + 0 << "  " << 8 * cont_vox + 1 << "  " << 8 * cont_vox + 5 << "  "   << 8 * cont_vox + 4 << "  " << v [i][j][k]. r << "  " << v [i][j][k]. g << "  " << v [i][j][k]. b << "  " << v [i][j][k]. um << fim;
                        arquivo << " 4 " << "  " << 8 * cont_vox + 0 << "  " << 8 * cont_vox + 4 << "  " << 8 * cont_vox + 7 << "  "   << 8 * cont_vox + 3 << "  " << v [i][j][k]. r << "  " << v [i][j][k]. g << "  " << v [i][j][k]. b << "  " << v [i][j][k]. um << fim;
                        arquivo << " 4 " << "  " << 8 * cont_vox + 3 << "  " << 8 * cont_vox + 7 << "  " << 8 * cont_vox + 6 << "  "   << 8 * cont_vox + 2 << "  " << v [i][j][k]. r << "  " << v [i][j][k]. g << "  " << v [i][j][k]. b << "  " << v [i][j][k]. um << fim;
                        arquivo << " 4 " << "  " << 8 * cont_vox + 1 << "  " << 8 * cont_vox + 2 << "  " << 8 * cont_vox + 6 << "  "   << 8 * cont_vox + 5 << "  " << v [i][j][k]. r << "  " << v [i][j][k]. g << "  " << v [i][j][k]. b << "  " << v [i][j][k]. um << fim;

                        cont_vox++;

                    }
                }
            }
        }

    arquivo. fechar (); // fechando o fluxo
}
