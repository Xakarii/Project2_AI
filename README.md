# Expert_System
Michael Mondragon
Alex Martin
Adam McBay

Create an intelligent computer expert system for a 8-bit puzzle solving using A* Search. 

To run the program, compile and execute. The program will then prompt you to input what heuristic formula you would like to exicute and which initial state you would like to use. Then the system will dispaly a table with execution time (ET), the number of nodes generated (NG), 
the number of nodes expanded (NE), depth of the tree (D), effective branching factor b* (NG/D), and the Total path (TP). 



 void displayPuzzle()
    {
        cout << "depth = " << depth << " " << "h(n) = " << hValue << endl;
      // cout << puzzle[0] << "  " << puzzle[1] << "  " << puzzle[2] << endl; 
      //  cout << puzzle[3] << "  " << puzzle[4] << "  " << puzzle[5] << endl;
      //  cout << puzzle[6] << "  " << puzzle[7] << "  " << puzzle[8] << endl;
         for(int i =0; i< 9;i++){
            if (puzzle[i]==0)
                cout << 5;
                    
            else if (puzzle[i]==1)
                cout << 1 ;
                
            else if (puzzle[i]==2)
                cout << 2 ;
                
            else if (puzzle[i]==3)
                cout << 3 ;
            else if (puzzle[i]==4)
                cout << 8 ;
            else if (puzzle[i]==5)
                cout << 0 ;
            else if (puzzle[i]==6)
                cout << 4 ;
            else if (puzzle[i]==7)
                cout << 7 ;
            else if (puzzle[i]==8)
                cout << 6 ;
            

            if(i == 2 || i==5 || i==8) 
             cout <<    endl; 

            else
            cout << " ";        






         }  
        
        
    }
    
