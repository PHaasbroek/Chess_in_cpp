#include "Header.h"


int main() {
    std::cout << "Hello, World!" << std::endl;
    
    std::vector < std::pair < int, int >> moves;

    My_Class chess;
    
    chess.print_board();
    chess.populate_initial_board();
    chess.print_board();

    //chess.move_any_piece(2, 7, 3, 3);
    //chess.print_board();
    chess.move_any_piece(0, 6, 3, 4);
    chess.move_any_piece(3, 1, 2, 3);

    chess.print_board();
    moves = chess.pawn_valid_moves(5, 1);


    std::cout << "Number of valid moves: " << moves.size() << std::endl;
    for (int i = 0; i < moves.size(); i++) {
        std::cout << moves[i].first << " " << moves[i].second << std::endl;
    }

    return 0;
}


