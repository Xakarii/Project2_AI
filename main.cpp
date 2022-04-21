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
	std::cout << "Adjacency of 0, 1 : " << p.calcAdjacent(0, 1) << std::endl;
	std::cout << "Adjacency of 1, 2 : " << p.calcAdjacent(1, 2) << std::endl;
	std::cout << "Adjacency of 2, 3 : " << p.calcAdjacent(2, 3) << std::endl;
	std::cout << "Adjacency of 3, 4 : " << p.calcAdjacent(3, 4) << std::endl;
	std::cout << "Adjacency of 4, 5 : " << p.calcAdjacent(4, 5) << std::endl;
	std::cout << "Adjacency of 5, 6 : " << p.calcAdjacent(5, 6) << std::endl;
	std::cout << "Adjacency of 6, 7 : " << p.calcAdjacent(6, 7) << std::endl;
	std::cout << "Adjacency of 6, 7 : " << p.calcAdjacent(7, 8) << std::endl;
	
	std::cout << "Adjacency of 0, 3 : " << p.calcAdjacent(0, 3) << std::endl;
	std::cout << "Adjacency of 0, 4 : " << p.calcAdjacent(0, 4) << std::endl;
	std::cout << "Adjacency of 0, 5 : " << p.calcAdjacent(0, 5) << std::endl;
	std::cout << "Adjacency of 1, 3 : " << p.calcAdjacent(1, 3) << std::endl;
	std::cout << "Adjacency of 1, 4 : " << p.calcAdjacent(1, 4) << std::endl;
	std::cout << "Adjacency of 1, 5 : " << p.calcAdjacent(1, 5) << std::endl;
	std::cout << "Adjacency of 2, 3 : " << p.calcAdjacent(2, 3) << std::endl;
	std::cout << "Adjacency of 2, 4 : " << p.calcAdjacent(2, 4) << std::endl;
	std::cout << "Adjacency of 2, 5 : " << p.calcAdjacent(2, 5) << std::endl;
	std::cout << "Adjacency of 3, 6 : " << p.calcAdjacent(3, 6) << std::endl;
	std::cout << "Adjacency of 3, 7 : " << p.calcAdjacent(3, 7) << std::endl;
	std::cout << "Adjacency of 3, 8 : " << p.calcAdjacent(3, 8) << std::endl;
	std::cout << "Adjacency of 4, 7 : " << p.calcAdjacent(4, 7) << std::endl;
	std::cout << "Adjacency of 5, 8 : " << p.calcAdjacent(5, 8) << std::endl;
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