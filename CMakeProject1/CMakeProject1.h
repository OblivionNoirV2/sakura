#include <iostream>
#include <map> 

using namespace std; 


#ifndef INPUT_H
#define INPUT_H 

class Input
{
public: 

	map<bool, char> get_input();
};

const char default_letters[6] =
{
	'S', 'A', 'K', 'U', 'R', 'A'
};

#endif

