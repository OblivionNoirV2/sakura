#include "CMakeProject1.h"
#include <iostream>
#include <algorithm>


using namespace std;

//this will actually return a char and a bool (left or right) in map form, not just a char 
map<bool, char> Input::get_input() //first get user input, then compare it to default letters to ensure it is valid 
{
    bool is_input_valid = false; 
    char letter; 

    while (!is_input_valid) 
    {
        cout << "Enter a letter" << "\n"; 
        cin >> letter; 
        letter = toupper(letter); 

        //check if the letter is in the default set 
        if (find(begin(default_letters), end(default_letters), letter) != end(default_letters))
        {
            cout << "found letter" << endl; 
            is_input_valid = true; 
        }


    }

    bool chosen_direction; //true for left, false for right

    

    map<bool, char> placeholder; 
    return placeholder;

    
}


