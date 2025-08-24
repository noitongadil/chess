#include <fstream>  // for getting input from file
#include <iostream>
#include <regex>  // for input/move validation
#include <stdexcept>
#include <vector>  // for vectors

#include "board.h"
#include "stats.h"

void replaySystem();

std::vector<std::string> parseInput();

int countNewLines(const std::string* str);

void movesInVector(std::string moves_str, std::vector<std::string>& moves);

void printStats(Stats gamestats);

int main() {
  replaySystem();
  return 0;
}

void replaySystem() {
  int choice;
  std::cout << "Which would you like to do?" << std::endl;
  std::cout << "1. Replay (Read from file)" << std::endl;
  std::cout << "2. Play" << std::endl;
  std::cout << "Your choice: ";
  std::cin >> choice;
  while (choice != 1 && choice != 2) {
    std::cout << "Invalid input. Try again: ";
    std::cin >> choice;
    std::cout << std::endl;
  }
  std::vector<std::string> moves;
  if (choice == 1) {
    moves = parseInput();
  }

  Board board;
  Stats gamestats;
  bool side = 0;

  if (choice == 1) {
    for (int i = 0; i < moves.size(); i++) {
      // get rid of local side
      int side = i % 2;
      std::cout << std::endl;
      std::cout << "move: " << moves[i] << std::endl
                << "side: " << side << std::endl
                << "move num: " << i + 1 << std::endl;
      board.passMove(moves[i], side, gamestats);
      board.printBoard();
    }
  } else if (choice == 2) {
    while (true) {
      std::string move;
      std::cout << "Make your move: ";
      std::cin >> move;
      std::cout << std::endl;
      if (move == "end") {
        break;
      }
      board.passMove(move, side, gamestats);
      board.printBoard();
      side = !side;
    }
  }
  printStats(gamestats);
}

std::vector<std::string> parseInput() {
  // getting the PGN
  std::fstream game_file("game.txt");
  std::string moves_str;
  getline(game_file, moves_str);

  // regex is a digit followed by a literal dot
  std::regex move_num("(\\d+\\.)");
  moves_str = std::regex_replace(moves_str, move_num, "\n");

  int size = countNewLines(&moves_str);

  std::vector<std::string> moves(size * 2, "");
  movesInVector(moves_str, moves);
  return moves;
}

int countNewLines(const std::string* moves_str) {
  int count = 0;
  for (char c : *moves_str) {
    if (c == '\n') {
      count++;
    }
  }
  return count;
}

void movesInVector(std::string moves_str, std::vector<std::string>& moves) {
  int i = 0;
  int move_num = 0;
  bool err;
  std::regex valid_move(
      "(([RNBKQ])?([a-h])?([1-8])?(x)?([a-h][1-8])(\\+|\\#)?)"
      "|((O-O)(-O)?)"
      "|(([a-h][1-8])(=)([RNBQ]))");
  for (int i = 0; i < moves_str.length(); i++) {
    // TODO: explain
    if (moves_str[i] == '\n') {
      if (i == 0) {
        continue;
      }  // end if
      try {
        if (std::regex_match(moves[move_num], valid_move) == false) {
          err = true;
          throw(err);
        }  // end if
      } catch (bool err) {
        std::cout << moves[move_num] << " -> ";
        std::cout << "Invalid move detected! Terminating process." << std::endl;
        std::exit(-1);
      }
      move_num++;
      // use str size instead of null
    } else if (moves_str[i] == '\0') {
      return;
    } else if (moves_str[i] == ' ') {
      if (moves_str[i + 1] == '\n') {
        continue;
      }  // end if
      move_num++;
      continue;
    } else {
      moves[move_num] += moves_str[i];
    }
  }
}

void printStats(Stats gamestats) {
  std::cout << std::endl;
  std::cout << "Game stats:" << std::endl;
  std::cout << "Number of pawn moves: " << gamestats.pawn_moves << std::endl;
  std::cout << "Number of queen moves: " << gamestats.queen_moves << std::endl;
  std::cout << "Number of bishop moves: " << gamestats.bishop_moves
            << std::endl;
  std::cout << "Number of rook moves: " << gamestats.rook_moves << std::endl;
  std::cout << "Number of king moves: " << gamestats.king_moves << std::endl;
  std::cout << "Number of knight moves: " << gamestats.knight_moves
            << std::endl;
  std::cout << "Number of takes: " << gamestats.takes << std::endl;
}
