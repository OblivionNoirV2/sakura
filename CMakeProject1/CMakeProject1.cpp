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
    std::vector<char> remaining_letters;

protected:
    const char default_letters[6] =
    {
        'S', 'A', 'K', 'U', 'R', 'A'
    };

public:

    void reinitialize()
    {
        // Clear the remaining_letters vector of any existing members
        remaining_letters.clear();
        // Copy the contents of default_letters into remaining_letters
        remaining_letters.insert(remaining_letters.end(), default_letters, default_letters + 6);
    };
};


/*class Input
{

public: 
    struct given_input
    {
        char chosen_letter;
        bool chosen_direction; //t for left, f for right 
    }; 
    
    char guess_letter() //returns player guess. players cannot see remaining letters, part of the logic game 
    {

    };
  
};*/





int main()
{
    Sorting sorting;
    sorting.reinitialize();

    for (char c : sorting.remaining_letters)
    {
        std::cout << c << "\n";
    }
    sorting.reinitialize();
    //Input input;
    //char guessedLetter = input.guess_letter();
    //std::cout << "Guessed Letter: " << guessedLetter << "\n";

    return 0;
}