#ifndef HEADER_H
#define HEADER_H 

#include <iostream>
#include <map> 
#include <array> 
#include <vector>
#include <cstdint>
#include <chrono>
#include <thread>
#include <ctime>
#include <tuple>

using namespace std;
//using reception_map = map<int, char>; //coordinates 

using reception_tuple_type = tuple<char, char>;

using current_coordinates_type = tuple<int, int>;

//1 2 3 4 corresponding to each direction

//a grid, keep track of what's at each position 
//if an occupied position is hit, swap it with the new letter 
//12 x 12 grid 
//can't go same direction twice in a row, cant use same letter twice in a row
//goal is to spell SAKURA in some way 


class input
{
public:
    reception_tuple_type get_input();
    void set_prev_letter(char& previous_letter, char letter);
    void set_prev_direction(char& previous_direction, char direction); 
    void message(string msg);
};

class grid_management
{
public: 
    void reset_grid(); 
    int calc_cell_number(reception_tuple_type& recieved_coords); //get cell number, then convert that to a coordinate
    current_coordinates_type convert_to_coords();
};

//print grid func here 

const array<char, 6> valid_letters = //this does not change hence the implementation
{
    'S', 'A', 'K', 'U', 'R', 'A'
};

const array<char, 4> valid_directions =
{
    'W', 'A', 'S', 'D'
};


void stopwatch();

extern int seconds; 


extern uint8_t round_num;
//extern vector<reception_map> past_inputs_combined;//probably not needed
extern char previous_letter; 
extern char previous_direction;

extern int prev_num; 
extern int current_num; 

#endif
