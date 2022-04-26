#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

const int goal_state[9] = {1,2,3,8,0,4,5,6,7};

int hueristic1(int puzzle[9]);
int hueristic2(int puzzle[9]);
int hueristic3(int puzzle[9]);
int hueristic4(int puzzle[9]);
int hueristic5(int puzzle[9]);
int hueristic6(int puzzle[9]);

class Node
{
public:  
    Node(int puzzle[9], int index, int hValue, int depth, int fValue, Node* parent) //constructor
    {
        for (int i = 0; i < 9; i++)
        {
            this->puzzle[i] = puzzle[i];
        }
        this->index = index;
        this->hValue = hValue;
        this->depth = depth;
        this->fValue = fValue;
        this->parent = parent;
    }


    void displayPuzzle()
    {
        cout << "g(n) = " << depth << " " << "h(n) = " << hValue << endl;
        cout << puzzle[0] << "  " << puzzle[1] << "  " << puzzle[2] << endl;
        cout << puzzle[3] << "  " << puzzle[4] << "  " << puzzle[5] << endl;
        cout << puzzle[6] << "  " << puzzle[7] << "  " << puzzle[8] << endl;
    }

    Node* moveUp(int heuristic) //return new state to add to queue
    {
        Node* statetoAdd;

        int x = index % 3;
        int y = index / 3;
        int new_y = y - 1;
        int new_puzzle[9];

        for (int i = 0; i < 9; i++) //copy over puzzle
        {
            new_puzzle[i] = this->puzzle[i];
        }

        int new_blank = x + (new_y * 3);
        int temp = new_puzzle[this->index];
        new_puzzle[this->index] = new_puzzle[new_blank];
        new_puzzle[new_blank] = temp;

        int new_hValue = 0;
        if (heuristic == 1) 
        {
            new_hValue = hueristic1(new_puzzle);
        }
        if (heuristic == 2)
        {
            new_hValue = hueristic2(new_puzzle);
        }
        if (heuristic == 3)
        {
            new_hValue = hueristic3(new_puzzle);
        }
        if (heuristic == 4)
        {
            new_hValue = hueristic4(new_puzzle);
        }
        if (heuristic == 5)
        {
            new_hValue = hueristic5(new_puzzle);
        }
        if (heuristic == 6)
        {
            new_hValue = hueristic6(new_puzzle);
        }

        int new_gn = this->depth + 1;
        int new_fn = new_gn + new_hValue;

        statetoAdd = new Node(new_puzzle, new_blank, new_hValue, new_gn, new_fn, this);

        //cout << "New state up: " << endl; 
        //statetoAdd->displayPuzzle();

        return statetoAdd;
    }

    Node* moveDown(int heuristic)
    {
        Node* statetoAdd;

        int x = index % 3;
        int y = index / 3;
        int new_y = y + 1;
        int new_puzzle[9];

        for (int i = 0; i < 9; i++) //copy over puzzle
        {
            new_puzzle[i] = this->puzzle[i];
        }

        int new_blank = x + (new_y * 3);
        int temp = new_puzzle[this->index];
        new_puzzle[this->index] = new_puzzle[new_blank];
        new_puzzle[new_blank] = temp;

        int new_hValue = 0;
        if (heuristic == 1)
        {
            new_hValue = hueristic1(new_puzzle);
        }
        if (heuristic == 2)
        {
            new_hValue = hueristic2(new_puzzle);
        }
        if (heuristic == 3)
        {
            new_hValue = hueristic3(new_puzzle);
        }
        if (heuristic == 4)
        {
            new_hValue = hueristic4(new_puzzle);
        }
        if (heuristic == 5)
        {
            new_hValue = hueristic5(new_puzzle);
        }
        if (heuristic == 6)
        {
            new_hValue = hueristic6(new_puzzle);
        }

        int new_gn = this->depth + 1;
        int new_fn = new_gn + new_hValue;

        statetoAdd = new Node(new_puzzle, new_blank, new_hValue, new_gn, new_fn, this);

        //cout << "New state down: " << endl; 
        //statetoAdd->displayPuzzle();

        return statetoAdd;
    }

