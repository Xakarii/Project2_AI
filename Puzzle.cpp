#include "Puzzle.h"
#include <iostream>

Puzzle::Puzzle() {
	//for (int i = 0; i < 10; i++) {
	//	square[i] = 11;
	//}
}

int Puzzle::getPuzzleState(int x) {
	//std::cout << "State at " << x << " = " << this->square[x];
	return square[x];
}

void Puzzle::setPuzzleState(int x, int n) {
	square[x] = n;
}