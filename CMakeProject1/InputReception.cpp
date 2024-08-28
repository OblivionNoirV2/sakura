#include "CMakeProject1.h"
#include <iostream>
#include <algorithm>
#include <tuple>//for storing coords


using namespace std;

void input::set_prev_letter(char& previous_letter, char letter)
{
    previous_letter = letter;

    //is_input_valid = true;
};

void input::set_prev_direction(char& previous_direction, char direction)
{
    previous_direction = direction;
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

tuple<int, int> current_coordinates = make_tuple(0, 0); //default

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
        //is_direction_valid = true;

        if (find(begin(valid_directions), end(valid_directions), direction) != end(valid_directions)) //if it was not found by the end of the iterations, it's not in the set
        {
            cout << "found direction" << endl; 
            cout << "prev: " << previous_direction << endl; 
            if (direction != previous_direction) //not equal means valid
            {
                set_prev_direction(previous_direction, direction);
                is_direction_valid = true;
            }
            else
            {
                message("Cannot use the same direction as last turn!");
            };
        }
        else
        {
            message("Valid inputs are w, a, s, d"); 
        }

    };


    reception_map placeholder; //so, this needs to hold a direction and a letter. make it a tuple? 
    return placeholder;

    
}


