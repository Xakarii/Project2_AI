#include <iostream>
#include "Puzzle.h"
#include "Puzzle.cpp"
#include <list>
#include <vector>

int heuristic1(Puzzle &p, Puzzle &g);
int heuristic2(Puzzle &p, Puzzle &g);
int heuristicS(Puzzle &p, Puzzle &g);

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
	//std::cout << "Swapping: 1 and empty 0: " << std::endl;
	//p.swapPositions(1);
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
	std::cout << std::endl;
	std::cout << "initial state One getDepth() " << initialOne.getDepth() << std::endl;
	
	std::cout << "heuristic 1 h value: " << heuristic1(p, g) << std::endl;
	
	return 0;
}
//std:: vector<int> heuristicHelper(Puzzle &p, Puzzle &g, int function) {

//finds possible moves

//makes as many childeren nodes as the size of the array/vector given from possible moves

//makes the children and a vector each for them (0,0) the first number being the square moved and the second being the f(n)

//compares the children to the goal by using any of the hueristic functions 1,2,3,4,5 or 6

//if children have the same f(n) 
// 	if 2 are the same run the heuristic2Helper on both and the vector w the lowest h(n) wins (the second part of the vector)
//     if all 3 or 4 kids are the same do the same thing
//
//

//returns the best one
//makes vector with (number to be moved, the h(n) of the function)

//return vector<int>

//}
int heuristic1(Puzzle &p, Puzzle &g) {
	int hValue;
	for (int i = 0; i < 9; i++) {
		std::cout<< "p.square[i] " << p.square[i] << " g.square[i] " << g.square[i] <<  " hValue "<< hValue << std::endl;
		if (p.square[i] != g.square[i] && p.square[i] != 0) {
			hValue++;
		}
	}
	return hValue;
}

int heuristic2(Puzzle &p, Puzzle &g) {
	std::cout << "Placeholder for H2" << std::endl;
	//int tp 
	//loop until p = g
	//find possible moves
	//pick the best one (may have to check grandkids)
	//p =  "best one"
	//calculate h(n)
	//depth ++
	// tp = tp + h(n) +1(for the extra debth)
	//end loop
	//print table
}

int heuristicS(Puzzle &p, Puzzle &g) {
	std::cout << "Placeholder for S" << std::endl;
}
