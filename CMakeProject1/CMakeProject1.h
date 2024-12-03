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

//if an occupied position is hit, swap it with the new letter 
//can't go same direction twice in a row, cant use same letter twice in a row
class input
{
public:
    char previous_letter;
    char previous_direction;
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
        previous_letter = '\0';
        previous_direction = '\0';
    }
};

class grid_management
{
public: 
    vector<char> current_targets;
    int current_pos;
    void print_grid(); 
    void calc_cell_number(reception_tuple_type&); //get cell number, then convert that to a coordinate
    void mod_position(char&, int);//letter 
    bool variant_type_checker(variant<int, char>);
    void swap_cell(char&, bool); 
    bool check_boundaries();
    void check_positions(); 
    optional<int> letter_search(); //returns what cell it was found in, if it was found
    void print_cell_values();
    void print_targets();
    vector<char> fetch_alph_relations(); //returns what needs to be searched for next
    void print_collected(vector<char> collected_items) const;
    vector<char> chars_to_eval;

    grid_management()
    {
        current_targets = { 'S' }; //default
        current_pos = 85;
        chars_to_eval = {}; //this does not get reset (but is edited within the code) so it's more efficient to init here than in a method
    };
};

class chain_mechanics : public grid_management
{
public: 
    vector<char> chaining(vector<char> elements_to_eval);
    void print_char_evals(vector<char> chars_to_ev);
    vector<char> char_chain; //chain of collection 

    chain_mechanics()
    {
        char_chain = {};
    };
};
struct final_scores_struct
{
    string time_in_min;
    int turns;
    int final_score;

    final_scores_struct(string time = "00:00", int t = 0, int score = 0) 
        : time_in_min(time), turns(t), final_score(score) {}
};

class mechanics_management : public grid_management
{
public: 
    int seconds;
    bool is_timing;
    int turn_counter;
    bool is_victory; //init this as false
    int stopwatch();
    void turn_counting(); 
    bool victory_condition_checking(); //true if victorious, false if not 
    bool check_turn_counter() const; //returns if max turns are reached or not 
    void game_over();
    void victory();
    final_scores_struct score_calculation(); 
    mechanics_management()
    {
        is_victory = false;
        seconds = 0;
        is_timing = true;
        turn_counter = 1; 

    };
};

string display_message(string);


#endif
