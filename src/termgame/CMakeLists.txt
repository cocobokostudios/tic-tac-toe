include_directories (
    "${PROJECT_SOURCE_DIR}/src/termgame"
    "${PROJECT_SOURCE_DIR}/src/gamelib"
    )

add_library(TerminalTicTacToe terminal_tic_tac_toe.c)
add_dependencies(TerminalTicTacToe TicTacToe)
target_link_libraries(TerminalTicTacToe 
    TicTacToe)

add_executable(TerminalTicTacToeRunner main.c)
set_target_properties(TerminalTicTacToeRunner
    PROPERTIES OUTPUT_NAME TerminalTicTacToe)
add_dependencies(TerminalTicTacToeRunner
    TerminalTicTacToe)
target_link_libraries(TerminalTicTacToeRunner
    TerminalTicTacToe
    )