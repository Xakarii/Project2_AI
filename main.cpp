#include <iostream>
#include "Puzzle.h"
#include "Puzzle.cpp"
#include <list>
#include <vector>

int main(int argc, char** argv) {
	
	
	Puzzle g = Puzzle(1,2,3,8,0,4,7,6,5); //goal state
	Puzzle initialOne = Puzzle(2,8,3,1,6,4,0,7,5);
	Puzzle initialTwo = Puzzle(2,1,6,4,0,8,7,5,3);
	Puzzle p = Puzzle();
	std::vector<Puzzle> open, closed;
	p.printPuzzle();
	std::cout<< std::endl << "Possible moves: ";
	p.findPossibleMoves();

	std::cout << "State at 2: "<<  p.getPuzzleState(2) << std::endl;
	std::cout << "p.square[4]" << p.square[4] << std::endl;
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
	
	Puzzle r = Puzzle(1, 2, 3, 4, 5, 6, 7, 8, 0);
	r.printPuzzle();
	std::cout << "Empty square is at : " << r.findEmpty() << std::endl;
	std::cout<< std::endl << "Possible moves: ";
	r.findPossibleMoves();
	r.swapPositions(8);
	r.printPuzzle();
	std::cout<<"intial state 1: " << std::endl;
	initialOne.printPuzzle();
	//std::cout<<"intial state 2: " << std::endl;
	//initialTwo.printPuzzle();
	
	std::cout<<"possible moves for initial state 1" << std::endl;
	initialOne.findPossibleMoves();
	
	//for loop that finds possible moves, may want to store them in a
	//locally scoped array, or add a function to output them as needed
	for (int i = 0; i< 4; i++) {
		if (initialOne.possibleMoves[i] != -1) {
			std::cout<< initialOne.possibleMoves[i] << " " ;
		}
		
	}
	
	initialOne.setDepth(0);
	std::cout << "initial state One getDepth" << initialOne.getDepth();
	
	
	return 0;
}

