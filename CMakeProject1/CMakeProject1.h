#ifndef HEADER_H
#define HEADER_H 

#include <iostream>
#include <map> 
#include <array> 
#include <vector>
#include <cstdint>

using namespace std;
using reception_map = map<int, char>; //coordinates 
//1 2 3 4 corresponding to each direction

//a grid, keep track of what's at each position 
//if an occupied position is hit, swap it with the new letter 
//12 x 12 grid 
//can't go same direction twice in a row, cant use same letter twice in a row
//goal is to spell SAKURA in some way 




class Input
{
public:
    reception_map get_input();
};

const array<char, 6> valid_letters =
{
    'S', 'A', 'K', 'U', 'R', 'A'
};

extern uint8_t round_num;
extern vector<reception_map> past_inputs_combined;
extern char previous_letter; 
extern int previous_direction;
extern char coordinates[12][12]; 
#endif
