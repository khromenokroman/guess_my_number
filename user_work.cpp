
#include <iostream>
#include <cmath>

#include "records.h"

void check_user_number(const int &pc_number, int &attempt, const std::string name_user)
{
    int user_number;
    while (pc_number != user_number)
    {
        std::cout << "Введите число: ";
        std::cin >> user_number;

        int deviation = abs(pc_number - user_number);

        if (deviation >= 30)
        {
            std::cout << "Очень далеко...\n";
        }
        else if (deviation >= 15 && deviation < 30)
        {
            std::cout << "Почти угадал...\n";
        }
        else if (deviation >= 5 && deviation < 15)
        {
            std::cout << "Совсем близко...\n";
        }
        else if (deviation > 0 && deviation < 5)
        {
            std::cout << "Рикошет...\n";
        }
        else if (deviation == 0)
        {
            std::cout << "************************************" << std::endl;
            std::cout << "**********!!!!Угадал!!!!************" << std::endl;
            std::cout << "************************************" << std::endl;
            std::cout << "Было использованно попыток: " << attempt << std::endl;
        }
        attempt++;
    }
    write_records(name_user, attempt);
}