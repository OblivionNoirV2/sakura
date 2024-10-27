//this is going to be a grid made up of 13 arrays of 13 (because 7 provides a middle for 0,0)
//ranges determine which row it falls in, ie (cell 14-25 = row 2) then count up from where that row starts 

#include "CMakeProject1.h"
#include<array>
#include <variant>
#include <cmath> 
#include <type_traits>
#include <optional>
#include <unordered_map>

using namespace std;

//first we need to figure out what number we are at in the overall array. 0, 0, is 85. 

int digit_checker(int number)//return number of digits in number
{
    //1-9, 10-99, 100+ 

    if (number == 0) //log10 0 is undefined 
    {
        return 1;
    }
    else
    {
        return static_cast<int>(log10(number)) + 1; //log10 returns digits -1, so add an extra 
    }
};

int origin_point = 85; //(0, 0)
array<variant<int, char>, 169> mixed_grid = {}; //defaults to all 0s, but letters will be chars

void grid_management::print_grid() //reset to all 0s, this should happen first
{
    int cell_number = 0; //use 1 because we DO need a middle number (85) to use as 0,0

    int element_count = 1; //need a seperate counter for all elements, for printing purposes. start at 1 for modulo 

    for (auto& element : mixed_grid) //for formatting, add 3 extra spaces if the number is single digit and 2 if it's double digit, 1 for triple
    {
        //reset the element to the current cell number
        if (holds_alternative<int>(element))
        {
            int& int_value = get<int>(element); //reference to the int
            int_value = cell_number++; //assign and increment the cell number
            cout << int_value << (digit_checker(int_value) == 1 
                ? "   " 
                : digit_checker(int_value) == 2 
                ? "  " 
                : " "
                ); 
            //add 2 newlines after every 13 elements to form a 13x13 grid
  
        }
        else 
        {
            cout << get<char>(element) << "   ";
            cell_number++;
        }
        element_count++;
        if (element_count % 13 == 1)
        {
            cout << "\n\n";
        }

    }
};

int current_pos = 85; 

/*
* use the extracted direction to determine how to move
* to move down a row by 1, it's gonna be +13 
* to move up a row by 1, it's gonna be -13 

* w = up 1 (row)
* a = left 1 (cell)
* s = right 1 (cell)
* d = down 1 (row)
*
* also remember we need to check for edges before making any movements
*/
map<char, int> match_to_movement =
{
    {'W', -13},
    {'A', -1},
    {'S', 13},
    {'D', 1}
};

//returns the new cell num 
void grid_management::calc_cell_number(reception_tuple_type& recieved_coordinates) //gets the cell number based on input recieved, which will then be converted to a coordinate
{
    cout << "test letter: " << get<0>(recieved_coordinates) << endl;
    cout << "test direction: " << get<1>(recieved_coordinates) << endl;

    cout << "current_pos: " << current_pos << endl;

    //first extract the direction 
    char extracted_direction = get<1>(recieved_coordinates); 

    char extracted_letter = get<0>(recieved_coordinates); 

    cout << "extracted direction: " << extracted_direction << endl; 
    //first we need to know what number we're on. Default is 85. 

    //retrieve movement value 
    int movement_value = match_to_movement[extracted_direction]; 

    current_pos += movement_value; 
    cout << "fresh position: " << current_pos << endl; 

    cout << "move val: " << movement_value << endl; 
    mod_position(extracted_letter, movement_value);

};

//checks if spot is taken. If it is, meaning it's NOT an int, returns true
bool grid_management::variant_type_checker(variant<int, char> type_given)
{
    return holds_alternative<int>(type_given) ? false : true;
};

mechanics_management mm_3;
//Next we need to adjust the new position accordingly, simple array position swap after some checks
void grid_management::mod_position(char& recieved_letter, int movement_value)
{
    cout << "num inside mod pos func: " << current_pos << endl;
    //check if position has a number or character. char = a letter is there 

   
    bool is_spot_taken = variant_type_checker(mixed_grid[current_pos]);
     //reset each time this is run 

    if (check_boundaries())
    {
        //turn is invalid, nothing happens and move to next (but turn DOES get incremented)
        display_message("Boundary hit"); 
        mm_3.turn_counting(); //lets do this first
    }
    else
    {
        swap_cell(recieved_letter, is_spot_taken);
    }
    cout << "is spot taken: " << is_spot_taken << endl;

    cout << "recieved letter inside mod pos: " << recieved_letter << endl;
    
};
//ensure position remains within the allotted variant array
//so how this works if it it hits an edge, it will simply move to the next row. It only becomes a "boundary" if it goes off the turing strip
bool grid_management::check_boundaries() 
{
    return current_pos < 170 && current_pos >= 1 ? false : true;
};

