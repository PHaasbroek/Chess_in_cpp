#include "Header.h"


int main() {
    std::cout << "Hello, World!" << std::endl;
    
    std::vector < std::pair < int, int >> moves;

    My_Class chess;
    
    chess.print_board();
    chess.populate_initial_board();
    chess.print_board();

    chess.move_any_piece(2, 7, 3, 3);
    chess.print_board();
    moves = chess.queen_valid_moves(3, 3);


    std::cout << "Number of valid moves: " << moves.size() << std::endl;
    for (int i = 0; i < moves.size(); i++) {
        std::cout << moves[i].first << " " << moves[i].second << std::endl;
    }

    return 0;
}


