#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>


class My_Class
{
public:
	My_Class() {
		
		std::vector<char> row;

		for (int i = 0; i < 8; i++) {
			row.push_back(' ');
		}

		for (int j = 0; j < 8; j++) {
			board.push_back(row);
		}
		
		std::cout << cell << std::endl;
		std::cout << std::endl;

		populate_initial_board();
		print_board();
	}


	void print_board() {

		std::cout << x_lable;
		std::cout << x_line;

		for (int iy = 7; iy > -1; iy--) {

			std::cout << " ";
			std::cout << (iy + 1);

			for (int ix = 0; ix < 8; ix++) {
				std::cout << yLine;
				std::cout << board[ix][iy];
			}

			std::cout << yLine;
			std::cout << (iy + 1);
			std::cout << "\n";
			std::cout << x_line;

		}
		std::cout << x_lable;
		std::cout << std::endl;
	}


	void populate_initial_board()
	{
		bool enabled_board = false;

		char piece = w_king;

		board[4][3] = piece;

		board[5][3] = piece;
		board[3][3] = piece;
		board[4][4] = piece;
		board[4][2] = piece;

		board[0][0] = piece;
		board[0][7] = piece;
		board[7][0] = piece;
		board[7][7] = piece;

		board[1][5] = piece;

		if (enabled_board)
		{
			int iy = 0; //row lables
			int ix = 0; //column lables

			for (int i = 0; i < 64; i++)
			{
				if (ix > 7)
				{
					ix = 0;
					iy++;
				}
				// white pieces
				board[0][0] = w_rook;
				board[1][0] = w_knight;
				board[2][0] = w_bishop;
				board[3][0] = w_queen;
				board[4][0] = w_king;
				board[5][0] = w_bishop;
				board[6][0] = w_knight;
				board[7][0] = w_rook;

				// black piecs
				board[0][7] = b_rook;
				board[1][7] = b_knight;
				board[2][7] = b_bishop;
				board[3][7] = b_queen;
				board[4][7] = b_king;
				board[5][7] = b_bishop;
				board[6][7] = b_knight;
				board[7][7] = b_rook;

				// white pawns
				if (iy == 1)
					board[ix][iy] = w_pawn;

				// black pawns
				if (iy == 6)
					board[ix][iy] = b_pawn;

				ix++;
			}
		}
		else
		{
		std::cout << "Board Setup Disabled!" << std::endl;
		}
	}


	char identify_chess_piece(std::string input)
	{
		int x_index = calculate_coordinate_x_index(input);
		int y_index = calculate_coordinate_y_index(input);

		char object = board[x_index][y_index];
		//char object = 't';
		return object;
	}


	int calculate_coordinate_x_index(std::string input)
	{
		int x_index = input[0] - 'a'; // Converts 'a'-'h' to 0-7 (zero-based index)
		return x_index;
	}


	int calculate_coordinate_y_index(std::string input)
	{
		int y_index = input[1] - '1'; // Converts '1'-'8' to 1-8
		return y_index;
	}


	std::string coordinates_from_indices(int x_index, int y_index)
	{
		char x_char = 'a' + x_index;  // Convert index to 'a'-'h'
		char y_char = '1' + y_index;  // Convert index to '1'-'8'
		return std::string(1, x_char) + std::string(1, y_char); // Concatenate strings
	}



	void move_piece(char input)
	{
		if (input == w_rook)
			std::cout << w_rook << std::endl;
	}


	void move_piece(std::string current_position)
	{
		std::string new_position;
		while (true)
		{
			std::cout << "Select a location using it's coordinates: " << std::endl;
			std::cin >> new_position;
			if (!does_coordinate_exist(new_position))
			{
				std::cout << "Coordinate does not exists, choose a new one: " << new_position << std::endl;
			}
			else
			{
				int current_x_index = calculate_coordinate_x_index(current_position);
				int current_y_index = calculate_coordinate_y_index(current_position);

				int new_x_index = calculate_coordinate_x_index(new_position);
				int new_y_index = calculate_coordinate_y_index(new_position);

				// create piece at new location
				board[new_x_index][new_y_index] = board[current_x_index][current_y_index];

				// remove piece from previous location
				board[current_x_index][current_y_index] = ' ';
				break;
			}
			
		}
	}