//char current_
// 
// 
// = 's'; //default for the full scan below
void grid_management::swap_cell(char& recieved_letter, bool cell_taken)
{
    mixed_grid[current_pos] = recieved_letter;

    if (cell_taken)
    {
        //char for char, in this case we need to display a swap message 
        cout << "Existing letter at position has been swapped for " << recieved_letter << endl;
    };
    cout << "current pos inside cell swap: " << current_pos << endl; 

   
    //cout << "current turn: " << turn_counter << endl; 

    print_grid();
    //check_positions(); //letter search first
    letter_search();

};

surroundings_type positions_to_check = 
{
    -1, 1, 12, 13, 14, -14, -13, -12
}; 

void grid_management::print_cell_values()
{
    for (auto& i : mixed_grid)
    {
        visit([](auto&& arg)
        {
            cout << "value: " << arg << endl;
        }, i);
    }
};
//vector<char> current_targets = { 'S' };//default
//things to check for each character. like if we have an A, the next possibility is a K, R, or S

//these values never change, but they rely on current_targets(which does change) so we can't wait till compile time
vector<char> grid_management::fetch_alph_relations()
{
    vector<char> found_matches = {}; 

    unordered_map<char, vector<char>> char_map
    {
        {
            {'S'}, { 'A' }
        },
        {
            {'A'}, {'K', 'R', 'S'}
        },
        {
            {'U'} , {'K', 'R'}
        }
    };
    
    if (current_targets.size() == 1) //if it's K or R, since they share the same matches
    {
        char alph_key = current_targets[0];

        cout << "inside current target cond, alph key: " << alph_key << endl;//this is S, as expected
     
       found_matches = char_map[alph_key];
       for (char i : found_matches)
       {
           cout << "match:" << i << endl; 
       }
       return found_matches;
    }
    else 
    {
        return found_matches = { 'A', 'U' };
    }

};

void grid_management::print_targets()
{
    for (char j : current_targets)
    {
        cout << "fresh target: " << j << endl;
    };

    int target_count = 0;
    for (char x : current_targets)
    {
        target_count++;
        cout << "target: " << x << " target count: " << target_count << endl;
        //then go to victory checking, which will concat the parts together in order to check if the goal has been met. 

    }
    target_count = 0;
};

//do a full scan, if an s is located use that as a starting point and do check_positions, then repeat the cycle using this to check surrounding letters 
optional<int> grid_management::letter_search()//returns cell number target was found at, if it was found
{ //so start with looking for an S, if one is found, target switches to A(uppercase! important!), and so on 
    bool target_found = false; 

    vector<char> target_vect; 

    //print_cell_values(); 
    for (auto& k : mixed_grid)
    {
        //reference to access the variable, not copy it
        visit([&](auto&& arg)
        {
            for (char j : current_targets)//somehow, current_targets is getting integers in it. 
            {
                if (arg == j)
                {
                    cout << "target found: " << static_cast<char>(arg) << endl; 
                    target_found = true;
                    break; 
                }
            }
        }, k);

        if (target_found)//if this flips to true it means we need to look for the next part of the word
        {
            cout << "moving to next target(s)" << endl; 
            current_targets = fetch_alph_relations(); 
            print_targets();
            mm_3.victory_condition_checking();
            if (collected_parts.size() >= 6)//impossible to win with less than 6 pieces
            {
                //victory checking
                mm_3.victory_condition_checking();
            }
            //else the overall loop simply continues 
            break;
        };
    }
    return 0;
}; 
//will return info about the cells surrounding the given cell
surroundings_type grid_management::check_positions(int starting_cell)
{
    surroundings_type surrounding_array = {}; 
    for (size_t i = 0; i < positions_to_check.size(); ++i) 
    {
        surrounding_array[i] = starting_cell + positions_to_check[i];
        cout << surrounding_array[i] << endl; 

    }

    return surrounding_array; 

};

void grid_management::print_collected() const
{
    if (collected_parts.empty())
    {
        cout << "collection is empty" << endl; 
    }
    else
    {
        for (int j = 0; j < collected_parts.size(); ++j)
        {
            cout << j << endl; 
        }
    }
};


//this stuff will probably get moved to new file 
bool mechanics_management::victory_condition_checking() //returns victory or no
{
    cout << "entered victory condition checking" << endl;
    cout << "is_victory value: " << is_victory << endl;


    return is_victory;
};

bool mechanics_management::check_turn_counter()
{
    return turn_counter > 50 ? true : false; 
};

//before this we need to check for victory conditions, but not if a boundary was hit(can just skip straight to turn manage w/o checking for victory)
void mechanics_management::turn_counting()
{
    //if a boundary was hit, simply add one to the turn counter and continue the cycle 
    bool is_turn_limit = check_turn_counter();

    turn_counter++;//in any situation, this comes first because it's the last stage of the turn

    //50 turn limit
    cout << "inside turn management" << endl;

    if (check_turn_counter())
    {
        //game is over
    }
    else
    {
   

    }
    
};

void mechanics_management::game_over()
{

};
void mechanics_management::victory()
{

};
int mechanics_management::score_calculation()
{
    return 0; 
};


