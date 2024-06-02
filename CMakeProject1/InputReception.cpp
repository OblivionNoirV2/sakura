#include "CMakeProject1.h"
#include <iostream>

using namespace std;

char Input::get_input() //first get user input, then compare it to default letters to ensure it is valid 
{
    bool is_input_valid = false; 
    char letter; 

    while (!is_input_valid) 
    {
        cout << "Enter a letter" << "\n"; 
        cin >> letter; 
        letter = toupper(letter); 

        //check if the letter is in the default set 


    }
    


    return 'b';

    
   
   
}

/*
class Input
{
public:
    struct given_input
    {
        char chosen_letter;
        bool chosen_direction; // true for left, false for right
    };

    char guess_letter()// returns player guess. players cannot see remaining letters, part of the logic game
    {
        return 'a';
    }
};
*/