	void select_piece(std::string input)
	{
		while (true)
		{
			if (!does_coordinate_exist(input))
			{
				std::cout << "Coordinate does not exists, choose a new one: " << input << std::endl;
			}
			else
			{
				char chess_piece = identify_chess_piece(input);

				if (chess_piece == ' ')
				{
					std::cout << "There is nothing on: " << input << std::endl;
				}
				else
				{
					selected_piece = chess_piece;
					selected_coordinate = input;
					std::cout << "Selected: " << selected_piece << std::endl;
					calculate_valid_moves(selected_piece);
					break;
				}
			}
			std::cout << "Select a valid piece using it's coordinates: ";
			std::cin >> input;
		}
	}


	bool select_coordinates_to_move_to()
	{
		while (true)
		{
			std::string user_input;
			std::cin >> user_input;

			bool valid_location_in_vector = true;

			if (valid_location_in_vector)
				break;
			else
				std::cout << "Select valid coordinates:: ";
		}

	}


	void calculate_valid_moves(char selected_piece)
	{
		char lowercase_piece = std::tolower(selected_piece);
		switch (lowercase_piece) {
		case 'k':
			king();
			break;
		case 'q':
			queen();
			break;
		case 'r':
			rook();
			break;
		case 'b':
			bishop();
			break;
		case 'n':
			knight();
			break;
		case 'p':
			pawn();
			break;
		}

	}


	void king()
	{
		rook_with_a_range_of_one();
		bishop_with_a_range_of_one();
	}

	void queen()
	{
		rook();
		bishop();
	}

	void rook()
	{
		int available_moves_up_right{ 0 };
		int available_moves_up_left{ 0 };
		int available_moves_down_right{ 0 };
		int available_moves_down_left{ 0 };

		int current_x_index = calculate_coordinate_x_index(selected_coordinate);
		int current_y_index = calculate_coordinate_y_index(selected_coordinate);

		int x_index = current_x_index;
		int y_index = current_y_index;

		// Calculate available upwards movements ---------------------------------------------------
		x_index = current_x_index;
		y_index = current_y_index;

		y_index++;
		while (y_index <= 7 && board[x_index][y_index] == ' ')
		{
			valid_coordinates.push_back(coordinates_from_indices(x_index, y_index));
			y_index++;
			available_moves_up_right++;
		}
		y_index--;

		// Calculate available downwards movements -------------------------------------------------
		x_index = current_x_index;
		y_index = current_y_index;

		y_index--;
		while (y_index >= 0 && board[x_index][y_index] == ' ')
		{
			valid_coordinates.push_back(coordinates_from_indices(x_index, y_index));
			y_index--;
			available_moves_up_left++;
		}
		y_index++;

		// Calculate available left movements -----------------------------------------------------
		x_index = current_x_index;
		y_index = current_y_index;

		x_index--;
		while (x_index >= 0 && board[x_index][y_index] == ' ')
		{
			valid_coordinates.push_back(coordinates_from_indices(x_index, y_index));
			x_index--;
			available_moves_down_right++;
		}
		x_index++;

		// Calculate available right movements ----------------------------------------------------
		x_index = current_x_index;
		y_index = current_y_index;

		x_index++;
		while (x_index <= 7 && board[x_index][y_index] == ' ')
		{
			valid_coordinates.push_back(coordinates_from_indices(x_index, y_index));
			x_index++;
			available_moves_down_left++;
		}
		x_index--;

		// -----------------------------------------------------------------------------------------

		for (const auto& coordinate : valid_coordinates) {
			std::cout << coordinate << std::endl;
		}

		std::cout << available_moves_up_right << " moves up" << std::endl;
		std::cout << available_moves_up_left << " moves down" << std::endl;
		std::cout << available_moves_down_right << " moves left" << std::endl;
		std::cout << available_moves_down_left << " moves right" << std::endl;
	}


	void printNonSpaceWithCoordinates() {
		for (size_t i = 0; i < board.size(); ++i) {
			for (size_t j = 0; j < board[i].size(); ++j) {
				if (board[i][j] != ' ') {
					std::cout << "Character: " << board[i][j] << " at (" << i << ", " << j << ")\n";
				}
			}
		}
	}


