#include <iostream>
#include "Puzzle.h"
#include "Puzzle.cpp"
#include <list>

int main(int argc, char** argv) {
	Puzzle p = Puzzle();
	std::list<Puzzle> open, closed;
	p.printPuzzle();
	std::cout<< std::endl << "Possible moves: ";
	p.findPossibleMoves();

	std::cout << "State at 2: "<<  p.getPuzzleState(2) << std::endl;
	std::cout << "p.square[4]" << p.square[4] << std::endl;
	
	std::cout << "Adjacency of 1, 4 : " << p.calcAdjacent(1, 4) << std::endl;
	std::cout << "Empty square is at : " << p.findEmpty() << std::endl;
	std::cout << "Swapping: 1 and empty 0: " << std::endl;
	p.swapPositions(1);
	std::cout << "Empty square is at : " << p.findEmpty() << std::endl;
	p.printPuzzle();
	std::cout << "p.square[1]" << p.square[1] << std::endl;
	auto q = Puzzle(p);
	q.printPuzzle();
	std::cout<< std::endl << "Possible moves: ";
	q.findPossibleMoves();
	return 0;
}