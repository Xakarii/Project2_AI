#include <iostream>
#include "Puzzle.h"
#include "Puzzle.cpp"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	Puzzle p = Puzzle();
	std::cout << "State at x: "<<  p.getPuzzleState(2) << std::endl;
	std::cout << p.square[4];
	return 0;
}