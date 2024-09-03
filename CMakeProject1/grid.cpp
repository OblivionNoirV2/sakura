//this is going to be a grid made up of 13 arrays of 13 (because 7 provides a middle for 0,0)
//ranges determine which row it falls in, ie (cell 14-25 = row 2) then count up from where that row starts 

#include "CMakeProject1.h"
#include<array>
#include <variant>
#include <cmath> 
#include <type_traits>
using namespace std;

//first we need to figure out what number we are at in the overall array. 0, 0, is 85. 

int digit_checker(int number)//return number of digits in number
{
    //1-9, 10-99, 100+ 

    if (number == 0) //log10 0 is undefined 
    {
        return 1;
    }
    else
    {
        return static_cast<int>(log10(number)) + 1; //log10 returns digits -1, so add an extra 
    }
};

int origin_point = 85; //(0, 0)
array<variant<int, char>, 169> mixed_grid = {}; //defaults to all 0s, but letters will be chars

void grid_management::reset_grid() //reset to all 0s, this should happen first
{
    int cell_number = 1; //use 1 because we DO need a middle number (85) to use as 0,0

    for (auto& element : mixed_grid) //for formatting, add 3 extra spaces if the number is single digit and 2 if it's double digit, 1 for triple
    {
        //reset the element to the current cell number
        if (holds_alternative<int>(element))
        {
            int& int_value = get<int>(element); //reference to the int
            int_value = cell_number++; //assign and increment the cell number
            cout << int_value << (digit_checker(int_value) == 1 
                ? "   " 
                : digit_checker(int_value) == 2 
                ? "  " 
                : " "
                ); 
            //add 2 newlines after every 13 elements to form a 13x13 grid
            if (cell_number % 13 == 1)
            {
                cout << "\n\n";
            }
        }
        else //print the char
        {
            cout << "Not an int" << " "; //placeholder
        }
    }
};

int current_pos = 85; //default is 85 

/*
* use the extracted direction to determine how to move
* to move down a row by 1, it's gonna be +13 
* to move up a row by 1, it's gonna be -13 

* w = up 1 (row)
* a = left 1 (cell)
* s = right 1 (cell)
* d = down 1 (row)
*
* also remember we need to check for edges before making any movements
*/
map<char, int> match_to_movement =
{
    {'W', -13},
    {'A', -1},
    {'S', 13},
    {'D', 1}
};

//returns the new cell num 
void grid_management::calc_cell_number(reception_tuple_type& recieved_coordinates) //gets the cell number based on input recieved, which will then be converted to a coordinate
{
    cout << "test letter: " << get<0>(recieved_coordinates) << endl;
    cout << "test direction: " << get<1>(recieved_coordinates) << endl;

    cout << "current_pos: " << current_pos << endl;

    //first extract the direction 
    char extracted_direction = get<1>(recieved_coordinates); 

    char extracted_letter = get<0>(recieved_coordinates); 

    cout << "extracted direction: " << extracted_direction << endl; 
    //first we need to know what number we're on. Default is 85. 

    //retrieve movement value 
    int movement_value = match_to_movement[extracted_direction]; 

    current_pos += movement_value; 
    cout << "fresh num: " << current_pos << endl; 

    cout << "move val: " << movement_value << endl; 
    mod_position(extracted_letter);

};

//checks if spot is taken. If it is, meaning it's NOT an int, returns true
bool grid_management::variant_type_checker(variant<int, char> type_given)
{
    return holds_alternative<int>(type_given) ? false : true;
};



void grid_management::swap_cell(char& recieved_letter, bool cell_taken)
{
    mixed_grid[current_pos] = recieved_letter;

    if (cell_taken)
    {
        //char for char, in this case we need to display a swap message 
    }
    cout << "current pos inside cell swap: " << current_pos << endl; 

    mixed_grid[current_pos] = recieved_letter; //swap the position 

    visit([](const auto& value)
    {
       cout << "new value at position "<< current_pos << ": " << value << std::endl;
    }, mixed_grid[current_pos]);

};

//Next we need to adjust the new position accordingly, simple array position swap after some checks
void grid_management::mod_position(char& recieved_letter)
{

    
    cout << "num inside mod pos func: " << current_pos << endl;
    //check if position has a number or character. char = a letter is there 

    bool is_spot_taken = variant_type_checker(mixed_grid[current_pos]);

    //remember we also need to make sure it's not out of bounds - number must be between 1 and 169

   

    cout << "is spot taken: " << is_spot_taken << endl; 

    cout << "recieved letter inside mod pos: " << recieved_letter << endl; 

    swap_cell(recieved_letter, is_spot_taken); 

};



