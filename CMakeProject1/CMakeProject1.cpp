// CMakeProject1.cpp : Defines the entry point for the application.
//

#include "CMakeProject1.h"
#include <vector>
#include <algorithm> // For std::copy
#include <iostream>
using namespace std;

//SAKURA 
//S -> A
//A -> S or K or R
//K -> A or U 
//U -> K or R 
//R -> U or A 
//A -> S or K or R

//given letter 
//choose which letter goes right or left 
//anything that has already been chosen correctly will be ruled out of the potential letters given 
//segments (ie SA) will be stored and linked together



class Sorting
{
public:


    void reinitialize() //reset the grid 
    {
        //fill coordinates with x 

    };
};




int main()
{
    
    Sorting sorting;
    sorting.reinitialize();

    //sorting.reinitialize();
    Input input;
    reception_map recieved_input = input.get_input(); //this will be a hash with the chosen char and direction to place it 
    //std::cout << "Guessed Letter: " << guessedLetter << "\n";

    return 0;
}