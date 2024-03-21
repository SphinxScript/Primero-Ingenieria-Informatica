/***
   * Universidad de La Laguna
   * Escuela Superior de Ingeniería y Tecnología
   * Grado en Ingeniería Informática
   * Informática Básica 2022-2023
   *
   * @author Ricardo David Rodríguez Pane alu0101643137@ull.edu.es
   * @date Nov 02 2023
   * @brief FUNCIÓN BOOL HECHA PARA SUBIR A JUTGE. chequea si una fecha es válida o no
   * @bug There are no known bugs
   * @see https://www.cs.cmu.edu/~410/doc/doxygen.html
   **/

bool is_valid_date (int d, int m, int y) {
  if (d < 1 || d > 31 || m < 1 || m > 12) {
    return false;
  }
  if ((m == 4 || m == 6 || m == 9 || m == 11) && d > 30) {
    return false;
  }
  if (m == 2) {
    if (y % 4 == 0 && y % 100 !=0 || y % 400 == 0) {
      if (d > 29) {
        return false;
      }
    }
    else {
      if (d > 28) {
        return false;
      }
    }
  }
  return true;
}