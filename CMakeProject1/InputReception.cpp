#include "CMakeProject1.h"
#include <iostream>


#ifndef INPUT_H
#define INPUT_H

char Input::guess_letter()
{
    return 'a';
}

/*
class Input
{
public:
    struct given_input
    {
        char chosen_letter;
        bool chosen_direction; // true for left, false for right
    };

    char guess_letter()// returns player guess. players cannot see remaining letters, part of the logic game
    {
        return 'a';
    }
};
*/
#endif // INPUT_H
