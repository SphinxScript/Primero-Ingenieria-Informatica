/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica 2022-2023
  *
  * @author Ricardo David Rodríguez Pane alu0101643137@ull.edu.es
  * @date Nov 17 2023
  * @brief This code calculates if a year is a leap year or not, and  returns
  *        true if it is a leap year, and false if it is not.
  * @bug There are no known bugs
  * @see https://www.cs.cmu.edu/~410/doc/doxygen.html
  */

#include "leap.h"

namespace leap {
/// bool function to calculate a leap year
  bool is_leap_year(int year) {
    if ((year % 4) == 0) {
      if ((year % 100) == 0) {
        return ((year % 400) == 0);
      }
      else {
        return true;
      }
    }
    else {
      return false;
    }
  }
}  /// namespace leap
