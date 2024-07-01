#pragma once

#include <iostream>
#include <vector>
#include <utility> // for the pair function
#include <string>

class My_Class
{
public:
	My_Class() {
		
		std::vector<char> row;

		for (int i = 0; i < 8; i++) {
			row.push_back(blank_cell);
		}

		for (int j = 0; j < 8; j++) {
			board.push_back(row);
		}
		
		std::cout << blank_cell << std::endl;
		std::cout << "Chess board initiated. ";
		std::cout << std::endl;
	}

	void print_board() {

		std::cout << xLable;
		std::cout << xLine;

		for (int iy = 7; iy > -1; iy--) {

			std::cout << " " << (iy + 1);

			for (int ix = 0; ix < 8; ix++) {
				std::cout << yLine;
				std::cout << board[ix][iy];
			}

			std::cout << yLine;
			std::cout << (iy + 1);
			std::cout << "\n";
			std::cout << xLine;
		}

		std::cout << xLable;
		std::cout << std::endl;
	}

	void populate_initial_board() {

		int iy = 0; //row lables
		int ix = 0; //column lables

		for (int i = 0; i < 64; i++) {
			if (ix > 7) {
				ix = 0;
				iy++;
			}

			// white side
			if (iy == 0) {

				if (ix == 0) 
					board[ix][iy] = w_rook;
				if (ix == 1) 
					board[ix][iy] = w_knight;
				if (ix == 2) 
					board[ix][iy] = w_bishop;
				if (ix == 3) 
					board[ix][iy] = w_queen;
				if (ix == 4)
					board[ix][iy] = w_king;
				if (ix == 5) 
					board[ix][iy] = w_bishop;
				if (ix == 6) 
					board[ix][iy] = w_knight;
				if (ix == 7)
					board[ix][iy] = w_rook;
			}

			if (iy == 1)  // white pawn
				board[ix][iy] = w_pawn;
			

			// black side
			if (iy == 7) {

				if (ix == 0)
					board[ix][iy] = b_rook;
				if (ix == 1)
					board[ix][iy] = b_knight;
				if (ix == 2)
					board[ix][iy] = b_bishop;
				if (ix == 3)
					board[ix][iy] = b_queen;
				if (ix == 4)
					board[ix][iy] = b_king;
				if (ix == 5)
					board[ix][iy] = b_bishop;
				if (ix == 6)
					board[ix][iy] = b_knight;
				if (ix == 7)
					board[ix][iy] = b_rook;
			}

			if (iy == 6) // black pawn
				board[ix][iy] = b_pawn;

			ix++;
		}
	}

	void move_any_piece(int start_x, int start_y, int end_x, int end_y) {
		// function for testing purposes
		// eliminate invalid selections
		if (start_x > 7)
			return;
		if (start_x < 0)
			return;
		if (start_y > 7)
			return;
		if (start_y < 0)
			return;
		if (end_x > 7)
			return;
		if (end_x < 0)
			return;
		if (end_y > 7)
			return;
		if (end_y < 0)
			return;
		if (start_x == end_x && start_y == end_y)
			return;

		board[end_x][end_y] = board[start_x][start_y];
		board[start_x][start_y] = blank_cell;
	}

	void move_piece(int start_x, int start_y, int end_x, int end_y) {

		bool valid_move = false;

		// eliminate invalid selections
		if (start_x > 7)
			return;
		if (start_x < 0)
			return;
		if (start_y > 7)
			return;
		if (start_y < 0)
			return;
		if (end_x > 7)
			return;
		if (end_x < 0)
			return;
		if (end_y > 7)
			return;
		if (end_y < 0)
			return;
		if (start_x == end_x && start_y == end_y)
			return;

		//valid_move = true;

		if (board[start_x][start_y] == w_bishop) {
			std::cout << "bishop selected" << std::endl;
			valid_move = bishop_movement_valid(start_x, start_y, end_x, end_y);
		}

		if (board[start_x][start_y] == w_rook) {
			std::cout << "rook selected" << std::endl;
			valid_move = rook_movement_valid(start_x, start_y, end_x, end_y);
		}

		if (valid_move) {
			board[end_x][end_y] = board[start_x][start_y];
			board[start_x][start_y] = blank_cell;
		}

		return;
	}

