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
#include <variant>

using namespace std;
//using reception_map = map<int, char>; //coordinates 

using reception_tuple_type = tuple<char, char>;


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
    void print_grid(); 
    void calc_cell_number(reception_tuple_type&); //get cell number, then convert that to a coordinate
    void mod_position(char&, int);//letter 
    bool variant_type_checker(variant<int, char>);
    void swap_cell(char&, bool, int); 
    bool victory_condition_checking(); //true if victorious, false if not 
    bool check_boundaries();

};

class time_management
{
public: 
    void stopwatch();
    void turn_management(); 

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




string display_message(string);

extern int seconds; 

extern int turn_counter; 

extern uint8_t round_num;
//extern vector<reception_map> past_inputs_combined;//probably not needed
extern char previous_letter; 
extern char previous_direction;

extern int prev_num; 
extern int current_pos; 

extern bool game_running; 

#endif