	void bishop()
		{	
		int available_moves_up_right{ 0 };
		int available_moves_up_left{ 0 };
		int available_moves_down_right{ 0 };
		int available_moves_down_left{ 0 };

		int current_x_index = calculate_coordinate_x_index(selected_coordinate);
		int current_y_index = calculate_coordinate_y_index(selected_coordinate);

		int x_index = current_x_index;
		int y_index = current_y_index;

		// -----------------------------------------------------------------------------------------
		// Calculate available upwards to the right movements
		// -----------------------------------------------------------------------------------------
		x_index = current_x_index;
		y_index = current_y_index;
		
		x_index++;
		y_index++;
		while ((y_index <= 7 && x_index <= 7) && (board[x_index][y_index] == ' '))
		{
			valid_coordinates.push_back(coordinates_from_indices(x_index, y_index));
			
			x_index++;
			y_index++;
			available_moves_up_right++;
		}
		y_index--;
		x_index--;


		// -----------------------------------------------------------------------------------------
		// Calculate available upwards to the left movements
		// -----------------------------------------------------------------------------------------

		// Calculate available upwards movements ---------------------------------------------------
		x_index = current_x_index;
		y_index = current_y_index;

		x_index--;
		y_index++;
		while ((y_index <= 7 && x_index >= 0) && (board[x_index][y_index] == ' '))
		{
			valid_coordinates.push_back(coordinates_from_indices(x_index, y_index));
			x_index--;
			y_index++;
			available_moves_up_left++;
		}
		x_index++;
		y_index--;

		// -----------------------------------------------------------------------------------------
		// Calculate available downwards to the right movements
		// -----------------------------------------------------------------------------------------


		x_index = current_x_index;
		y_index = current_y_index;

		x_index++;
		y_index--;
		while ((y_index >= 0 && x_index <= 7) && (board[x_index][y_index] == ' '))
		{
			valid_coordinates.push_back(coordinates_from_indices(x_index, y_index));
			x_index++;
			y_index--;
			available_moves_down_right++;
		}
		x_index--;
		y_index++;

		// -----------------------------------------------------------------------------------------
		// Calculate available downwards to the left movements
		// -----------------------------------------------------------------------------------------
		x_index = current_x_index;
		y_index = current_y_index;

		x_index--;
		y_index--;
		while ((y_index >= 0 && x_index >= 0) && (board[x_index][y_index] == ' '))
		{
			valid_coordinates.push_back(coordinates_from_indices(x_index, y_index));
			x_index--;
			y_index--;
			available_moves_down_left++;
		}
		x_index++;
		y_index++;
		// -----------------------------------------------------------------------------------------

		for (const auto& coordinate : valid_coordinates) {
			std::cout << coordinate << std::endl;
		}

		std::cout << available_moves_up_right << " moves up right" << std::endl;
		std::cout << available_moves_up_left << " moves up left" << std::endl;
		std::cout << available_moves_down_right << " moves down right" << std::endl;
		std::cout << available_moves_down_left << " moves down left" << std::endl;
	}

	void rook_with_a_range_of_one()
	{
		int available_moves_up_right{ 0 };
		int available_moves_up_left{ 0 };
		int available_moves_down_right{ 0 };
		int available_moves_down_left{ 0 };

		int current_x_index = calculate_coordinate_x_index(selected_coordinate);
		int current_y_index = calculate_coordinate_y_index(selected_coordinate);

		int x_index = current_x_index;
		int y_index = current_y_index;

		// Calculate available upwards movements ---------------------------------------------------
		x_index = current_x_index;
		y_index = current_y_index;

		y_index++;
		if (y_index <= 7 && board[x_index][y_index] == ' ')
		{
			valid_coordinates.push_back(coordinates_from_indices(x_index, y_index));
			y_index++;
			available_moves_up_right++;
		}
		y_index--;

		// Calculate available downwards movements -------------------------------------------------
		x_index = current_x_index;
		y_index = current_y_index;

		y_index--;
		if (y_index >= 0 && board[x_index][y_index] == ' ')
		{
			valid_coordinates.push_back(coordinates_from_indices(x_index, y_index));
			y_index--;
			available_moves_up_left++;
		}
		y_index++;

		// Calculate available left movements -----------------------------------------------------
		x_index = current_x_index;
		y_index = current_y_index;

		x_index--;
		if (x_index >= 0 && board[x_index][y_index] == ' ')
		{
			valid_coordinates.push_back(coordinates_from_indices(x_index, y_index));
			x_index--;
			available_moves_down_right++;
		}
		x_index++;

		// Calculate available right movements ----------------------------------------------------
		x_index = current_x_index;
		y_index = current_y_index;

		x_index++;
		if (x_index <= 7 && board[x_index][y_index] == ' ')
		{
			valid_coordinates.push_back(coordinates_from_indices(x_index, y_index));
			x_index++;
			available_moves_down_left++;
		}
		x_index--;

		// -----------------------------------------------------------------------------------------

		for (const auto& coordinate : valid_coordinates) {
			std::cout << coordinate << std::endl;
		}

		std::cout << available_moves_up_right << " moves up" << std::endl;
		std::cout << available_moves_up_left << " moves down" << std::endl;
		std::cout << available_moves_down_right << " moves left" << std::endl;
		std::cout << available_moves_down_left << " moves right" << std::endl;
	}

