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

	void populate_board_test() {

		int iy = 0; //row lables
		int ix = 0; //column lables

		for (int i = 0; i < 64; i++) {

			if (iy > 7) {
				iy = 0;
				ix++;
			}

			board[ix][iy] = std::to_string(ix)[0];
			iy++;

		}
	}

private:
	//std::vector<char> row;
	std::vector < std::vector <char> > board;

	std::string xLine =		"   -   -   -   -   -   -   -   -  \n";
	std::string xLable =	"   a   b   c   d   e   f   g   h  \n";
	std::string yLine =		" | ";

	char cell = ' ';
};