    Node* moveLeft(int heuristic)
    {

        Node* statetoAdd;

        int x = index % 3;
        int y = index / 3;
        int new_x = x - 1;
        int new_puzzle[9];

        for (int i = 0; i < 9; i++) //copy over puzzle
        {
            new_puzzle[i] = this->puzzle[i];
        }

        int new_blank = new_x + (y * 3);
        int temp = new_puzzle[this->index];
        new_puzzle[this->index] = new_puzzle[new_blank];
        new_puzzle[new_blank] = temp;

        int new_hValue = 0;
        if (heuristic == 1)
        {
            new_hValue = hueristic1(new_puzzle);
        }
        if (heuristic == 2)
        {
            new_hValue = hueristic2(new_puzzle);
        }
        if (heuristic == 3)
        {
            new_hValue = hueristic3(new_puzzle);
        }
        if (heuristic == 4)
        {
            new_hValue = hueristic4(new_puzzle);
        }
        if (heuristic == 5)
        {
            new_hValue = hueristic5(new_puzzle);
        }
        if (heuristic == 6)
        {
            new_hValue = hueristic6(new_puzzle);
        }

        int new_gn = this->depth + 1;
        int new_fn = new_gn + new_hValue;

        statetoAdd = new Node(new_puzzle, new_blank, new_hValue, new_gn, new_fn, this);

        //cout << "New state left: " << endl; 
        //statetoAdd->displayPuzzle();

        return statetoAdd;
    }

    Node* moveRight(int heuristic)
    {
        Node* statetoAdd;

        int x = index % 3;
        int y = index / 3;
        int new_x = x + 1;
        int new_puzzle[9];

        for (int i = 0; i < 9; i++) //copy over puzzle
        {
            new_puzzle[i] = this->puzzle[i];
        }

        int new_blank = new_x + (y * 3);
        int temp = new_puzzle[this->index];
        new_puzzle[this->index] = new_puzzle[new_blank];
        new_puzzle[new_blank] = temp;

        int new_hValue = 0;
        if (heuristic == 1)
        {
            new_hValue = hueristic1(new_puzzle);
        }
        if (heuristic == 2)
        {
            new_hValue = hueristic2(new_puzzle);
        }
        if (heuristic == 3)
        {
            new_hValue = hueristic3(new_puzzle);
        }
        if (heuristic == 4)
        {
            new_hValue = hueristic4(new_puzzle);
        }
        if (heuristic == 5)
        {
            new_hValue = hueristic5(new_puzzle);
        }
        if (heuristic == 6)
        {
            new_hValue = hueristic6(new_puzzle);
        }

        int new_gn = this->depth + 1;
        int new_fn = new_gn + new_hValue;

        statetoAdd = new Node(new_puzzle, new_blank, new_hValue, new_gn, new_fn, this);

        //cout << "New state right: " << endl; 
        //statetoAdd->displayPuzzle();

        return statetoAdd;
    }

    //State variables, make public for now so don't have to deal with get
    Node* parent;
    int puzzle[9];
    int index;
    int hValue;
    int depth;
    int fValue;
};

class compareState //compare function for priority queue
{
public:
    int operator() (Node* state1, Node* state2)
    {
        return state1->fValue > state2->fValue;
    }
};