	bool king_movement_valid(int start_x, int start_y, int end_x, int end_y) {
		// now that I think of it, the Kings' movement is the most complex as it consideres all other pieces' attack paths. For this reason I will be leaving it for last. 

		if (board[end_x][end_y] == w_king || board[end_x][end_y] == b_king) {
			return false; //this should never happen, but writing it anyway. 
		}
	}

	bool is_white(char piece) {
		// NB: empty cells return false!

		if (piece == w_bishop)
			return true;
		if (piece == w_king)
			return true;
		if (piece == w_knight)
			return true;
		if (piece == w_pawn)
			return true;
		if (piece == w_queen)
			return true;
		if (piece == w_rook)
			return true;
		
		return false;
	}

	bool is_black(char piece) {

		if (piece == b_bishop)
			return true;
		if (piece == b_king)
			return true;
		if (piece == b_knight)
			return true;
		if (piece == b_pawn)
			return true;
		if (piece == b_queen)
			return true;
		if (piece == b_rook)
			return true;

		return false;
	}

	bool is_king(char piece) {
		if (piece == w_king)
			return true;
		if (piece == b_king)
			return true;

		return false;
	}

	std::vector < std::pair < int, int> > rook_valid_moves(int const start_x, int const start_y) {
		// the new rook function that returns the vector of 

		std::vector < std::pair < int, int> > valid_moves;

		bool is_white_piece = is_white(board[start_x][start_y]);

		int test_x;
		int test_y;

		test_x = start_x;
		test_y = start_y;

		for (int i = 0; i < 8; i++) {
			test_x++;

			if (test_x < 0 || test_x > 7 || test_y < 0 || test_y > 7) 
				break; //break when out of bounds

			if (board[test_x][test_y] == blank_cell) {
				valid_moves.push_back(std::make_pair(test_x, test_y));
			}
			else if (is_white(board[test_x][test_y]) == is_white_piece) {
				break; // same team => break the loop
			}
			else if (is_white(board[test_x][test_y]) != is_white_piece) {
				// if not a blank cell AND is of the other team, do this:

				if (is_king(board[test_x][test_y])) 
					break; // break if a King is encountered. 

				valid_moves.push_back(std::make_pair(test_x, test_y));
				break; // other team
			}
		}

		test_x = start_x;
		test_y = start_y;

		for (int i = 0; i < 8; i++) {
			test_x--;

			if (test_x < 0 || test_x > 7 || test_y < 0 || test_y > 7)
				break; //break when out of bounds

			if (board[test_x][test_y] == blank_cell) {
				valid_moves.push_back(std::make_pair(test_x, test_y));
			}
			else if (is_white(board[test_x][test_y]) == is_white_piece) {
				break; // same team => break the loop
			}
			else if (is_white(board[test_x][test_y]) != is_white_piece) {
				// if not a blank cell AND is of the other team, do this:

				if (is_king(board[test_x][test_y])) 
					break; // break if a King is encountered. 

				valid_moves.push_back(std::make_pair(test_x, test_y));
				break; // other team
			}
		}

		test_x = start_x;
		test_y = start_y;

		for (int i = 0; i < 8; i++) {
			test_y++;

			if (test_x < 0 || test_x > 7 || test_y < 0 || test_y > 7)
				break; //break when out of bounds

			if (board[test_x][test_y] == blank_cell) {
				valid_moves.push_back(std::make_pair(test_x, test_y));
			}
			else if (is_white(board[test_x][test_y]) == is_white_piece) {
				break; // same team => break the loop
			}
			else if (is_white(board[test_x][test_y]) != is_white_piece) {
				// if not a blank cell AND is of the other team, do this:

				if (is_king(board[test_x][test_y])) 
					break; // break if a King is encountered

				valid_moves.push_back(std::make_pair(test_x, test_y));
				break; // other team
			}
		}

		test_x = start_x;
		test_y = start_y;

		for (int i = 0; i < 8; i++) {
			test_y--;

			if (test_x < 0 || test_x > 7 || test_y < 0 || test_y > 7)
				break; //break when out of bounds

			if (board[test_x][test_y] == blank_cell) {
				valid_moves.push_back(std::make_pair(test_x, test_y));
			}
			else if (is_white(board[test_x][test_y]) == is_white_piece) {
				break; // same team => break the loop
			}
			else if (is_white(board[test_x][test_y]) != is_white_piece) {
				// if not a blank cell AND is of the other team, do this:

				if (is_king(board[test_x][test_y]))
					break; // break if a King is encountered. 

				valid_moves.push_back(std::make_pair(test_x, test_y));
				break; // other team
			}
		}

		return valid_moves;
	}

