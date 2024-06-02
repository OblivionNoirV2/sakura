// CMakeProject1.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>

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