#include <iostream>


#ifndef INPUT_H
#define INPUT_H 

class Input
{
public: 

	char chosen_letter; 
	bool chosen_direction; //true for left, false for right

	char get_input();
};

const char default_letters[6] =
{
	'S', 'A', 'K', 'U', 'R', 'A'
};

#endif