cmake_minimum_required(VERSION 3.14)
project(chess VERSION 1.0)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(SRC_FILES
    src/main.cpp
    src/board/board.cpp
    src/pieces/piece.cpp
    src/pieces/king.cpp
    src/pieces/queen.cpp
    src/pieces/knight.cpp
    src/pieces/bishop.cpp
    src/pieces/rook.cpp
    src/pieces/pawn.cpp
)

set(CURSES_NEED_NCURSES TRUE)
find_package(Curses REQUIRED)

include_directories(
    src
    src/board
    src/pieces
)

add_executable(chess ${SRC_FILES})

target_link_libraries(chess PRIVATE ${CURSES_LIBRARIES})
