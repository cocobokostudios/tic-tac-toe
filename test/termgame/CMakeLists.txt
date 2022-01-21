include_directories (
    "${PROJECT_SOURCE_DIR}/src/termgame"
    )
add_executable(test_terminaltictactoe test_terminal_tic_tac_toe.c)
add_dependencies(test_terminaltictactoe 
    test_terminaltictactoe
    TerminalTicTacToe
    )
add_test(test_terminaltictactoe test_terminaltictactoe)
target_link_libraries(test_terminaltictactoe PRIVATE 
    TerminalTicTacToe
    cmocka::cmocka
    )