#include "CMakeProject1.h"
#include <iostream>
#include <algorithm>

using namespace std;

//this will actually return a char and a bool (left or right) in hash form, not just a char 
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

    bool chosen_direction; //true for left, false for right

    

 
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

