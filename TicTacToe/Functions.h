#include <iostream>



void greet() {

	std::cout << "_______________________\n\n";
	std::cout << "Welcome to Tic-Tac-Toe!\n\n";
	std::cout << "ASCII ART\n\n";
	std::cout << "_______________________\n\n\n";

}



void make_spots(int grid_array[3][3]) {

	int num = 1;

	for (int i = 0; i < 3; i++) {
		
		for (int j = 0; j < 3; j++) {

			grid_array[i][j] = num;
			num++;
		}
	}
}



void draw_board(int grid_array[3][3]) {

	for (int i = 0; i < 3; i++) {

		for (int j = 0; j < 3; j++) {

			if (grid_array[i][j] == 0)

			std::cout << " " << grid_array[i][j];

			if (j != 2)
				std::cout << "  | ";

		}

		if (i != 2)
			std::cout << "\n----------------\n";
	}

	std::cout << "\n\n";
}

int turn_function(int turn_num) {

	// X = 0
	// O = 10
	if (turn_num % 2 == 0)
		return 0;
	else
		return 10;
	
}



void choose(int grid_array[3][3], int turn) {

	int choice;
	char turn_char;

	// To convert the number into a representative char
	if (turn == 0)
		turn_char = 'X'; // X = 0
	else
		turn_char = 'O'; // O = 10


	std::cout << "\n It's " << turn_char << "'s turn, choose a spot: ";
	std::cin >> choice;
	std::cout << "\n\n";

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {

			if ( grid_array[i][j] == (choice) ) {
				
				grid_array[i][j] = turn;
			}
		}
	}

}



bool win_checker(int grid_array[3][3]) {

	// 8 sequences
	for (int i = 0; i < 3; i++) {

		// 3 sequences, rows
		if (grid_array[i][0] == grid_array[i][1] == grid_array[i][2])
			return true;
		
		// 3 sequences
		if (grid_array[0][i] == grid_array[1][i] == grid_array[2][i])
			return true;
		
		// Check it once, as it not related to the loop
		if (i == 0) {

			// 1 sequence, decline diagonal
			if (grid_array[0][0] == grid_array[1][1] == grid_array[2][2])
				return true;
			
			// 1 sequence, incline diagonal
			if (grid_array[2][0] == grid_array[1][1] == grid_array[0][2])
				return true;
		}

	}
	return false;
}



void end_game(bool win, int turn) {

	// if any had won
	if (win == true) {
		std::cout << "The winner is " << turn << ", Congrats!\n";
	}
	else {
		std::cout << "It's a tie!\n";
	}
}