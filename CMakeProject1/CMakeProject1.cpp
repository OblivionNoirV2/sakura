﻿// CMakeProject1.cpp : Defines the entry point for the application.
//

#include "CMakeProject1.h"
#include <vector>
#include <algorithm> // For std::copy
#include <iostream>
#include <array> 
using namespace std;

//SAKURA 
//S -> A
//A -> S or K or R
//K -> A or U 
//U -> K or R 
//R -> U or A 
//A -> S or K or R


string display_message(string message) //move this to header 
{
    return message; 
}

bool start_game() //returns true when game is started 
{

    char begin_var; 
    //cout << "test" << endl;
    cout << "S for start, X for exit or E for explanation" << endl; 
    cin >> begin_var; 
    cout << "input is" << " " << begin_var << endl;

    //ensure it is a character 
    if (isalpha(begin_var))
    {
        cout << "yay you entered a character" << endl; 

    }
    else
    {
        cout << display_message("invalid input") << endl; //make this a global function that takes in a msg 
        start_game(); //try again
    }
    begin_var = tolower(begin_var);

    //check validity and act according to input 
    switch (begin_var)
    {
        case 's':
            return true; 
            break; 
        case 'x': 
            exit(0); 
            break;
        case 'e': 
            //display how the game works
            break; 
        default: 
            //input is invalid, try again 
            cout << display_message("invalid input, please enter S, X or E") << endl;
            start_game();

    }

    //cout << "final begin var" << " " << begin_var << endl; 


    return false; 

}

int seconds = 0; 
void stopwatch()
{
    //cout << "starting stopwatch" << endl;

    while (true)
    {
        this_thread::sleep_for(chrono::seconds(1));
        ++seconds;
        //cout << seconds << " seconds passed" << endl;
    }
};

int main()
{

    thread stopwatch_thread(stopwatch);//stopwatch on thread #2

    //Sorting sorting;

    //sorting.reinitialize();
    grid_management grid_management_2;
    grid_management_2.reset_grid();

    input input_2;
    reception_map recieved_input = input_2.get_input(); //this will be a hash with the chosen char and direction to place it 
    //std::cout << "Guessed Letter: " << guessedLetter << "\n";
    stopwatch_thread.join();
    return 0;
}