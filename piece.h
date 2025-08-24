#pragma once

#include <iostream>
#include <string>
#include <vector>

class Board;

class Piece {
 private:
  Board* local_board;
  int file;
  int rank;
  enum Side : char { black, white };
  Side side;

  void disambiguate(std::string move, std::vector<std::string>& possible_moves);
  Piece(Board* board, int file, int rank, Side side);
  std::vector<std::string> possibleMoves();

 public:
  void makeMove(Piece* piece, int fin_file, int fin_rank, int castle,
                bool taking);
};
