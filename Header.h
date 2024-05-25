#pragma once

#include <iostream>
#include <vector>
#include <string>

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

		std::cout << "Chess board initiated. ";
		std::cout << std::endl;
	}

	void print_board() {

		std::cout << xLable;
		std::cout << xLine;

		for (int i = 7; i > -1; i--) {

			for (int j = 0; j < 8; j++) {
				std::cout << yLine;
				std::cout << board[i][j];
			}
			std::cout << yLine;
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

			if (iy == 1) { // white pawn
				board[ix][iy] = w_pawn;
			}

			if (iy == 6) { // black pawn
				board[ix][iy] = b_pawn;
			}

			ix++;
		}
	}

private:
	//std::vector<char> row;
	std::vector < std::vector <char> > board;

	std::string xLine =		"   -   -   -   -   -   -   -   -  \n";
	std::string xLable =	"   a   b   c   d   e   f   g   h  \n";
	std::string yLine =		" | ";

	char w_rook = 'R';
	char w_pawn = 'P';
	char w_queen = 'Q';
	char w_king = 'K';
	char w_bishop = 'B';
	char w_knight = "N";

	char b_rook = "r";
	char b_pawn = 'p';
	char b_queen = "q";
	char b_king = "k";
	char b_bishop = "b";
	char b_knight = "n";



	char cell = ' ';
};
