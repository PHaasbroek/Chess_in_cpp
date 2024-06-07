#include "Header.h"


int main() {
    std::cout << "Hello, World!" << std::endl;
    
    My_Class chess;
    
    chess.print_board();

    chess.populate_initial_board();

    chess.print_board();

    chess.move_piece(2, 0, 6, 4);
    chess.print_board();
    chess.move_piece(6, 4, 4, 6);
    chess.print_board();    
    chess.move_piece(4, 6, 1, 3);
    chess.print_board();


    //std::cout << chess.yLable(0) << std::endl;

    return 0;
}


