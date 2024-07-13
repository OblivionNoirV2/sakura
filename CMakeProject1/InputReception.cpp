#include "CMakeProject1.h"
#include <iostream>
#include <algorithm>


using namespace std;

void input::set_prev_and_validity(char& previous_letter, char letter, bool& is_input_valid)
{
    previous_letter = letter;
    is_input_valid = true;
};

void input::message(string msg)
{
    cout << msg << endl;

};

reception_map input::get_input() //first get user input, then compare it to default letters to ensure it is valid 
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
            letter != previous_letter 
                ? 
                set_prev_and_validity(previous_letter, letter, is_input_valid) 
                :  //remember to reset validity after the input is done 
                message("Cannot use the same letter as last turn!");     
        }
        else
        {
            message("Valid inputs are s, a, k, u, r, a");
        }

            
    }
    cout << "new prev" << letter << endl; 

    int chosen_direction; //up down left right, 1 2 3 4 

    

    reception_map placeholder; 
    return placeholder;

    
}


