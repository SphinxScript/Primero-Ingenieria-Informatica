#include <iostream>
#include "grains.h"
namespace grains {
  std::uint64_t square(int casillas) {
    std::uint64_t result = ((uint64_t)1<<(casillas-1));
    return result;
  }
  std::uint64_t total() {
    std::uint64_t result = 1;
      for(int i = 2; i <= 64; i++) {
        result += square(i);
      }
      return result;
  }
}  // namespace grains
