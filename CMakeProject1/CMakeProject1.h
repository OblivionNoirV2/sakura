#include <iostream>
#include <map> 
#include <array> 
#include <vector>
#include <cstdint>

using namespace std; 
using reception_map = map<bool, char>; 


#ifndef INPUT_H
#define INPUT_H 

class Input
{
public: 

	reception_map get_input();
};

const array<char, 6> default_letters =
{
	'S', 'A', 'K', 'U', 'R', 'A'
};

//store past inputs 
//max round num is 100 
extern uint8_t round_num; 
extern vector<reception_map> past_inputs; 



#endif

