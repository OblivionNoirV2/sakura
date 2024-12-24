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
    mod_position(extracted_letter);

};

//checks if spot is taken. If it is, meaning it's NOT an int, returns true
bool grid_management::variant_type_checker(variant<int, char> type_given)
{
    return holds_alternative<int>(type_given) ? false : true;
};

mechanics_management mm_3;
//Next we need to adjust the new position accordingly, simple array position swap after some checks
void grid_management::mod_position(char recieved_letter)
{
    cout << "num inside mod pos func: " << current_pos << endl;
    //check if position has a number or character. char = a letter is there 

    bool is_spot_taken = variant_type_checker(mixed_grid[current_pos]);

    if (check_boundaries())
    {
        //turn is invalid, nothing happens and move to next (but turn DOES get incremented)
        display_message("Boundary hit"); 
        mm_3.turn_counting(); //lets do this first
    }
    else
    {
        display_message("swap performed");
        swap_cell(recieved_letter, is_spot_taken);
    }
    cout << "is spot taken? " << is_spot_taken << endl;

    cout << "recieved letter inside mod pos: " << recieved_letter << endl;
    
};
//ensure position remains within the allotted variant array
//so how this works if it it hits an edge, it will simply move to the next row. It only becomes a "boundary" if it goes off the turing strip
bool grid_management::check_boundaries() 
{
    return current_pos < 170 && current_pos >= 1 ? false : true;
};


void grid_management::swap_cell(char recieved_letter, bool cell_taken) //this feels like it should take place later
{
    cout << "is spot taken? " << cell_taken << endl; 
    mixed_grid[current_pos] = recieved_letter;

    if (cell_taken)
    {
        //cout << "cell taken" << mixed_grid[current_pos] << endl; //if this happens, we need to 
        //char for char, in this case we need to display a swap message 
        cout << "Existing letter at position has been swapped for " << recieved_letter << endl; //swap works fine, but why isn't this writing
    };
    cout << "current pos inside cell swap: " << current_pos << endl; 

   
    //cout << "current turn: " << turn_counter << endl; 

    print_grid();
    //check_positions(); //letter search first
    letter_search();

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
            {'K'}, {'A', 'U'}
        },
        {
            {'U'} , {'K', 'R'}
        },
        {
            {'R'}, {'A', 'U'}
        }
    };
    char alph_key = current_targets[0];

    cout << "inside current target cond, alph key: " << alph_key << endl;//this is S, as expected

    found_matches = char_map[alph_key];
    for (char i : found_matches)
    {
        cout << "match:" << i << endl;
    }
    return found_matches;
    /*
    if (current_targets.size() == 1) //if it's K or R, since they share the same matches
    {

    }
    else 
    {
        return found_matches = { 'A', 'U' }; //this is matching when it shouldn't. it should not match to U 
    }*/

};

void grid_management::print_targets()
{

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
        current_targets = fetch_alph_relations(); 
        print_targets();
        //print_collected();
        check_positions(); //just for testing, this may go elsewhere
        mm_3.victory_condition_checking(); //temp
        /*if (collected_chain.size() >= 6)//impossible to win with less than 6 pieces
        {
                //victory checking
            mm_3.victory_condition_checking();
        }*/
            //else the overall loop simply continues 
        break;
        
    }
    return 0;
}; 
surroundings_type positions_to_check =
{
    -1, 1, 12, 13, 14, -14, -13, -12
};

chain_mechanics cm1;

unordered_map<char, string> combo_reference
{

};
//this only gets called if the vector is not empty, so there should always be a valid return. 
vector<char> chain_mechanics::chaining(vector<char> elements_to_eval)
{
    cout << "inside chaining" << endl; 
    cm1.print_char_evals(elements_to_eval);
    /*algorithm
    -need to look for certain matches, like if there's an S and an A and shit like that 
    -if there is, store them on the chain in the proper order
    -remove those letters from the vector via index (remember this means we need to remove them from the grid as well!) 
    -remember, by the time it's gotten here we already know the positions are valid so we just need to check for the right combinations
    -due to how the board is set up, this chain will only get fully cleared when the game ends
    -ends when a "sakura" is found or turn limit is reached (turn limit should be checked before any major computations take place
    */
    vector <char> temp2 = { 'c' };

    return temp2;
};

