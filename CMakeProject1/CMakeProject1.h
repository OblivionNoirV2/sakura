#include <iostream>


#ifndef INPUT_H
#define INPUT_H 

class Input
{
public: 
	struct given_input
	{
		char chosen_letter; 
		bool chosen_direction; //true for left, false for right
	};

	char guess_letter();
};

#endif