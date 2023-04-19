#include <iostream>

void create_pc_number(int &pc_number)
{
    srand(static_cast<unsigned int>(time(0)));
    pc_number = rand() % 100;
    std::cout << "Я загадал число: " << pc_number << std::endl;
}