	std::vector < std::pair < int, int> > bishop_valid_moves(int const start_x, int const start_y) {

		std::vector < std::pair < int, int> > valid_moves;

		bool is_white_piece = is_white(board[start_x][start_y]);

		int test_x;
		int test_y;

		test_x = start_x;
		test_y = start_y;

		for (int i = 0; i < 8; i++) {
			test_x++;
			test_y++;

			if (test_x < 0 || test_x > 7 || test_y < 0 || test_y > 7)
				break; //break when out of bounds

			if (board[test_x][test_y] == blank_cell) {
				valid_moves.push_back(std::make_pair(test_x, test_y));
			}
			else if (is_white(board[test_x][test_y]) == is_white_piece) {
				break; // same team => break the loop
			}
			else if (is_white(board[test_x][test_y]) != is_white_piece) {
				// if not a blank cell AND is of the other team, do this:

				if (is_king(board[test_x][test_y])) {
					break; // break if a King is encountered. 
				}

				valid_moves.push_back(std::make_pair(test_x, test_y));
				break; // other team
			}
		}

		test_x = start_x;
		test_y = start_y;

		for (int i = 0; i < 8; i++) {
			test_x++;
			test_y--;

			if (test_x < 0 || test_x > 7 || test_y < 0 || test_y > 7)
				break; //break when out of bounds

			if (board[test_x][test_y] == blank_cell) {
				valid_moves.push_back(std::make_pair(test_x, test_y));
			}
			else if (is_white(board[test_x][test_y]) == is_white_piece) {
				break; // same team => break the loop
			}
			else if (is_white(board[test_x][test_y]) != is_white_piece) {
				// if not a blank cell AND is of the other team, do this:

				if (is_king(board[test_x][test_y])) {
					break; // break if a King is encountered. 
				}

				valid_moves.push_back(std::make_pair(test_x, test_y));
				break; // other team
			}
		}

		test_x = start_x;
		test_y = start_y;

		for (int i = 0; i < 8; i++) {
			test_x--;
			test_y++;

			if (test_x < 0 || test_x > 7 || test_y < 0 || test_y > 7)
				break; //break when out of bounds

			if (board[test_x][test_y] == blank_cell) {
				valid_moves.push_back(std::make_pair(test_x, test_y));
			}
			else if (is_white(board[test_x][test_y]) == is_white_piece) {
				break; // same team => break the loop
			}
			else if (is_white(board[test_x][test_y]) != is_white_piece) {
				// if not a blank cell AND is of the other team, do this:

				if (is_king(board[test_x][test_y])) {
					break; // break if a King is encountered. 
				}

				valid_moves.push_back(std::make_pair(test_x, test_y));
				break; // other team
			}
		}

		test_x = start_x;
		test_y = start_y;

		for (int i = 0; i < 8; i++) {
			test_x--;
			test_y--;

			if (test_x < 0 || test_x > 7 || test_y < 0 || test_y > 7)
				break; //break when out of bounds

			if (board[test_x][test_y] == blank_cell) {
				valid_moves.push_back(std::make_pair(test_x, test_y));
			}
			else if (is_white(board[test_x][test_y]) == is_white_piece) {
				break; // same team => break the loop
			}
			else if (is_white(board[test_x][test_y]) != is_white_piece) {
				// if not a blank cell AND is of the other team, do this:

				if (is_king(board[test_x][test_y])) {
					break; // break if a King is encountered. 
				}

				valid_moves.push_back(std::make_pair(test_x, test_y));
				break; // other team
			}
		}

		return valid_moves;
	}

