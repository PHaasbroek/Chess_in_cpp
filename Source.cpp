#include "Header.h"


int main() {
    std::cout << "Hello, World!" << std::endl;
    
    std::vector < std::pair < int, int >> moves;

    My_Class chess;
    
    chess.print_board();

    chess.populate_initial_board();

    chess.print_board();

 


    return 0;
}


