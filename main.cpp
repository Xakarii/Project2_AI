#include <iostream>
#include "Node.h"
#include "Node.cpp"
#include <list>
#include <vector>

int heuristic1(Node &p, Node &g);
int heuristic2(Node &p, Node &g);
int heuristicS(Node &p, Node &g);
void aStarSearch(Node &initial, std::vector<Node> &open, std::vector<Node> &closed, 
				std::vector<Node> &bestPath, int heuristic);

int main(int argc, char** argv) {
	
	
	Node g = Node(1,2,3,8,0,4,7,6,5); //goal state
	Node initialOne = Node(2,8,3,1,6,4,0,7,5);
	Node initialTwo = Node(2,1,6,4,0,8,7,5,3);
	Node p = Node();
	std::vector<Node> open, closed, bestPath;
	p.printNode();
	std::cout<< std::endl << "Possible moves: ";
	p.findPossibleMoves();

	std::cout << "State at 2: "<<  p.getNodeState(2) << std::endl;
	std::cout << "p.square[4]" << p.square[4] << std::endl;
	std::cout << "Empty square is at : " << p.findEmpty() << std::endl;
	//std::cout << "Swapping: 1 and empty 0: " << std::endl;
	//p.swapPositions(1);
	std::cout << "Empty square is at : " << p.findEmpty() << std::endl;
	p.printNode();
	std::cout << "p.square[1]" << p.square[1] << std::endl;
	auto q = Node(p);
	q.printNode();
	std::cout<< std::endl << "Possible moves: ";
	q.findPossibleMoves();
	
	Node r = Node(1, 2, 3, 4, 5, 6, 7, 8, 0);
	r.printNode();
	std::cout << "Empty square is at : " << r.findEmpty() << std::endl;
	std::cout<< std::endl << "Possible moves: ";
	r.findPossibleMoves();
	r.swapPositions(8);
	r.printNode();
	std::cout<<"intial state 1: " << std::endl;
	initialOne.printNode();
	//std::cout<<"intial state 2: " << std::endl;
	//initialTwo.printNode();
	
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


int heuristic1(Node &initial,  Node &goal) { //sums all the distances by 
                                             //which the tiles are out of place, one for each square a tile must be 
 											 // moved to reach its position in the goal state.
	int hValue=0;
	for (int j =0; j<8 ; j++){
		switch(j){
			
		case 0: //square 1 check
			if (initial.square[j]==2 || initial.square[j]==8 )
				hValue = hValue+1;
			if (initial.square[j]==3 || initial.square[j]==7 || initial.square[j]==0 )
				hValue = hValue+2;
			if (initial.square[j]==4 || initial.square[j]==6)
				hValue = hValue+3;
			if (initial.square[j]==5)
				hValue = hValue+4;
				
		break;

		case 1: //square 2 check
			if (initial.square[j]==1 || initial.square[j]==3 || initial.square[j]==0 )
				hValue = hValue+1;
			if (initial.square[j]==6 || initial.square[j]==8 || initial.square[j]==4 )
				hValue = hValue+2;
			if (initial.square[j]==5 || initial.square[j]==7)
				hValue = hValue+3;

		break;

		case 2: //square 3 check
			if (initial.square[j]==2 || initial.square[j]==4)
				hValue = hValue+1;
			if (initial.square[j]==1 || initial.square[j]==0 || initial.square[j]==5 )
				hValue = hValue+2;
			if (initial.square[j]==8 || initial.square[j]==6)
				hValue = hValue+3;
			if (initial.square[j]==7)
				hValue = hValue+4;

		break;

		case 5: //square 4 check
			if (initial.square[j]==3 || initial.square[j]==5 || initial.square[j]==0)
				hValue = hValue+1;
			if (initial.square[j]==8 || initial.square[j]==2 || initial.square[j]==6 )
				hValue = hValue+2;
			if (initial.square[j]==1 || initial.square[j]==7)
				hValue = hValue+3;
		
		break;

		case 8: //square 5 check
			if (initial.square[j]==6 || initial.square[j]==4)
				hValue = hValue+1;
			if (initial.square[j]==7 || initial.square[j]==3 || initial.square[j]==0 )
				hValue = hValue+2;
			if (initial.square[j]==8 || initial.square[j]==2)
				hValue = hValue+3;
			if (initial.square[j]==1)
				hValue = hValue+4;
		break;

		case 7: //square 6 check
			if (initial.square[j]==5 || initial.square[j]==7 || initial.square[j]==0 )
				hValue = hValue+1;
			if (initial.square[j]==2 || initial.square[j]==8 || initial.square[j]==4 )
				hValue = hValue+2;
			if (initial.square[j]==1 || initial.square[j]==3)
				hValue = hValue+3;

		break;

		case 6: //square 7 check
			if (initial.square[j]==8 || initial.square[j]==6)
				hValue = hValue+1;
			if (initial.square[j]==1 || initial.square[j]==5 || initial.square[j]==0 )
				hValue = hValue+2;
			if (initial.square[j]==2 || initial.square[j]==4)
				hValue = hValue+3;
			if (initial.square[j]==3)
				hValue = hValue+4;

		break;

		case 3: //square 8 check
			if (initial.square[j]==1 || initial.square[j]==7 || initial.square[j]==0)
				hValue = hValue+1;
			if (initial.square[j]==4 || initial.square[j]==2 || initial.square[j]==6 )
				hValue = hValue+2;
			if (initial.square[j]==3 || initial.square[j]==5)
				hValue = hValue+3;

		break;

		case 4: //square 9 check
			if (initial.square[j]==2 || initial.square[j]==4 || initial.square[j]==8 || initial.square[j]==6)
				hValue = hValue+1;
			if (initial.square[j]==1 || initial.square[j]==3 || initial.square[j]==5 || initial.square[j]==7 )
				hValue = hValue+2;
		break;
			}
		}	
	return hValue;
}


int heuristic2(Node &initial,  Node &goal) { //counts the tiles out of place in each state when it is compared with the goal.

	int hValue=0;
	for (int j =0; j<8 ; j++){
		if(initial.square[j]!=goal.square[j])
			hValue++;
		}	
	return hValue;
}


int heuristic3(Node &initial,  Node &goal) { // by checking around the non-central 
//squares in turn, allotting 2 for every tile not followed by its proper 
//successor and allotting 0 for every other tile; a piece in the center 
//scores one.
	int hValue=0;
	for (int j =0; j<8 ; j++){
		switch(j){
			
		case 0:
		 if (initial.square[0]==1 && initial.square[4]!=8)
		 	hValue=hValue+2;
		 if (initial.square[0]==2 || initial.square[0]==3 || initial.square[0]==4 || initial.square[0]==5 || initial.square[0]==6
		 	|| initial.square[0]==7|| initial.square[0]==8)
			 if( (initial.square[0] - initial.square[4]) != 1)
			hValue=hValue+2;
		break;

		case 1: //square 2 check
		if (initial.square[1]==1 && initial.square[0]!=8)
		 	hValue=hValue+2;
		if (initial.square[1]==2 || initial.square[1]==3 || initial.square[1]==4 || initial.square[1]==5 || initial.square[1]==6
		 	|| initial.square[1]==7|| initial.square[1]==8)
			 if( (initial.square[1] - initial.square[0]) != 1)
			hValue=hValue+2;
		break;

		case 2:
		if (initial.square[j]==1 && initial.square[1]!=8)
		 	hValue=hValue+2;
		if (initial.square[j]==2 || initial.square[j]==3 || initial.square[j]==4 || initial.square[j]==5 || initial.square[j]==6
		 	|| initial.square[j]==7|| initial.square[j]==8)
			 if( (initial.square[j] - initial.square[1]) != 1)
			hValue=hValue+2;
		break;

		case 5:
		if (initial.square[j]==1 && initial.square[2]!=8)
		 	hValue=hValue+2;
		if (initial.square[j]==2 || initial.square[j]==3 || initial.square[j]==4 || initial.square[j]==5 || initial.square[j]==6
		 	|| initial.square[j]==7|| initial.square[j]==8)
			 if( (initial.square[j] - initial.square[2]) != 1)
			hValue=hValue+2;	
		break;

		case 8:
		if (initial.square[j]==1 && initial.square[5]!=8)
		 	hValue=hValue+2;
		if (initial.square[j]==2 || initial.square[j]==3 || initial.square[j]==4 || initial.square[j]==5 || initial.square[j]==6
		 	|| initial.square[j]==7|| initial.square[j]==8)
			 if( (initial.square[j] - initial.square[5]) != 1)
			hValue=hValue+2;	
		break;

		case 7:
		if (initial.square[j]==1 && initial.square[8]!=8)
		 	hValue=hValue+2;
		if (initial.square[j]==2 || initial.square[j]==3 || initial.square[j]==4 || initial.square[j]==5 || initial.square[j]==6
		 	|| initial.square[j]==7|| initial.square[j]==8)
			 if( (initial.square[j] - initial.square[8]) != 1)
			hValue=hValue+2;	
		break;

		case 6:
		if (initial.square[j]==1 && initial.square[7]!=8)
		 	hValue=hValue+2;
		if (initial.square[j]==2 || initial.square[j]==3 || initial.square[j]==4 || initial.square[j]==5 || initial.square[j]==6
		 	|| initial.square[j]==7|| initial.square[j]==8)
			 if( (initial.square[j] - initial.square[7]) != 1)
			hValue=hValue+2;	
		break;

		case 3:
		if (initial.square[j]==1 && initial.square[6]!=8)
		 	hValue=hValue+2;
		if (initial.square[j]==2 || initial.square[j]==3 || initial.square[j]==4 || initial.square[j]==5 || initial.square[j]==6
		 	|| initial.square[j]==7|| initial.square[j]==8)
			 if( (initial.square[j] - initial.square[6]) != 1)
			hValue=hValue+2;			
		break;

			}
		}	
	return hValue;
}


//passing vector for initial node
void aStarSearch(Node &initial, std::vector<Node> &open, std::vector<Node> &closed, 
	std::vector<Node> &bestPath, int heuristic) {
	std::cout << "placeholder for A* search algo" << std::endl; 
	//find h and f value of p and expand possible moves, swap each possible 
	//with empty (0) square and create a new node for each
	initial.findPossibleMoves();
	
	
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
