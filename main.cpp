#include <iostream>
#include "Puzzle.h"
#include "Puzzle.cpp"

int main(int argc, char** argv) {
	Puzzle p = Puzzle();
	p.printPuzzle();
	std::cout << "State at 2: "<<  p.getPuzzleState(2) << std::endl;
	std::cout << p.square[4] << std::endl;
	
	std::cout << "Adjacency of 1, 4 : " << p.calcAdjacent(1, 4) << std::endl;
	std::cout << "Empty square is at : " << p.findEmpty() << std::endl;
	std::cout << "Swapping: 1 and empty 0: " << std::endl;
	p.swapPositions(1);
	std::cout << "Empty square is at : " << p.findEmpty() << std::endl;
	p.printPuzzle();
	return 0;
}