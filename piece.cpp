#include <iostream>
#include <string> // for strings

#include "board.h"
Piece::Piece(Board* board, int side, int rank, int file, char type, char symb)
    : local_board(board),
      side(side),
      rank(rank),
      file(file),
      type(type),
      symb(symb) {}

void Piece::disambiguate(std::string move, std::vector<std::string> &possible_moves) {
    move.insert(1, 1, file + 'a');
    possible_moves.push_back(move);
    move.insert(2, std::to_string(rank + 1));
    possible_moves.push_back(move);
}

void Piece::getPosMovesRec(Piece piece, std::vector<std::string> &possible_moves,
                           int curr_rank, int curr_file, std::string direction,
                           bool start) {
    std::string move;
    if (!start) {
        for (Piece tmp_piece : local_board->pieces) {
            if (tmp_piece.getFile() == curr_file && tmp_piece.getRank() == curr_rank) {
                if (tmp_piece.getSide() != piece.getSide()) {
                    move = piece.getType();
                    move += 'x';
                    move += curr_file + 'a';
                    move += std::to_string(curr_rank + 1);
                    possible_moves.push_back(move);
                    disambiguate(move, possible_moves);
                }
                return;
            }
        }

        move = piece.getType();
        move += curr_file + 'a';
        move += std::to_string(curr_rank + 1);
        possible_moves.push_back(move);
        disambiguate(move, possible_moves);
    }

    if (direction == "n") {
        if (curr_rank == 7) {
            return;
        }
        getPosMovesRec(piece, possible_moves, curr_rank + 1, curr_file, direction, false);
    }
    if (direction == "w") {
        if (curr_file == 0) {
            return;
        }
        getPosMovesRec(piece, possible_moves, curr_rank, curr_file - 1, direction, false);
    }
    if (direction == "s") {
        if (curr_rank == 0) {
            return;
        }
        getPosMovesRec(piece, possible_moves, curr_rank - 1, curr_file, direction, false);
    }
    if (direction == "e") {
        if (curr_file == 7) {
            return;
        }
        getPosMovesRec(piece, possible_moves, curr_rank, curr_file + 1, direction, false);
    }
    if (direction == "nw") {
        if (curr_rank == 7 || curr_file == 0) {
            return;
        }
        getPosMovesRec(piece, possible_moves, curr_rank + 1, curr_file - 1, direction, false);
    }
    if (direction == "ne") {
        if (curr_rank == 7 || curr_file == 7) {
            return;
        }
        getPosMovesRec(piece, possible_moves, curr_rank + 1, curr_file + 1, direction, false);
    }
    if (direction == "sw") {
        if (curr_rank == 0 || curr_file == 0) {
            return;
        }
        getPosMovesRec(piece, possible_moves, curr_rank - 1, curr_file - 1, direction, false);
    }
    if (direction == "se") {
        if (curr_rank == 0 || curr_file == 7) {
            return;
        }
        getPosMovesRec(piece, possible_moves, curr_rank - 1, curr_file + 1, direction, false);
    }
}

bool Piece::isBlocked(int side, int file2check, int rank2check) {
    for (Piece piece : local_board->pieces) {
        if (piece.getSide() == side && piece.getFile() == file2check && piece.getRank() == rank2check) {
            return true;
        }
    }
    return false;
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

void Piece::makeMove(Piece *piece, int fin_file, int fin_rank, int castle, bool taking) {
    Piece local_piece = *piece;
    if (castle == 1) {
        for (Piece &rook : local_board->pieces) {
            if (rook.getFile() == 7 && rook.getRank() == piece->getRank() && rook.getSide() == piece->getSide()) {
                rook.setFile(5);
                piece->setFile(6);
                return;
            }
        }
    } else if (castle == 2) {
        for (Piece &rook : local_board->pieces) {
            if (rook.getFile() == 0 && rook.getRank() == piece->getRank() && rook.getSide() == piece->getSide()) {
                rook.setFile(3);
                piece->setFile(2);
                return;
            }
        }
    }
    if (taking) {
        for (int i = 0; i < local_board->pieces.size(); i++) {
            if (local_board->pieces[i].getRank() == fin_rank && local_board->pieces[i].getFile() == fin_file) {
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

// Setter methods
void Piece::setRank(int n) {
    rank = n;
}

void Piece::setFile(int n) {
    file = n;
}

void Piece::setSide(int n) {
    side = n;
}

void Piece::setType(char c) {
    type = c;
}

void Piece::setSymb(char c) {
    symb = c;
}

void Piece::setDir(std::vector<std::string> dirs) {
    directions = dirs;
}

std::vector<std::string> Piece::getDirs() {
    return directions;
}

char Piece::getType() {
    return type;
}

char Piece::getSymb() {
    return symb;
}

int Piece::getFile() {
    return file;
}

int Piece::getRank() {
    return rank;
}

int Piece::getSide() {
    return side;
}
