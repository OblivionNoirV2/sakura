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
//default values, cannot be in the function or they'll get reset every time
char previous_letter = '\0';
char previous_direction = '\0';

reception_map input::get_input() //first get user input, then compare it to default letters to ensure it is valid 
{
    bool is_letter_valid = false;

    char letter; 
    char direction; 

    while (!is_letter_valid) 
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
                set_prev_letter(previous_letter, letter) 
                :  //remember to reset validity after the input is done 
                message("Cannot use the same letter as last turn!");     
        }
        else
        {
            message("Valid inputs are s, a, k, u, r, a");
        }
    }
    cout << "new prev" << letter << endl; 
    //get_input(); //proves that letter tracking works

    //now that that's validated get the direction 
    //while()


    int chosen_direction; //up left down right, wasd
    cout << "Enter a direction (WASD)" << endl; //this should work pretty much the same as with the letters, validate the set 



 
    

    reception_map placeholder; 
    return placeholder;

    
}


