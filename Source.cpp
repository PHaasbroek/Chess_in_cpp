#include "Header.h"


int main() {
    std::cout << "Hello, World!" << std::endl;
    
    std::vector < std::pair < int, int >> moves;
    std::vector < std::pair < int, int >> base_vector;
    base_vector.push_back(std::make_pair(0, 0));
    base_vector.push_back(std::make_pair(0, 0));
    base_vector.push_back(std::make_pair(0, 1));
    base_vector.push_back(std::make_pair(1, 1));
    base_vector.push_back(std::make_pair(2, 2));
    base_vector.push_back(std::make_pair(3, 3));
    base_vector.push_back(std::make_pair(4, 4));
    base_vector.push_back(std::make_pair(0, 0));

    

    std::vector < std::pair < int, int >> subtract_vector;
    subtract_vector.push_back(std::make_pair(0, 0));
    subtract_vector.push_back(std::make_pair(0, 1));



    My_Class chess;
       
    chess.populate_initial_board();

    chess.move_any_piece(4, 0, 3, 3);
    chess.move_any_piece(0, 7, 2, 4); //move black rook to upper left corner of white king
    chess.move_any_piece(7, 7, 3, 4); //move black rook to above corner of white king

    chess.print_board();
    //chess.move_any_piece(4, 0, 2, 2);
    //chess.move_any_piece(0, 7, 0, 2);

    //chess.print_board();
    moves = chess.valid_moves(3, 3);

    //moves = chess.valid_moves(2, 2);

    std::cout << "Number of valid moves: " << moves.size() << std::endl;
    chess.print_pair_vector(moves);

    return 0;
}