	void bishop_with_a_range_of_one()
	{
		int available_moves_up_right{ 0 };
		int available_moves_up_left{ 0 };
		int available_moves_down_right{ 0 };
		int available_moves_down_left{ 0 };

		int current_x_index = calculate_coordinate_x_index(selected_coordinate);
		int current_y_index = calculate_coordinate_y_index(selected_coordinate);

		int x_index = current_x_index;
		int y_index = current_y_index;

		// -----------------------------------------------------------------------------------------
		// Calculate available upwards to the right movements
		// -----------------------------------------------------------------------------------------
		x_index = current_x_index;
		y_index = current_y_index;

		x_index++;
		y_index++;
		if ((y_index <= 7 && x_index <= 7) && (board[x_index][y_index] == ' '))
		{
			valid_coordinates.push_back(coordinates_from_indices(x_index, y_index));

			x_index++;
			y_index++;
			available_moves_up_right++;
		}
		y_index--;
		x_index--;


		// -----------------------------------------------------------------------------------------
		// Calculate available upwards to the left movements
		// -----------------------------------------------------------------------------------------

		// Calculate available upwards movements ---------------------------------------------------
		x_index = current_x_index;
		y_index = current_y_index;

		x_index--;
		y_index++;
		if ((y_index <= 7 && x_index >= 0) && (board[x_index][y_index] == ' '))
		{
			valid_coordinates.push_back(coordinates_from_indices(x_index, y_index));
			x_index--;
			y_index++;
			available_moves_up_left++;
		}
		x_index++;
		y_index--;

		// -----------------------------------------------------------------------------------------
		// Calculate available downwards to the right movements
		// -----------------------------------------------------------------------------------------


		x_index = current_x_index;
		y_index = current_y_index;

		x_index++;
		y_index--;
		if ((y_index >= 0 && x_index <= 7) && (board[x_index][y_index] == ' '))
		{
			valid_coordinates.push_back(coordinates_from_indices(x_index, y_index));
			x_index++;
			y_index--;
			available_moves_down_right++;
		}
		x_index--;
		y_index++;

		// -----------------------------------------------------------------------------------------
		// Calculate available downwards to the left movements
		// -----------------------------------------------------------------------------------------
		x_index = current_x_index;
		y_index = current_y_index;

		x_index--;
		y_index--;
		if ((y_index >= 0 && x_index >= 0) && (board[x_index][y_index] == ' '))
		{
			valid_coordinates.push_back(coordinates_from_indices(x_index, y_index));
			x_index--;
			y_index--;
			available_moves_down_left++;
		}
		x_index++;
		y_index++;
		// -----------------------------------------------------------------------------------------

		for (const auto& coordinate : valid_coordinates) {
			std::cout << coordinate << std::endl;
		}

		std::cout << available_moves_up_right << " moves up right" << std::endl;
		std::cout << available_moves_up_left << " moves up left" << std::endl;
		std::cout << available_moves_down_right << " moves down right" << std::endl;
		std::cout << available_moves_down_left << " moves down left" << std::endl;
	}


	void knight()
	{
		;
	}


	void pawn()
	{
		;
	}


	bool does_coordinate_exist(const std::string& coordinate)
	{
		if (coordinate.length() != 2) return false;
		char col = coordinate[0];
		char row = coordinate[1];

		return (col >= 'a' && col <= 'h') && (row >= '1' && row <= '8');
	}


private:
	//std::vector<char> row;
	std::vector < std::vector <char> > board;
	std::vector<std::string> valid_coordinates;

	std::string x_line =		"     -   -   -   -   -   -   -   -\n";
	std::string x_lable =	"     a   b   c   d   e   f   g   h  \n";
	std::string yLine =		" | ";

	char selected_piece = ' ';
	std::string selected_coordinate = "";
	
	char w_king = 'K';
	char w_queen = 'Q';
	char w_rook = 'R';
	char w_bishop = 'B';
	char w_knight = 'N';
	char w_pawn = 'P';
	
	
	char b_king = 'k';
	char b_queen = 'q';
	char b_rook = 'r';
	char b_bishop = 'b';
	char b_knight = 'n';
	char b_pawn = 'p';

	char cell = ' ';
};
