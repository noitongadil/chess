#include <iostream>
#include <string>  // for strings

#include "board.h"

Piece::Piece(Board* board, int rank, int file, Side side)
    : local_board(board),
      rank(rank),
      file(file),
      side(side) {}

void Piece::disambiguate(std::string move,
                         std::vector<std::string>& possible_moves) {
  move.insert(1, 1, file + 'a');
  possible_moves.push_back(move);
  move.insert(2, std::to_string(rank + 1));
  possible_moves.push_back(move);
}

std::vector<std::string> Piece::possibleMoves() {
  std::vector<std::string> possible_moves;
  std::string move;

  if (type == 'P') {
    if (side == 0) {
      if (rank == 1) {
        move = file + 'a';
        move += std::to_string(rank + 3);
        possible_moves.push_back(move);
      }
      move = file + 'a';
      move += std::to_string(rank + 2);
      possible_moves.push_back(move);

      // taking
      move = file + 'a';
      move += 'x';
      move += file + 1 + 'a';
      move += std::to_string(rank + 2);
      possible_moves.push_back(move);

      move = file + 'a';
      move += 'x';
      move += file - 1 + 'a';
      move += std::to_string(rank + 2);
      possible_moves.push_back(move);
    }

    if (side == 1) {
      if (rank == 6) {
        move = file + 'a';
        move += std::to_string(rank - 1);
        possible_moves.push_back(move);
      }
      move = file + 'a';
      move += std::to_string(rank);
      possible_moves.push_back(move);

      // taking
      move = file + 'a';
      move += 'x';
      move += file + 1 + 'a';
      move += std::to_string(rank);
      possible_moves.push_back(move);

      move = file + 'a';
      move += 'x';
      move += file - 1 + 'a';
      move += std::to_string(rank);
      possible_moves.push_back(move);
    }
  }

  // King
  if (type == 'K') {
    // right
    if (file < 7) {
      if (!isBlocked(side, file + 1, rank)) {
        move = 'K';
        move += file + 1 + 'a';
        move += std::to_string(rank + 1);
        possible_moves.push_back(move);
        // taking
        move.insert(1, 1, 'x');
        possible_moves.push_back(move);
      }

      // right up
      if (rank < 7) {
        if (!isBlocked(side, file + 1, rank + 1)) {
          move = 'K';
          move += file + 1 + 'a';
          move += std::to_string(rank + 2);
          possible_moves.push_back(move);
          // taking
          move.insert(1, 1, 'x');
          possible_moves.push_back(move);
        }
      }

      // right down
      if (rank > 0) {
        if (!isBlocked(side, file + 1, rank - 1)) {
          move = 'K';
          move += file + 1 + 'a';
          move += std::to_string(rank);
          possible_moves.push_back(move);
          // taking
          move.insert(1, 1, 'x');
          possible_moves.push_back(move);
        }
      }
    }

    // up
    if (rank < 7) {
      if (!isBlocked(side, file, rank + 1)) {
        move = 'K';
        move += file + 'a';
        move += std::to_string(rank + 2);
        possible_moves.push_back(move);
        // taking
        move.insert(1, 1, 'x');
        possible_moves.push_back(move);
      }
    }

    // down
    if (rank > 0) {
      if (!isBlocked(side, file, rank - 1)) {
        move = 'K';
        move += file + 'a';
        move += std::to_string(rank);
        possible_moves.push_back(move);
        // taking
        move.insert(1, 1, 'x');
        possible_moves.push_back(move);
      }
    }

    // left
    if (file > 0) {
      if (!isBlocked(side, file - 1, rank)) {
        move = 'K';
        move += file - 1 + 'a';
        move += std::to_string(rank + 1);
        possible_moves.push_back(move);
        // taking
        move.insert(1, 1, 'x');
        possible_moves.push_back(move);
      }

      // left up
      if (rank < 7) {
        if (!isBlocked(side, file - 1, rank + 1)) {
          move = 'K';
          move += file - 1 + 'a';
          move += std::to_string(rank + 2);
          possible_moves.push_back(move);
          // taking
          move.insert(1, 1, 'x');
          possible_moves.push_back(move);
        }
      }
    }

    // left down
    if (rank > 0) {
      if (!isBlocked(side, file - 1, rank - 1)) {
        move = 'K';
        move += file - 1 + 'a';
        move += std::to_string(rank);
        possible_moves.push_back(move);
        // taking
        move.insert(1, 1, 'x');
        possible_moves.push_back(move);
      }
    }

    // castling
    move = "O-O-O";
    possible_moves.push_back(move);
    move = "O-O";
    possible_moves.push_back(move);
  }

  // Knight
  if (type == 'N') {
    // up right
    if (file + 1 < 8 && rank + 2 < 8) {
      move = 'N';
      move += file + 1 + 'a';
      move += std::to_string(rank + 3);
      possible_moves.push_back(move);
      disambiguate(move, possible_moves);
      // taking
      move.insert(1, 1, 'x');
      possible_moves.push_back(move);
      disambiguate(move, possible_moves);
    }

    // down right
    if (file + 1 < 8 && rank - 2 >= 0) {
      move = 'N';
      move += file + 1 + 'a';
      move += std::to_string(rank - 1);
      possible_moves.push_back(move);
      disambiguate(move, possible_moves);
      // taking
      move.insert(1, 1, 'x');
      possible_moves.push_back(move);
      disambiguate(move, possible_moves);
    }

    // up left
    if (file - 1 >= 0 && rank + 2 < 8) {
      move = 'N';
      move += file - 1 + 'a';
      move += std::to_string(rank + 3);
      possible_moves.push_back(move);
      disambiguate(move, possible_moves);
      // taking
      move.insert(1, 1, 'x');
      possible_moves.push_back(move);
      disambiguate(move, possible_moves);
    }

    // down left
    if (file - 1 >= 0 && rank - 2 >= 0) {
      move = 'N';
      move += file - 1 + 'a';
      move += std::to_string(rank - 1);
      possible_moves.push_back(move);
      disambiguate(move, possible_moves);
      // taking
      move.insert(1, 1, 'x');
      possible_moves.push_back(move);
      disambiguate(move, possible_moves);
    }

    // right up
    if (file + 2 < 8 && rank + 1 < 8) {
      move = 'N';
      move += file + 2 + 'a';
      move += std::to_string(rank + 2);
      possible_moves.push_back(move);
      disambiguate(move, possible_moves);
      // taking
      move.insert(1, 1, 'x');
      possible_moves.push_back(move);
      disambiguate(move, possible_moves);
    }

    // right down
    if (file + 2 < 8 && rank - 1 >= 0) {
      move = 'N';
      move += file + 2 + 'a';
      move += std::to_string(rank);
      possible_moves.push_back(move);
      disambiguate(move, possible_moves);
      // taking
      move.insert(1, 1, 'x');
      possible_moves.push_back(move);
      disambiguate(move, possible_moves);
    }

    // left up
    if (file - 2 >= 0 && rank + 1 < 8) {
      move = 'N';
      move += file - 2 + 'a';
      move += std::to_string(rank + 2);
      possible_moves.push_back(move);
      disambiguate(move, possible_moves);
      // taking
      move.insert(1, 1, 'x');
      possible_moves.push_back(move);
      disambiguate(move, possible_moves);
    }

    // left down
    if (file - 2 >= 0 && rank - 1 >= 0) {
      move = 'N';
      move += file - 2 + 'a';
      move += std::to_string(rank);
      possible_moves.push_back(move);
      disambiguate(move, possible_moves);
      // taking
      move.insert(1, 1, 'x');
      possible_moves.push_back(move);
      disambiguate(move, possible_moves);
    }
  }
  return possible_moves;
}

