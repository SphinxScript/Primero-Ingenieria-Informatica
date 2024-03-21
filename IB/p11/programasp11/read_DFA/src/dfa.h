#ifndef DFA_H
#define DFA_H

#include <iostream>
#include <fstream>
#include <vector>

struct Transition {
  char symbol;
  unsigned int destination;
};

struct State {
  unsigned int id;
  bool isAccepting;
  std::vector<Transition> transitions;
};

class DFA {
public:
  void readFromFile(const char* filename);
  void printInfo();

private:
  unsigned int numStates;
  unsigned int startState;
  std::vector<State> states;
};

#endif // DFA_H