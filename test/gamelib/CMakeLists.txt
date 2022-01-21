include_directories ("${PROJECT_SOURCE_DIR}/src/gamelib")
add_executable(test_tictactoe test_tic_tac_toe.c)
add_dependencies(test_tictactoe test_tictactoe)
add_test(test_tictactoe test_tictactoe)

target_link_libraries(test_tictactoe PRIVATE 
    cmocka::cmocka
    TicTacToe
    )