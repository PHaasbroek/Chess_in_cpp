#pragma once

#include <iostream>
#include <vector>

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

		std::cout << "   -   -   -   -   -   -   -   -  \n";

		for (int i = 0; i < 8; i++) {

			for (int j = 0; j < 8; j++) {
				std::cout << " | ";
				std::cout << board[i][j];
			}
			std::cout << " | \n";
			std::cout << "   -   -   -   -   -   -   -   -  \n";
		}
		std::cout << std::endl;
	}

private:
	//std::vector<char> row;
	std::vector < std::vector <char> > board;
	char cell = ' ';
};
