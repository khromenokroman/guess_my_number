cmake_minimum_required(VERSION 3.5)

project(03_guess_my_number)

add_executable(03_guess_my_number 
    guess_my_number.cpp
    pc_work.cpp
    user_work.cpp
    start_menu.cpp
    records.cpp
)

set_target_properties(03_guess_my_number PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)