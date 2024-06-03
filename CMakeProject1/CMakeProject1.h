#include <iostream>
#include <map> 
#include <array> 
#include <vector>
#include <cstdint>

using namespace std; 


#ifndef INPUT_H
#define INPUT_H 

class Input
{
public: 

	map<bool, char> get_input();
};

const array<char, 6> default_letters =
{
	'S', 'A', 'K', 'U', 'R', 'A'
};

//store past inputs 
//max round num is 100 
uint8_t round_num = 1; 
vector<map<char, bool>>; 







#endif

