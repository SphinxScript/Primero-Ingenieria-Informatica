#include "dfa.h"

int main() {
  const char* filename = "input.dfa";
  DFA dfa;
  dfa.readFromFile(filename);
  dfa.printInfo();

  return 0;
}