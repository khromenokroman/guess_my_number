#include <iostream>
#include<ctime>

void create_pc_number(int &pc_number, const int &max_random_number)
{
    srand(static_cast<unsigned int>(time(0)));
    pc_number = rand() % max_random_number;
    std::cout << "Я загадал число: " << pc_number << std::endl;
}