bool grid_management::subchain_verif(vector<tuple<char, int>> subchain) {
    return true; 
};

//will return info about the cells surrounding the given cell
void grid_management::check_positions() 
{
    vector<tuple<char, int>> current_subchain = {}; 
    surroundings_type surrounding_array = {}; 
    for (size_t i = 0; i < positions_to_check.size(); ++i) 
    {
        surrounding_array[i] = current_pos + positions_to_check[i]; 
        cout << "surrounding but only indexes: " << surrounding_array[i] << endl;

    }
    //ok so we need to take that surrounding array and find the values in the mixed grid held at those indexes
    //print_grid();

    //no need to print, just locate so it can use that data 
    if (!surrounding_array.empty())//may be able to remove this
    {
        for (size_t i : surrounding_array) 
        { //what we need to check is the indexes present in surrounding_array
            const auto& cell_i = mixed_grid[i];

            if (holds_alternative<int>(cell_i))
            {
                cout << "int: " << get<int>(cell_i) << endl;
            }
            else if (holds_alternative<char>(cell_i))
            {//ok so if one is found here, AND it matches correctly with the map up top, that means it is a valid target found. a success
                //in other words, if we reach this point it passes the first check of being a char in the given range
                char char_success = get<char>(cell_i);
                cout << "char: " << char_success << endl; //then this stuff needs to be eval'd, and that goes until the chain breaks or a win is found

                //so first here we're gonna add it to a subchain, which doesn't get added to the final chain until it's verified that the valid letters did not change. this will need the positions of the collected letters 
                //pass that subchain to the function here, value and cell number 
                tuple<char, int> element = make_tuple(char_success, static_cast<int>(i));
                cout << "tuple char: " << get<0>(element) << endl;
                cout << "tuple int: " << get<1>(element) << endl; 
                current_subchain.push_back(element);

                //chars_to_eval.push_back(char_success); 
                //cm1.print_char_evals(chars_to_eval);
            }
            else
            {
                cout << "shouldn't be here" << endl;
            }
        }
    }
    else
    {
        cout << "surrounding array is empty" << endl;
    };

     //pass the collection into chaining. no return
    if (!chars_to_eval.empty())
    {
        cm1.chaining(chars_to_eval);
    }
    else
    {
        cout << "no chars to eval" << endl;
    };

};

void chain_mechanics::print_char_evals(vector<char> chars_to_ev)
{
    if (!chars_to_ev.empty())
    {
        for (char c : chars_to_ev)
        {
            cout << "char to ev: " << c << endl;
        };

    }
    else
    {
        cout << "eval vector is empty" << endl;
    };

};



void grid_management::print_collected(vector<char> collected_items) const
{
    if (collected_items.empty())
    {
        cout << "collection is empty" << endl; 
    }
    else
    {
        cout << "collected: " << endl; 
        for (char j : collected_items)
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
    cout << "turn num: " << turn_counter << endl; 


    //turn_counting();

    return is_victory;
};

bool mechanics_management::check_turn_counter() const
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
    cout << "inside turn management, new turn count: " << turn_counter << endl;

    bool is_turn_limit_exceeded = check_turn_counter();
    if (is_turn_limit_exceeded)
    {
        //game is over, but display final time and score 
    }
    else
    {
   

    }
    
};

void mechanics_management::game_over()
{
    //asks if end or start over?
};
void mechanics_management::victory()
{

};
/*
//time(converted to minutes, so this is a string), turns, final score
final_scores_struct mechanics_management::score_calculation()
{
    final_scores_struct ph; //placeholder
    ph.time_in_min = "5";
    ph.final_score = 100;
    ph.turns = 30;

    return ph; 
};*/


