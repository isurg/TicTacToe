#include <iostream>
#include "functions.h"


int main()
{
	// just greeting
	greet();

	// make a 3x3 grid, to choose from
	int grid_array[3][3]; 
	
	// to fill in numbers of each spot
	make_spots(grid_array);


	// simply, 9 spots, 9 turns, even number is 'X', odd is 'O'
	int turn_num = 0;
	
	// represents the turn in number, X = 0, O = 10
	int turn = 0;

	// starts as false, at the the end the function win_checker checks if any won,
	// then return true, and exit while loop
	bool win = false;

	

	while (win == false && turn_num < 9) {

		turn = turn_function(turn_num);

		// self explanatory, draws board with the available spots
		draw_board(grid_array);

		// self explanatory
		choose(grid_array, turn);

		// check if any has won, return true if so
		// check only after 5 movement, as it impossible to win before that
		// we start counting from 0 so...
		if (turn_num >= 4)
			win = win_checker(grid_array);
		

		if (win == false)
			turn_num++;
		
	}


	draw_board(grid_array);

	// prints out if any has won, or otherwise
	end_game(win, turn);

}