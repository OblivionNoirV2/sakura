#include "CMakeProject1.h"
#include <iostream>
#include <algorithm>


using namespace std;

reception_map Input::get_input() //first get user input, then compare it to default letters to ensure it is valid 
{
    bool is_input_valid = false; 
    char letter; 
    char previous_letter = '\0'; 
    while (!is_input_valid) 
    {
        cout << "Enter a letter" << "\n"; 
        cin >> letter; 
        letter = toupper(letter); 

        //check if the letter is in the default set 
        if (find(begin(valid_letters), end(valid_letters), letter) != end(valid_letters))
        {
            cout << "found letter" << endl; 
            cout << "prev: " << previous_letter << endl;
            if (letter != previous_letter) //check if it was the prev 
            {
                previous_letter = letter;
                is_input_valid = true; //remember to reset this after the input is done 
              

            }
            else
            {
                cout << "Cannot use the same letter as last turn!" << endl; 
            }
        }
        else
        {
            cout << "Valid inputs are s, a, k, u, r, a" << '\n' << endl; 
        }

            
    }
    cout << "new prev" << letter << endl; 

    int chosen_direction; //up down left right, 1 2 3 4 

    

    reception_map placeholder; 
    return placeholder;

    
}


