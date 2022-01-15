#include <iostream>



void greet() {

	std::cout << "_______________________\n\n";
	std::cout << "Welcome to Tic-Tac-Toe!\n\n";
	std::cout << "XXXXXXX       XXXXXXX                                                         OOOOOOOOO     \n";
	std::cout << "X:::::X       X:::::X                                                       OO:::::::::OO   \n";
	std::cout << "X:::::X       X:::::X                                                     OO:::::::::::::OO \n";
	std::cout << "X::::::X     X::::::X                                                    O:::::::OOO:::::::O\n";
	std::cout << "XXX:::::X   X:::::XXX     vvvvvvv           vvvvvvv    ssssssssss        O::::::O   O::::::O\n";
	std::cout << "   X:::::X X:::::X         v:::::v         v:::::v   ss::::::::::s       O:::::O     O:::::O\n";
	std::cout << "    X:::::X:::::X           v:::::v       v:::::v  ss:::::::::::::s      O:::::O     O:::::O\n";
	std::cout << "     X:::::::::X             v:::::v     v:::::v   s::::::ssss:::::s     O:::::O     O:::::O\n";
	std::cout << "     X:::::::::X              v:::::v   v:::::v     s:::::s  ssssss      O:::::O     O:::::O\n";
	std::cout << "    X:::::X:::::X              v:::::v v:::::v        s::::::s           O:::::O     O:::::O\n";
	std::cout << "   X:::::X X:::::X              v:::::v:::::v            s::::::s        O:::::O     O:::::O\n";
	std::cout << "XXX:::::X   X:::::XXX            v:::::::::v       ssssss   s:::::s      O::::::O   O::::::O\n";
	std::cout << "X::::::X     X::::::X             v:::::::v        s:::::ssss::::::s     O:::::::OOO:::::::O\n";
	std::cout << "X:::::X       X:::::X              v:::::v         s::::::::::::::s       OO:::::::::::::OO \n";
	std::cout << "X:::::X       X:::::X               v:::v           s:::::::::::ss          OO:::::::::OO   \n";
	std::cout << "XXXXXXX       XXXXXXX                vvv             sssssssssss              OOOOOOOOO     \n";
	std::cout << "\n";
	std::cout << "\n";
	std::cout << "\n";
	
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

			if (grid_array[i][j] == 0) {
				std::cout << " " << 'X';
			}
			else if (grid_array[i][j] == 10) {
				std::cout << " " << 'O';
			}
			else {
				std::cout << " " << grid_array[i][j];
			}
			
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


char turn_to_char(int turn) {

	char turn_char;

	// To convert the number into a representative char
	if (turn == 0)
		turn_char = 'X'; // X = 0
	else
		turn_char = 'O'; // O = 10

	return turn_char;
}



void choose(int grid_array[3][3], int turn) {

	int choice;
	char turn_char = turn_to_char(turn);


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

	// I summed the 1st & 2nd to compare with the 3rd times 2
	// as I countered bugs when comparing all three directly

	// 8 sequences
	for (int i = 0; i < 3; i++) {

		// 3 sequences, rows
		if ( (grid_array[i][0] + grid_array[i][1]) == (grid_array[i][2] * 2) )
			return true;

		// 3 sequences
		if ( (grid_array[0][i] + grid_array[1][i]) == (grid_array[2][i] * 2) )
			return true;
			
		
		// Check it once, as it not related to the loop
		if (i == 0) {

			// 1 sequence, decline diagonal
			if ( (grid_array[0][0] + grid_array[1][1]) == (grid_array[2][2] * 2) )
				return true;
	
			// 1 sequence, incline diagonal
			if ( (grid_array[2][0] + grid_array[1][1]) == (grid_array[0][2] * 2) )
				return true;
				
		}

	}
	return false;
}



void end_game(bool win, int turn) {

	char turn_char = turn_to_char(turn);

	// if any had won
	if (win == true) {
		std::cout << "The winner is " << turn_char << ", Congrats!\n";
	}
	else {
		std::cout << "It's a tie!\n";
	}

	int pause;
	std::cin >> pause;
}