int hueristic1(int puzzle[9])
{

    
    int hValue = 0;
    for (int i = 0; i < 9; i++)
    {
        if (puzzle[i] != (i + 1) % 9 && puzzle[i] != 0)
        {
            ++hValue;
        }

    }
    //cout << "num misplaced tile test " << hValue << endl;
    return hValue;
    
}
int hueristic2(int puzzle[9]) 
{
 
    int hValue = 0;
    for (int j = 0; j < 8; j++) {
        switch (j) {

        case 0: //square 1 check
            if (puzzle[j] == 2 || puzzle[j] == 8)
                hValue = hValue + 1;
            if (puzzle[j] == 3 || puzzle[j] == 7)
                hValue = hValue + 2;
            if (puzzle[j] == 4 || puzzle[j] == 6)
                hValue = hValue + 3;
            if (puzzle[j] == 5)
                hValue = hValue + 4;

            break;

        case 1: //square 2 check
            if (puzzle[j] == 1 || puzzle[j] == 3)
                hValue = hValue + 1;
            if (puzzle[j] == 6 || puzzle[j] == 8 || puzzle[j] == 4)
                hValue = hValue + 2;
            if (puzzle[j] == 5 || puzzle[j] == 7)
                hValue = hValue + 3;

            break;

        case 2: //square 3 check
            if (puzzle[j] == 2 || puzzle[j] == 4)
                hValue = hValue + 1;
            if (puzzle[j] == 1 || puzzle[j] == 5)
                hValue = hValue + 2;
            if (puzzle[j] == 8 || puzzle[j] == 6)
                hValue = hValue + 3;
            if (puzzle[j] == 7)
                hValue = hValue + 4;

            break;

        case 5: //square 4 check
            if (puzzle[j] == 3 || puzzle[j] == 5)
                hValue = hValue + 1;
            if (puzzle[j] == 8 || puzzle[j] == 2 || puzzle[j] == 6)
                hValue = hValue + 2;
            if (puzzle[j] == 1 || puzzle[j] == 7)
                hValue = hValue + 3;

            break;

        case 8: //square 5 check
            if (puzzle[j] == 6 || puzzle[j] == 4)
                hValue = hValue + 1;
            if (puzzle[j] == 7 || puzzle[j] == 3)
                hValue = hValue + 2;
            if (puzzle[j] == 8 || puzzle[j] == 2)
                hValue = hValue + 3;
            if (puzzle[j] == 1)
                hValue = hValue + 4;
            break;

        case 7: //square 6 check
            if (puzzle[j] == 5 || puzzle[j] == 7)
                hValue = hValue + 1;
            if (puzzle[j] == 2 || puzzle[j] == 8 || puzzle[j] == 4)
                hValue = hValue + 2;
            if (puzzle[j] == 1 || puzzle[j] == 3)
                hValue = hValue + 3;

            break;

        case 6: //square 7 check
            if (puzzle[j] == 8 || puzzle[j] == 6)
                hValue = hValue + 1;
            if (puzzle[j] == 1 || puzzle[j] == 5)
                hValue = hValue + 2;
            if (puzzle[j] == 2 || puzzle[j] == 4)
                hValue = hValue + 3;
            if (puzzle[j] == 3)
                hValue = hValue + 4;

            break;

        case 3: //square 8 check
            if (puzzle[j] == 1 || puzzle[j] == 7)
                hValue = hValue + 1;
            if (puzzle[j] == 4 || puzzle[j] == 2 || puzzle[j] == 6)
                hValue = hValue + 2;
            if (puzzle[j] == 3 || puzzle[j] == 5)
                hValue = hValue + 3;

            break;

        case 4: //square 9 check 
            if (puzzle[j] == 2 || puzzle[j] == 4 || puzzle[j] == 8 || puzzle[j] == 6)
                hValue = hValue + 1;
            if (puzzle[j] == 1 || puzzle[j] == 3 || puzzle[j] == 5 || puzzle[j] == 7)
                hValue = hValue + 2;
            break;
        }
    }
    return hValue;
}

