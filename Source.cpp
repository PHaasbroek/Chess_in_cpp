#include "Header.h"


int main() {
    std::cout << "Hello, World!" << std::endl;
    
    My_Class chess;
    
    chess.print_board();

    chess.populate_board_test();

    chess.print_board();
    return 0;
}