	std::vector < std::pair < int, int> > queen_valid_moves(int const start_x, int const start_y) {
		std::vector < std::pair < int, int> > valid_moves = (rook_valid_moves(start_x, start_y));
		std::vector < std::pair < int, int> > bishop_moves = bishop_valid_moves(start_x, start_y);

		for (int i = 0; i < bishop_moves.size(); i++) {
			valid_moves.push_back(bishop_moves[i]);
		}
		return valid_moves;
	}

	std::vector < std::pair < int, int> > pawn_valid_moves(int const start_x, int const start_y) {
		
		std::vector < std::pair < int, int> > valid_moves;

		bool is_white_piece = is_white(board[start_x][start_y]);

		int test_x;
		int test_y;

		test_x = start_x;
		test_y = start_y;

		for (int i = 0; i < 2; i++) {
			if (is_white_piece) {
				test_y++;

				if (test_x < 0 || test_x > 7 || test_y < 0 || test_y > 7)
					break; //break when out of bounds

				if (board[test_x][test_y] == blank_cell)
					valid_moves.push_back(std::make_pair(test_x, test_y));

				if (board[test_x][test_y] != blank_cell)
					break;

				if (start_y != 1)
					break;
			}

			if (!is_white_piece) {
				test_y--;

				if (test_x < 0 || test_x > 7 || test_y < 0 || test_y > 7)
					break; //break when out of bounds

				if (board[test_x][test_y] == blank_cell)
					valid_moves.push_back(std::make_pair(test_x, test_y));

				if (board[test_x][test_y] != blank_cell)
					break;

				if (start_y != 6)
					break;
			}
		}

		test_x = start_x;
		test_y = start_y;

		for (int i = 0; i < 1; i++) {
			if (is_white_piece) {
				test_x++;
				test_y++;

				if (test_x < 0 || test_x > 7 || test_y < 0 || test_y > 7)
					break; //break when out of bounds

				if (is_black(board[test_x][test_y]))
					valid_moves.push_back(std::make_pair(test_x, test_y));
			}

			if (!is_white_piece) {
				test_x++;
				test_y--;

				if (test_x < 0 || test_x > 7 || test_y < 0 || test_y > 7)
					break; //break when out of bounds

				if (is_white(board[test_x][test_y]))
					valid_moves.push_back(std::make_pair(test_x, test_y));
			}
		}

		test_x = start_x;
		test_y = start_y;

		for (int i = 0; i < 1; i++) {
			if (is_white_piece) {
				test_x--;
				test_y++;

				if (test_x < 0 || test_x > 7 || test_y < 0 || test_y > 7)
					break; //break when out of bounds

				if (is_black(board[test_x][test_y]))
					valid_moves.push_back(std::make_pair(test_x, test_y));
			}

			if (!is_white_piece) {
				test_x--;
				test_y--;

				if (test_x < 0 || test_x > 7 || test_y < 0 || test_y > 7)
					break; //break when out of bounds

				if (is_white(board[test_x][test_y]))
					valid_moves.push_back(std::make_pair(test_x, test_y));
			}
		}

		return valid_moves;
	}


