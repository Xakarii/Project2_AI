#ifndef PUZZLE_H
#define PUZZLE_H

class Puzzle
{
	public:
		//int state = 1;
		int square[9] = {1,2,3,8,0,4,7,6,5};
		Puzzle();
		int getPuzzleState(int x);
		void setPuzzleState(int x, int n);
		
	//protected:
};

#endif