int hueristic3(int puzzle[9])
{
    int hValue = 0;
    for (int j = 0; j < 8; j++) {
        switch (j) {

        case 0:
            if (puzzle[0] == 1 && puzzle[4] != 8)
                hValue = hValue + 2;
            if (puzzle[0] == 2 || puzzle[0] == 3 || puzzle[0] == 4 || puzzle[0] == 5 || puzzle[0] == 6
                || puzzle[0] == 7 || puzzle[0] == 8)
                if ((puzzle[0] - puzzle[4]) != 1)
                    hValue = hValue + 2;
            break;

        case 1: //square 2 check
            if (puzzle[1] == 1 && puzzle[0] != 8)
                hValue = hValue + 2;
            if (puzzle[1] == 2 || puzzle[1] == 3 || puzzle[1] == 4 || puzzle[1] == 5 || puzzle[1] == 6
                || puzzle[1] == 7 || puzzle[1] == 8)
                if ((puzzle[1] - puzzle[0]) != 1)
                    hValue = hValue + 2;
            break;

        case 2:
            if (puzzle[j] == 1 && puzzle[1] != 8)
                hValue = hValue + 2;
            if (puzzle[j] == 2 || puzzle[j] == 3 || puzzle[j] == 4 || puzzle[j] == 5 || puzzle[j] == 6
                || puzzle[j] == 7 || puzzle[j] == 8)
                if ((puzzle[j] - puzzle[1]) != 1)
                    hValue = hValue + 2;
            break;

        case 5:
            if (puzzle[j] == 1 && puzzle[2] != 8)
                hValue = hValue + 2;
            if (puzzle[j] == 2 || puzzle[j] == 3 || puzzle[j] == 4 || puzzle[j] == 5 || puzzle[j] == 6
                || puzzle[j] == 7 || puzzle[j] == 8)
                if ((puzzle[j] - puzzle[2]) != 1)
                    hValue = hValue + 2;
            break;

        case 8:
            if (puzzle[j] == 1 && puzzle[5] != 8)
                hValue = hValue + 2;
            if (puzzle[j] == 2 || puzzle[j] == 3 || puzzle[j] == 4 || puzzle[j] == 5 || puzzle[j] == 6
                || puzzle[j] == 7 || puzzle[j] == 8)
                if ((puzzle[j] - puzzle[5]) != 1)
                    hValue = hValue + 2;
            break;

        case 7:
            if (puzzle[j] == 1 && puzzle[8] != 8)
                hValue = hValue + 2;
            if (puzzle[j] == 2 || puzzle[j] == 3 || puzzle[j] == 4 || puzzle[j] == 5 || puzzle[j] == 6
                || puzzle[j] == 7 || puzzle[j] == 8)
                if ((puzzle[j] - puzzle[8]) != 1)
                    hValue = hValue + 2;
            break;

        case 6:
            if (puzzle[j] == 1 && puzzle[7] != 8)
                hValue = hValue + 2;
            if (puzzle[j] == 2 || puzzle[j] == 3 || puzzle[j] == 4 || puzzle[j] == 5 || puzzle[j] == 6
                || puzzle[j] == 7 || puzzle[j] == 8)
                if ((puzzle[j] - puzzle[7]) != 1)
                    hValue = hValue + 2;
            break;

        case 3:
            if (puzzle[j] == 1 && puzzle[6] != 8)
                hValue = hValue + 2;
            if (puzzle[j] == 2 || puzzle[j] == 3 || puzzle[j] == 4 || puzzle[j] == 5 || puzzle[j] == 6
                || puzzle[j] == 7 || puzzle[j] == 8)
                if ((puzzle[j] - puzzle[6]) != 1)
                    hValue = hValue + 2;
            break;
        case 4:
            if (puzzle[j] != 0)
                hValue = hValue + 1;
            break;
        }
    }
    return hValue;

}


int hueristic4(int puzzle[9]) { //corners out of place = +1, blank square out of place =+0, others out of place =+2

    int hValue = 0;
    int i = 0;
    if (puzzle)

    if (puzzle[i] != 1)
        hValue = hValue + 1;
    if (puzzle[i+2] != 3)
        hValue = hValue + 1;
    if (puzzle[i+6] != 7)
        hValue = hValue + 1;
    if (puzzle[i+8] != 5)
        hValue = hValue + 1;

    if (puzzle[i] == 0 || puzzle[i+2] == 0 || puzzle[i+6] == 0 || puzzle[i+8] == 0)
        hValue = hValue - 1;

    if (puzzle[i+4] != 0)
        hValue = hValue + 1;
    if (puzzle[i+1] != 2)
        hValue = hValue + 2;
    if (puzzle[i+3] != 8)
        hValue = hValue + 2;
    if (puzzle[i+5] != 4)
        hValue = hValue + 2;
    if (puzzle[i+7] != 6)
        hValue = hValue + 2;
    if (puzzle[i+4] == 0 || puzzle[i+1] == 0 || puzzle[i+3] == 0 || puzzle[i+5] == 0 || puzzle[i+7] == 0)
        hValue = hValue - 2;

    return hValue;
}

