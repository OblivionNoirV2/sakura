//this is going to be a grid made up of 13 arrays of 13 (because 7 provides a middle for 0,0)
//ranges determine which row it falls in, ie (cell 14-25 = row 2) then count up from where that row starts 




#include "CMakeProject1.h"
#include<array>
#include <variant>
using namespace std;

//first we need to figure out what number we are at in the overall array. 0, 0, is 85. 


int origin_point = 85; //(0, 0)
array<variant<int, char>, 169> mixed_grid = {}; //defaults to all 0s, but letters will be chars

void grid_management::reset_grid() //reset to all 0s, this should happen first
{
    int cell_number = 1; //use 1 because we DO need a middle number (85) to use as 0,0

    for (auto& element : mixed_grid) //for formatting, add 2 extra spaces if the number is single digit and 1 if it's double digit 
    {
        //reset the element to the current cell number
        if (holds_alternative<int>(element))
        {
            int& int_value = get<int>(element); //reference to the int
            int_value = cell_number++; //assign and increment the cell number

            cout << int_value << " ";

            //add a newline after every 13 elements to form a 13x13 grid
            if (cell_number % 13 == 1)
            {
                cout << endl;
            }
        }
        else //this is where non-ints will be taken care of 
        {
            cout << "Not an int" << " "; //placeholder
        }
    }
};


/*int get_row_or_column()
{

}*/
//put all this shit in a class

