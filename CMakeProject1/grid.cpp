//this is going to be a grid made up of 13 arrays of 13 (because 7 provides a middle for 0,0)
//ranges determine which row it falls in, ie (cell 14-25 = row 2) then count up from where that row starts 

//start by creating reference points for each row split, maybe with a map


using namespace std; 
//#include <map>
#include<array>
#include <variant>


//first we need to figure out what number we are at in the overall array. 0, 0, is 85. 

int origin_point = 85; //(0, 0)
array<variant<int, char>, 169> mixed_grid = {}; //defaults to all 0s, but letters will be chars

for (auto& element : mixed_array) //make this a function
{
    element = 0;  //init to all zeros 
}


int get_row_or_column()
{

}
//put all this shit in a class