int hueristic5(int puzzle[9]) { //right place +0 right row +1 right collum +1 wrong row +2 wrong collum +2

    int hValue = 0;

    for (int j = 0; j < 8; j++) {
        if (puzzle[j] != 0)
            switch (j) {

            case 0:

                if (puzzle[j] == 1)
                    break;

                if (puzzle[1] == 1 || puzzle[2] == 1)
                    hValue = hValue + 1;
                else
                    hValue = hValue + 2;
                if (puzzle[1] == 3 || puzzle[6] == 1)
                    hValue = hValue + 1;
                else
                    hValue = hValue + 2;
                break;

            case 1: //square 2 check
                if (puzzle[j] == 2)
                    break;
                if (puzzle[0] == 2 || puzzle[2] == 2)
                    hValue = hValue + 1;
                else
                    hValue = hValue + 2;
                if (puzzle[4] == 2 || puzzle[7] == 2)
                    hValue = hValue + 1;
                else
                    hValue = hValue + 2;
                break;

            case 2:
                if (puzzle[j] == 3)
                    break;
                if (puzzle[1] == 3 || puzzle[0] == 3)
                    hValue = hValue + 1;
                else
                    hValue = hValue + 2;
                if (puzzle[5] == 3 || puzzle[8] == 3)
                    hValue = hValue + 1;
                else
                    hValue = hValue + 2;
                break;

            case 5:
                if (puzzle[j] == 4)
                    break;
                if (puzzle[3] == 4 || puzzle[4] == 4)
                    hValue = hValue + 1;
                else
                    hValue = hValue + 2;
                if (puzzle[2] == 4 || puzzle[8] == 4)
                    hValue = hValue + 1;
                else
                    hValue = hValue + 2;
                break;

            case 8:
                if (puzzle[j] == 5)
                    break;
                if (puzzle[6] == 5 || puzzle[7] == 5)
                    hValue = hValue + 1;
                else
                    hValue = hValue + 2;
                if (puzzle[2] == 5 || puzzle[5] == 5)
                    hValue = hValue + 1;
                else
                    hValue = hValue + 2;
                break;

            case 7:
                if (puzzle[j] == 6)
                    break;
                if (puzzle[8] == 6 || puzzle[6] == 6)
                    hValue = hValue + 1;
                else
                    hValue = hValue + 2;
                if (puzzle[1] == 6 || puzzle[4] == 6)
                    hValue = hValue + 1;
                else
                    hValue = hValue + 2;
                break;

            case 6:
                if (puzzle[j] == 7)
                    break;
                if (puzzle[0] == 7 || puzzle[3] == 7)
                    hValue = hValue + 1;
                else
                    hValue = hValue + 2;
                if (puzzle[7] == 7 || puzzle[8] == 7)
                    hValue = hValue + 1;
                else
                    hValue = hValue + 2;
                break;

            case 3:
                if (puzzle[j] == 8)
                    break;
                if (puzzle[0] == 8 || puzzle[6] == 8)
                    hValue = hValue + 1;
                else
                    hValue = hValue + 2;
                if (puzzle[4] == 8 || puzzle[4] == 8)
                    hValue = hValue + 1;
                else
                    hValue = hValue + 2;
                break;
            }
    }
    return hValue;
}

