#include "Puzzle.h"
#include <iostream>
#include <cmath>

Puzzle::Puzzle() {
}

int Puzzle::getPuzzleState(int x) {
	//std::cout << "State at " << x << " = " << this->square[x];
	return square[x];
}

void Puzzle::setPuzzleState(int x, int n) {
	square[x] = n;
}


//assuming we only swap with the empty (0) position, then whatever square is adjacent to
//it will return either 1 for horizontally adjacent, 3 for vertically adjacent or 0 for
//not adjacent
int Puzzle::calcAdjacent(int square1, int square2) {
	int adj = 0;
	//Squares are adjacent in the horizontal plane
	if (abs(square1 - square2) == 1){
		adj = 1;
	}
	//Squares are adjacent in the vertical plane
	else if (abs(square1 - square2) == 3) {
		adj = 3;
	}
	
	return adj;
}

int Puzzle::findEmpty() {
	for (int i=0; i<8; i++) {
		if (square[i] == 0)
			return i;
	}
}

void Puzzle::swapPositions(int x) {
	// if empty square is adjacent to attempted swap, swap them
	std::cout<< "square[findEmpty()] : " << square[this->findEmpty()]<< std::endl;
	std::cout<< "findEmpty(): " << findEmpty() << std::endl;
	std::cout<< "square[x] : " << square[x]<< std::endl;
	if (calcAdjacent(x, findEmpty())) {
		std::cout<< "calcAdjacent true!" << std::endl;
		std::cout<< "square[findEmpty()] : " << square[findEmpty()]<< std::endl;
		std::cout<< "square[x] : " << square[x]<< std::endl;
		square[findEmpty()] = square[x];
		square[x] = 0;
		
	}
} 
void Puzzle::printPuzzle() {
	for (int i = 0; i<9; i++) {
		if (i == 3 || i == 6) 
			std::cout << std::endl; 
		std::cout << square[i] << " ";
	}
	std::cout << std::endl;
}