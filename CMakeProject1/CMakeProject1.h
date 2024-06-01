// CMakeProject1.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>

// TODO: Reference additional headers your program requires here.
#ifndef INPUT_H
#define INPUT_H

class Input
{
public:
    struct given_input
    {
        char chosen_letter;
        bool chosen_direction; // true for left, false for right
    };

    char guess_letter(); // returns player guess. players cannot see remaining letters, part of the logic game
};

#endif // INPUT_H
