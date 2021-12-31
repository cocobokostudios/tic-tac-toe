include_directories (
    "${PROJECT_SOURCE_DIR}/src/game"
    "${PROJECT_SOURCE_DIR}/src/gamelib"
    )
add_executable(TerminalTicTacToe main.c)
add_dependencies(TerminalTicTacToe TicTacToe)
target_link_libraries(TerminalTicTacToe TicTacToe)