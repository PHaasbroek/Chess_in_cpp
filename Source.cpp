#include "Header.h"


int main() {
    std::cout << "Hello, World!" << std::endl;
    
    My_Class chess;
    
    chess.print_board();

    chess.populate_initial_board();

    chess.print_board();

    chess.move_piece(0, 0, 0, 2);
    chess.print_board();
    
    chess.move_piece(2, 0, 8, 6);
    chess.print_board();

    //std::cout << chess.yLable(0) << std::endl;

    return 0;
}


