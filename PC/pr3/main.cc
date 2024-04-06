// Solución PR3 curso 23-24
// Manejo de matrices con funciones.
// Autor: Alberto Hamilton Castro
// Fecha: 2024-03-21

#include <iostream>
#include <iomanip>
#include <cmath>
#include <tuple>

typedef struct {
  int nFil;
  int nCol;
  float elementos[];
} structMat;


structMat mat1 {
  6,
  6,
  {
    11.11, 12.12, 13.13, 14.14, 15.15, 16.16,
    21.21, 22.22, 23.23, 24.24, 25.25, 26.26,
    31.31, 32.32, 33.33, 34.34, 35.35, 36.36,
    41.41, 42.42, 43.43, 44.44, 45.45, 46.46,
    51.51, 52.52, 53.53, 54.54, 55.55, 56.56,
    61.61, 62.62, 63.63, 64.64, 65.65, 66.66
  }
};

structMat mat2 {
  7,
  10,
  {
    -36.886, -58.201,  78.671,  19.092, -50.781,  33.961, -59.511, 12.347,  57.306,  -1.938,
    -86.858, -81.852,  54.623, -22.574,  88.217,  64.374,  52.312, 47.918, -83.549,  19.041,
     4.255, -36.842,  82.526,  27.394,  56.527,  39.448,  18.429, 97.057,  76.933,  14.583,
    67.79 ,  -9.861, -96.191,  32.369, -18.494, -43.392,  39.857, 80.686, -36.87 , -17.786,
    30.073,  89.938,  -6.889,  64.601, -85.018,  70.559, -48.853, -62.627, -60.147,  -5.524,
    84.323, -51.718,  93.127, -10.757,  32.119,  98.214,  69.471, 73.814,   3.724,  57.208,
    -41.528, -17.458, -64.226, -71.297, -98.745,   7.095, -79.112, 33.819,  63.531, -96.181
  }
};

structMat mat3 {
  1,
  8,
  {
    -36.52,  35.3 ,  79.05, -58.69, -55.23, -19.44, -88.63, -93.61
  }
};

structMat mat4 {
  16,
  1,
  { -90.57, -65.11, -58.21, -73.23, -89.38, -79.25,  16.82,  66.3 ,
    -96.14, -97.16, -24.66,   5.27, -33.5 , -13.09,  27.13, -74.83 }
};

structMat mat5 {
  1,
  1,
  { 78.98 }
};

structMat mat6 {
  0,
  0,
  { 0 }
};

float infinito = INFINITY;

void print_mat(structMat* mat) {
  int nFil = mat->nFil;
  int nCol = mat->nCol;
  float* elem = mat->elementos;
  std::cout << "\n\nLa matriz tiene dimension " << nFil << 'x' << nCol << '\n';
  for(int f = 0; f < nFil; f++) {
    for(int c = 0; c < nCol; c++) {
      std::cout << elem[f*nCol + c] << ' ';
    }
    std::cout << '\n';
  }
  std::cout << '\n';
}

void change_elto(structMat* mat, int indF, int indC, float valor) {
  int numCol = mat->nCol;
  mat->elementos[indF * numCol + indC] = valor;
}

void swap(float* e1, float* e2) {
  float temp1 = *e1;
  float temp2 = *e2;
  *e1 = temp2;
  *e2 = temp1;
}

void intercambia(structMat* mat, int indF, int indC) {
  int numCol = mat->nCol;
  int numFil = mat->nFil;
  float* datos = mat->elementos;
  float* e1 = &datos[indF * numCol + indC];
  float* e2 = &datos[(numFil - indF - 1) * numCol + (numCol - indC - 1)];
  swap(e1, e2);
}

std::tuple<float, int, int> find_min(structMat* mat) {
  int numCol = mat->nCol;
  int numFil = mat->nFil;
  float* datos = mat->elementos;
  float min = infinito;
  int fmin = -1;
  int cmin = -1;
  for(int f = 0; f < numFil; f++) {
    for(int c = 0; c < numCol; c++) {
      float valor = datos[f * numCol + c];
      if (valor < min) {
        min = valor;
        fmin = f;
        cmin = c;
      }
    }
  }
  return {min, fmin, cmin};
}

int main() {
  std::cout << std::fixed << std::setprecision(8);  // Ignorar
  std::cout << "\nComienza programa manejo matrices con funciones\n";

  structMat* matTrabajo = &mat1;
  while(true) {
    print_mat(matTrabajo);
    std::cout <<
    "(0) Terminar el programa\n"
    "(1) Cambiar la matriz de trabajo\n"
    "(3) Cambiar el valor de un elemento\n"
    "(4) Intercambiar un elemento con su opuesto\n"
    "(7) Encontrar el minimo\n"
    "\nIntroduce opción elegida: ";

    int opcion;
    std::cin >> opcion;


    if(opcion == 0) {
      break;
    }

    // Opción 1 ////////////////////////////////////////////////////////////
    if(opcion == 1) {
      std::cout << "\nElije la matriz de trabajo (1..6): ";
      int matT;
      std::cin >> matT;
      if (matT == 1) {
        matTrabajo = &mat1;
        continue;  // volvemos al principio del bucle
      }
      if (matT == 2) {
        matTrabajo = &mat2;
        continue;  // volvemos al principio del bucle
      }
      if (matT == 3) {
        matTrabajo = &mat3;
        continue;  // volvemos al principio del bucle
      }
      if (matT == 4) {
        matTrabajo = &mat4;
        continue;  // volvemos al principio del bucle
      }
      if (matT == 5) {
        matTrabajo = &mat5;
        continue;  // volvemos al principio del bucle
      }
      if (matT == 6) {
        matTrabajo = &mat6;
        continue;  // volvemos al principio del bucle
      }
      std::cout << "Numero de matriz de trabajo incorrecto\n";
      continue;  // volvemos al principio del bucle
    }

    // Opción 3  y  4 //////////////////////////////////////////////////////////
    if(opcion == 3 || opcion == 4) {
      std::cout << "\nIndice de fila: ";
      int indFil;
      std::cin >> indFil;
      if ((indFil < 0) || (indFil >= matTrabajo->nFil)) {
        std::cerr << "Error: dimension incorrecta.  Numero de fila incorrecto\n";
        continue;  // volvemos al principio del bucle
      }
      std::cout << "Indice de columna: ";
      int indCol;
      std::cin >> indCol;
      if ((indCol < 0) || (indCol >= matTrabajo->nCol)){
        std::cerr << "Error: dimension incorrecta.  Numero de columna incorrecto\n";
        continue;  // volvemos al principio del bucle
      }

      if (opcion == 3) {
        std::cout << "Nuevo valor para el elemento: ";
        float valor;
        std::cin >> valor;
        change_elto(matTrabajo, indFil, indCol, valor);
      }
      if(opcion == 4) {
        intercambia(matTrabajo, indFil, indCol);
      }

      continue;
    }

    // Opción 7 ////////////////////////////////////////////////////////////
    if(opcion == 7) {
      float valorMin;
      int filaMin;
      int columnaMin;
      std::tie(valorMin, filaMin, columnaMin) = find_min(matTrabajo);
      std::cout << "\nEl valor minimo esta en (" << filaMin << ','
        << columnaMin <<") con valor " << valorMin;
      continue;
    }

    // Opción Incorrecta ///////////////////////////////////////////////////////
    std::cout << "Error: opcion incorrecta\n";
  }
  std::cout << "\nTermina el programa\n";
}