#include <iostream>
#include <map> 
#include <array> 

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

#endif

