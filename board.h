#include <iostream>

#include "piece.h"

struct Stats;

class Board {
  public:
    std::vector<Piece> pieces;

    // Constructor
    Board();

    // Instance methods
    void printBoard();
    void passMove(std::string move, int side, Stats &gamestats);

  private:
};
