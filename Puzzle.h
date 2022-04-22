#ifndef PUZZLE_H
#define PUZZLE_H

class Puzzle
{
	public:
		//int state = 1;
		int square[9] = {1,2,3, 8,0,4, 7,6,5};
		int depth = 0;  //depth of node, increment with setDepth when creating a new puzzle node
		Puzzle();
		Puzzle(int a, int b, int c, int d, int e, int f, int g, int h, int i);
		Puzzle(const Puzzle &p);
		//possible moves initialized to -1 to signify no possible moves
		//if possible moves found by member function, set these to indexes
		//that can swap with empty square
		int possibleMoves [4] = {-1,-1,-1,-1};
		
		
		void setDepth(int d);
		int getDepth();
		int getPuzzleState(int x);
		void setPuzzleState(int x, int n);
		void swapPositions(int swapped);
		int calcAdjacent(int square1, int square2);
		int findEmpty();
		void printPuzzle();
		void findPossibleMoves();
	//protected:
};

#endif