void Piece::makeMove(Piece* piece, int fin_file, int fin_rank, int castle,
                     bool taking) {
  Piece local_piece = *piece;
  if (castle == 1) {
    for (Piece& rook : local_board->pieces) {
      if (rook.getFile() == 7 && rook.getRank() == piece->getRank() &&
          rook.getSide() == piece->getSide()) {
        rook.setFile(5);
        piece->setFile(6);
        return;
      }
    }
  } else if (castle == 2) {
    for (Piece& rook : local_board->pieces) {
      if (rook.getFile() == 0 && rook.getRank() == piece->getRank() &&
          rook.getSide() == piece->getSide()) {
        rook.setFile(3);
        piece->setFile(2);
        return;
      }
    }
  }
  if (taking) {
    for (int i = 0; i < local_board->pieces.size(); i++) {
      if (local_board->pieces[i].getRank() == fin_rank &&
          local_board->pieces[i].getFile() == fin_file) {
        piece->setFile(fin_file);
        piece->setRank(fin_rank);
        if (local_board->pieces[i].getSymb() == piece->getSymb()) {
          continue;
        } else {
          local_board->pieces.erase(local_board->pieces.begin() + i);
          return;
        }
      }
    }
  }
  piece->setFile(fin_file);
  piece->setRank(fin_rank);
}