	bool rook_movement_valid(int start_x, int start_y, int end_x, int end_y) {
		// this function is no longer used

		int test_x; 
		int test_y; 

		test_x = start_x;
		test_y = start_y;

		for (int i = 0; i < 8; i++) {
			test_x++;

			if (test_x < 0 || test_x > 7 || test_y < 0 || test_y > 7)
				break; //break when out of bounds

			if (test_x == end_x && test_y == end_y) {
				return true;
			}

			if (board[test_x][test_y] != blank_cell) {
				break; // breaks the loop if a piece is met
			}
		}

		test_x = start_x;
		test_y = start_y;

		for (int i = 0; i < 8; i++) {
			test_x--;

			if (test_x < 0 || test_x > 7 || test_y < 0 || test_y > 7)
				break; //break when out of bounds

			if (test_x == end_x && test_y == end_y) {
				return true;
			}

			if (board[test_x][test_y] != blank_cell) {
				break; // breaks the loop if a piece is met
			}
		}

		test_x = start_x;
		test_y = start_y;

		for (int i = 0; i < 8; i++) {
			test_y++;

			if (test_x < 0 || test_x > 7 || test_y < 0 || test_y > 7)
				break; //break when out of bounds

			if (test_x == end_x && test_y == end_y) {
				return true;
			}

			if (board[test_x][test_y] != blank_cell) {
				break; // breaks the loop if a piece is met
			}
		}

		test_x = start_x;
		test_y = start_y;

		for (int i = 0; i < 8; i++) {
			test_y--;

			if (test_x < 0 || test_x > 7 || test_y < 0 || test_y > 7)
				break; //break when out of bounds

			if (test_x == end_x && test_y == end_y) {
				return true;
			}

			if (board[test_x][test_y] != blank_cell) {
				break; // breaks the loop if a piece is met
			}
		}

		std::cout << "invalid move" << std::endl;
		return false;
	}

	bool bishop_movement_valid(int start_x, int start_y, int end_x, int end_y) {
		int test_x = start_x;
		int test_y = start_y;

		for (int i = 0; i < 8; i++) {
			test_x++;
			test_y++;

			if (test_x < 0 || test_x > 7 || test_y < 0 || test_y > 7)
				break; //break when out of bounds

			if (test_x == end_x && test_y == end_y) {
				return true;
			}
		}

		test_x = start_x;
		test_y = start_y;

		for (int i = 0; i < 8; i++) {
			test_x--;
			test_y++;

			if (test_x < 0 || test_x > 7 || test_y < 0 || test_y > 7)
				break; //break when out of bounds

			if (test_x == end_x && test_y == end_y) {
				return true;
			}
		}

		test_x = start_x;
		test_y = start_y;

		for (int i = 0; i < 8; i++) {
			test_x--;
			test_y--;

			if (test_x < 0 || test_x > 7 || test_y < 0 || test_y > 7)
				break; //break when out of bounds

			if (test_x == end_x && test_y == end_y) {
				return true;
			}
		}

		test_x = start_x;
		test_y = start_y;

		for (int i = 0; i < 8; i++) {
			test_x++;
			test_y--;
			
			if (test_x < 0 || test_x > 7 || test_y < 0 || test_y > 7)
				break; //break when out of bounds

			if (test_x == end_x && test_y == end_y) {
				return true;
			}
		}

		std::cout << "invalid move" << std::endl;
		return false;
	}


private:
	//std::vector<char> row;
	std::vector < std::vector <char> > board;

	std::string xLine =		"     -   -   -   -   -   -   -   -\n";
	std::string xLable =	"     a   b   c   d   e   f   g   h  \n";
	std::string yLine =		" | ";
	
	char w_rook = 'R';
	char w_pawn = 'P';
	char w_queen = 'Q';
	char w_king = 'K';
	char w_bishop = 'B';
	char w_knight = 'N';

	char b_rook = 'r';
	char b_pawn = 'p';
	char b_queen = 'q';
	char b_king = 'k';
	char b_bishop = 'b';
	char b_knight = 'n';
	
	char blank_cell = ' ';

	int move_number;

};