/*n-MaxSwap
assumes you can swap any tile with the "space".
Use the number of steps it takes to solve as h value
Will be ineffective as it the algo used doesnt accommodate
these assumptions
*/
int hueristic6(int puzzle[9]) {
    
    
    
    int hValue = 0;

    if (puzzle[0] != 1)
        hValue = hValue + 1;
    if (puzzle[1] != 2)
        hValue = hValue + 1;
    if (puzzle[2] != 3)
        hValue = hValue + 1;
    if (puzzle[3] != 8)
        hValue = hValue + 1;
    if (puzzle[4] != 0)
        hValue = hValue + 1;
    if (puzzle[5] != 4)
        hValue = hValue + 1;
    if (puzzle[6] != 7)
        hValue = hValue + 1;
    if (puzzle[7] != 6)
        hValue = hValue + 1;
    if (puzzle[8] != 5)
        hValue = hValue + 1;
    return hValue;
}

void aStarSearch(Node* initialstate, int hchoice)
{

    int nodes_expanded = 0;
    int node_gen = 0;
    int heuristic = hchoice;

    priority_queue <Node*, vector<Node*>, compareState > pq;

    Node* currNode;

    pq.push(initialstate);

    while (pq.size() != 0)
    {
        if (pq.size() > node_gen) //updates generated nodes
        {
            node_gen = pq.size();
        }

        currNode = pq.top();
        pq.pop();
     

        for (int i = 0; i < 9; i++) //check for goal state
        {
            if (currNode->puzzle[i] != goal_state[i])
            {
                
                break;
            }
            else if ((currNode->puzzle[i] == goal_state[i]) && (i == 8))
            {
                cout << "Generated Nodes: " << node_gen << endl;
                cout << "Nodes Expanded: " << nodes_expanded << endl;
                cout << "Puzzle Solved!" << endl;
                currNode->displayPuzzle();
                return;
            }
        }

        cout << "Expanding state " << endl;
        currNode->displayPuzzle();
        nodes_expanded += 1; //expanding state, update count

        // check where blank is and determine what operators are possible
        // add those states to priority queue
        if (currNode->index != 0 && currNode->index != 1 && currNode->index != 2)
        {
            pq.push(currNode->moveUp(heuristic));
        }
        if (currNode->index != 6 && currNode->index != 7 && currNode->index != 8)
        {
            pq.push(currNode->moveDown(heuristic));
        }
        if (currNode->index != 0 && currNode->index != 3 && currNode->index != 6)
        {
            pq.push(currNode->moveLeft(heuristic));
        }
        if (currNode->index != 2 && currNode->index != 5 && currNode->index != 8)
        {
            pq.push(currNode->moveRight(heuristic));
        }

    }

    cout << "No solution found!" << endl;
}

int main()
{
    //int userPuzzle[9];
    //int goal_state[9] = { 1,2,3,8,0,4,5,6,7 };
    int initialstate[9] = {1,2,3,4,8,0,7,6,5}; //TESTIN
    int hueristicpicker;
    int index;

    

    for (int i = 0; i < 9; i++)
    {
        if (initialstate[i] == 0)
        {
            index = i;
        }
    }



    cout << "Enter algorithm choice: " << endl;
    cout << "   Enter \"1\" Hueristic 1" << endl;
    cout << "   Enter \"2\" Heuristic 2" << endl;
    cout << "   Enter \"3\" Heuristic 3" << endl;
    cout << "   Enter \"4\" Heuristic 4" << endl;
    cout << "   Enter \"5\" Heuristic 5" << endl;
    cout << "   Enter \"6\" Heuristic 6" << endl;

    cin >> hueristicpicker;

    Node* problem = new Node(initialstate, index, 0, 0, 0, 0);

    if (hueristicpicker == 2)
    {
        problem->hValue = hueristic2(problem->puzzle);
    }
    if (hueristicpicker == 3)
    {
        problem->hValue = hueristic3(problem->puzzle);
    }
    if (hueristicpicker == 4)
    {
        problem->hValue = hueristic4(problem->puzzle);
    }
    if (hueristicpicker == 5)
    {
        problem->hValue = hueristic5(problem->puzzle);
    }
    if (hueristicpicker == 6)
    {
        problem->hValue = hueristic6(problem->puzzle);
    }


    aStarSearch(problem, hueristicpicker);


    return 0;
}