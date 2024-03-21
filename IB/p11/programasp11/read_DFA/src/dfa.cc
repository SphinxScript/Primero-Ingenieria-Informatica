#include "dfa.h"

void DFA::readFromFile(const char* filename) {
  std::ifstream file(filename);
  if (!file.is_open()) {
    std::cerr << "Error: Unable to open file " << filename << std::endl;
    return;
  }

  file >> numStates;
  file >> startState;

  states.resize(numStates);

  for (unsigned int i = 0; i < numStates; ++i) {
    State& state = states[i];
    state.id = i;

    file >> state.isAccepting;

    unsigned int numTransitions;
    file >> numTransitions;

    state.transitions.resize(numTransitions);
    for (unsigned int j = 0; j < numTransitions; ++j) {
      Transition& transition = state.transitions[j];
      file >> transition.destination >> transition.symbol;
    }
  }
}

void DFA::printInfo() {
  std::cout << "|Q| = " << numStates << std::endl;
  std::cout << "q0 = " << startState << std::endl;

  std::cout << "F = {";
  bool firstAccepting = true;
  for (const State& state : states) {
    if (state.isAccepting) {
      if (!firstAccepting) {
        std::cout << ", ";
      }
      std::cout << state.id;
      firstAccepting = false;
    }
  }
  std::cout << "}" << std::endl;

  for (const State& state : states) {
    for (const Transition& transition : state.transitions) {
      std::cout << "delta(" << state.id << ", " << transition.symbol << ") = " << transition.destination << std::endl;
    }
  }
}