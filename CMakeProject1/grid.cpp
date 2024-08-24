//this is going to be a grid made up of 13 arrays of 13 (because 7 provides a middle for 0,0)
//ranges determine which row it falls in, ie (cell 14-25 = row 2) then count up from where that row starts 

//start by creating reference points for each row split, maybe with a map



#include "CMakeProject1.h"
#include<array>
#include <variant>
using namespace std;

//first we need to figure out what number we are at in the overall array. 0, 0, is 85. 

int origin_point = 85; //(0, 0)
array<variant<int, char>, 169> mixed_grid = {}; //defaults to all 0s, but letters will be chars

void grid_management::reset_grid()
{
    cout << "inside function" << endl; 
    for (auto& element : mixed_grid) 
    {
        element = 0;
        cout << "in loop" << endl;
    }
}


/*int get_row_or_column()
{

}*/
//put all this shit in a class

