#include "Header.h"


int main()
{
    My_Class chess;

	std::string user_input{ "No Input" };

	while (true)
	{
		while (true)
		{
			std::cout << "Select a piece using it's coordinates (enter 'x' to exit): " << std::endl;
			std::cin >> user_input;

			// If the user wants to exit
			if (user_input == "x")
			{
				break;
			}
			chess.select_piece(user_input);
			//chess.move_piece(user_input);
			chess.print_board();
		}
		if (user_input == "x")
		{
			break;
		}
	}
    return 0;
}