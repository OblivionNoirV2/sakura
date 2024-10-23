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
#include <optional>

using namespace std;
//using reception_map = map<int, char>; //coordinates 

using reception_tuple_type = tuple<char, char>;

using surroundings_type = array<int, 8>;

//1 2 3 4 corresponding to each direction

//a grid, keep track of what's at each position 
//if an occupied position is hit, swap it with the new letter 
//12 x 12 grid 
//can't go same direction twice in a row, cant use same letter twice in a row
//goal is to spell SAKURA in some way 

/*const array<char, 6> valid_letters = this does not change hence the implementation
{
    'S', 'A', 'K', 'U', 'R', 'A'
};

const array<char, 4> valid_directions =
{
    'W', 'A', 'S', 'D'
};*/
class input
{
public:
    const array<char, 6> valid_letters; 
    const array<char, 4> valid_directions; 
    reception_tuple_type get_input();
    void set_prev_letter(char& previous_letter, char letter);
    void set_prev_direction(char& previous_direction, char direction); 
    void message(string msg);

    input() :  //init immediately since these are const
        valid_letters { 'S', 'A', 'K', 'U', 'R', 'A' },
        valid_directions { 'W', 'A', 'S', 'D' }
        {
    }
};

class grid_management
{
public: 
    vector<char> collected_parts; 
    vector<char> current_targets;
    void print_grid(); 
    void calc_cell_number(reception_tuple_type&); //get cell number, then convert that to a coordinate
    void mod_position(char&, int);//letter 
    bool variant_type_checker(variant<int, char>);
    void swap_cell(char&, bool); 
    bool check_boundaries();
    surroundings_type check_positions(int starting_cell); 
    optional<int> letter_search(); //returns what cell it was found in, if it was found
    void print_cell_values();
    void print_targets();
    vector<char> fetch_alph_relations(); //returns what needs to be searched for next
    void print_collected();

    grid_management()
    {
        collected_parts = {}; 
        current_targets = { 'S' };
    };
};

class mechanics_management : public grid_management
{
public: 
    int seconds;
    bool is_timing;

    int turn_counter;

    bool is_victory; //init this as false
    void stopwatch();
    void turn_management(bool); //bool for boundary hit or not
    bool victory_condition_checking(); //true if victorious, false if not 

    mechanics_management()
    {
        is_victory = false;
        seconds = 0;
        is_timing = true;
        turn_counter = 1; 

    };
};

//print grid func here 





//might be able to clean this stuff up
string display_message(string);

extern int seconds; 

extern int turn_counter; 

extern uint8_t round_num;
//extern vector<reception_map> past_inputs_combined;//probably not needed
extern char previous_letter; 
extern char previous_direction;

extern int prev_num; 
extern int current_pos; 


#endif
