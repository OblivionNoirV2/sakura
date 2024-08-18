#include "CMakeProject1.h"
#include <iostream>
#include <algorithm>


using namespace std;

void input::set_prev_letter(char& previous_letter, char letter)
{
    previous_letter = letter;

    //is_input_valid = true;
};

void input::message(string msg)
{
    cout << msg << endl;

};

void up_input(char& txt) //global
{
    txt = toupper(txt);
}; 

//default values, cannot be in the function or they'll get reset every time
char previous_letter = '\0';
char previous_direction = '\0';

reception_map input::get_input() //first get user input, then compare it to default letters to ensure it is valid 
{
    bool is_letter_valid = false;
    bool is_direction_valid = false; 

    char letter; 
    char direction; 

    while (!is_letter_valid) 
    {
        message("Enter a letter"); 

        cin >> letter; 

        up_input(letter);

        //check if the letter is in the default set 
        if (find(begin(valid_letters), end(valid_letters), letter) != end(valid_letters))
        {
            cout << "found letter" << endl; 
            cout << "prev: " << previous_letter << endl;
            if (letter != previous_letter)
            {
                set_prev_letter(previous_letter, letter);
                is_letter_valid = true;

            }
            else
            {
                message("Cannot use the same letter as last turn!");

            };
        }
        else
        {
            message("Valid inputs are s, a, k, u, r, a");
        }
    }
    cout << "new prev" << letter << endl; 
    //get_input(); //proves that letter tracking works

    //now that that's validated get the direction 
    while (!is_direction_valid)  //up left down right, wasd
    {
        message("Enter a direction(WASD)");

        cin >> direction;

        up_input(direction);
        cout << "direction:" << direction << endl;
        is_direction_valid = true;

    };

    reception_map placeholder; 
    return placeholder;

    
}


