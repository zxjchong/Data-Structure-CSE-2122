/* 
    File name: hw2_template.cpp
    Created by: Xiaojie Chong
    Created on: 09/13/2019
    Synopsis: This program simulate LIFE, which is an organism that lives in a discrete, two-dimensional world. There
    are several rules LIFE follows. Besides basic function, I also finish the bonus part in the hw.
*/ 

#include <iostream>
#include <cstdlib>

using namespace std;


const char ALIVE = '*';
const char DEAD = ' ';

// ATTENTION: comments in this code are hints, they don't follow
// the format discussed in lectures i.e. making the code understandable
// you should delete them and write your own comments before submitting your code

void initialization(bool **world, int nrows, int ncols);
// This function takes the point of the 2d array and its number of row and col as input, and there is a 
// for loop to get user's input for coordinates of alive cells.

void generation(bool **world, bool **copy, int nrows, int ncols);
// input parameters: original world, an array to make a copy, dimensions of the array
// This function will first store the current world into another 2d array point (copy) and to check each node in the 
// 2d array. For occupied node and empty node, there will be different rules.

void display(bool **world, int nrows, int ncols);
// prints the world to the console
// This function use a for loop to display the world


// you are free to define more functions
void bonus_generation(bool **world, bool **copy, int nrows, int ncols);
// input parameters: original world, an array to make a copy, dimensions of the array
// this function is the function used for bonus 
// While for non-bonus version, the generation will only check neighborhood node, this function will check wrap-around neighborhood
// using a mod operation to achieve this goal.

int main(int argc, char** argv){

    // Variable declarations. You can add more if necessary
    bool **world, **copy;
    int nrows, ncols;
    char next;
    int withbouns = 0;
    if(argc > 1) withbouns = 1;  // this is to check whether it is a basic version or bonus version.


    if(withbouns == 1){
        cout << "Example solution with bonus"<<endl;
    }
    cout << "Enter world dimensions (rows and columns): ";
    cin >> nrows >> ncols;    //input the size of the world

    // allocate memory for dynamic 2d-arrays 'world' and 'copy'
    /* your code here */

    // allocate two 2d array with the same size (nrows* ncols)
    world = new bool*[nrows];
    for(int i = 0; i<nrows; i++){
        world[i] = new bool[ncols];
    }

    copy = new bool*[nrows];
    for(int i = 0; i < nrows; i++){
        copy[i] = new bool[ncols];
    }


    // initialize the world and display
    initialization(world, nrows, ncols);    
    display(world, nrows, ncols);

    // prompt user input, Generation/Quit
    while (true){
        cout << "next Generation or Quit (g/q): ";
	cin >> next;
	if (next=='g' || next=='G' || next=='q' || next=='Q') 
	    break;
    }

    while (next=='g' || next=='G'){
        
        // update the world and display
        if(withbouns == 0) generation(world, copy, nrows, ncols);       // this is the generation function for basic version
        else
            bonus_generation(world, copy, nrows, ncols);    // this is the generation function for bonus version
        display(world, nrows, ncols);

	// prompt user input
        while (true){
	    cout << "next Generation or Quit (g/q): ";
	    cin >> next;
	    if (next=='g' || next=='G' || next=='q' || next=='Q') break;
	}
    }

    // deallocate memory for dynamic 2d-arrays 'world' and 'copy'
    /* your code here */

    // delete all used 2d array pointers after execution
    for (int i = 0; i < nrows; i++){
        delete[] world[i];
        delete[] copy[i];
    }
    delete[] world;
    delete[] copy;
    return 0;
}


void generation(bool **world, bool **copy, int nrows, int ncols){
	/* your code here */
    int count = 0;          // this is the variable to count alive neighborhood
    int cur_row = 0;        // this is used as an row index of neighborhood.
    int cur_col = 0;         // this is used as an cul index of neighborhood.

    // First copy the current world to **copy
    for(int i = 0; i < nrows; i++){
        for(int j = 0; j < ncols; j++){
            copy[i][j] = world[i][j];
        }
    }

    //scan all nodes 
    for(int i = 0; i < nrows; i++){
        for(int j = 0; j < ncols; j++){
            count = 0;
            for(int x = -1; x < 2; x++){        // the neighborhood for node world[i][j] is a 3*3 array (without itself)
                for(int y = -1; y < 2; y++){
                    cur_row = i + x;
                    cur_col = j + y;
                    if(cur_row >= 0 && cur_row < nrows && cur_col >= 0 && cur_col < ncols){  //this is to ensure the neighborhood doesn't exceed the edge
                        if(copy[cur_row][cur_col]){
                            count = count + 1;
                        }
                    }
                }
            }

            if(copy[i][j]){
                if(count <= 2 || count > 4){            // count how many alive neighborhood (becase we will also count the node itself during the previous loop so adjust the numbers in the ruls alittle bit)
                    world[i][j] = false;        // adjust the new alive node in the array pointed by **world
                }
            }
            else{
                if(count == 3){
                    world[i][j] = true;
                }
            }
        }
    } 
}


void initialization(bool **world, int nrows, int ncols){
    /* your code here */ 
    int nlives = 0;
    int row;
    int col;
    cout<<"Enter coordinates of alive cells: ";   // get the number of alive cells
    cin >> nlives;
    cout<<"Enter coordinates of alive cells: " << endl; //use a for loop to get the coordinates of alive cells
    for(int i = 0; i<nlives; i++){
        cin >> row;
        cin >> col;
        world[row][col] = true;
    }
}


void display(bool **world, int nrows, int ncols){
    /* your code here */
    for(int j = 0; j < ncols+2; j++){       //display the edges
        cout << "=";
    }
    cout << endl;
    for(int i = 0; i < nrows; i++){         //use a for loop to display the world
        cout << "|";
        for(int j = 0; j < ncols; j++){
            if(world[i][j]){
                cout << ALIVE;
            }
            else{
                cout << DEAD;
            }
        }
        cout << "|" << endl;
    }

    for(int j = 0; j < ncols+2; j++){
        cout << "=";
    }
    cout << endl;
}

void bonus_generation(bool **world, bool **copy, int nrows, int ncols){
    /* your code here */
    int count = 0;
    int cur_row = 0;
    int cur_col = 0;
    for(int i = 0; i < nrows; i++){
        for(int j = 0; j < ncols; j++){
            copy[i][j] = world[i][j];
        }
    }
    for(int i = 0; i < nrows; i++){
        for(int j = 0; j < ncols; j++){
            count = 0;
            for(int x = -1; x < 2; x++){
                for(int y = -1; y < 2; y++){
                    cur_row = (i + x + nrows)%nrows;        // all other parts in bonus generation is the same
                    cur_col = (j + y + ncols)%ncols;        // use a mod operation to calculate wrap-around neighborhoods.
                    if(copy[cur_row][cur_col]){
                        count = count + 1;
                    }
                }
            }

            if(copy[i][j]){
                if(count <= 2 || count > 4){
                    world[i][j] = false;
                }
            }
            else{
                if(count == 3){
                    world[i][j] = true;
                }
            }
        }
    } 
}

// More function definitions
/* your code here */
