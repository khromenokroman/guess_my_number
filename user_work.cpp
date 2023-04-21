
#include <iostream>
#include <cmath>

#include "records.h"

int help_user(const int max, const int pc_number)
{
    int left = 0;
    int right = max - 1;
    int midlle = 0;
    int *arr = new int[max];
    for (int i = 0; i < max; i++)
    {
        arr[i] = i;
    }

    while (left <= right)
    {
        midlle = (left + right) / 2;
        // std::cout << midlle << std::endl;
        if (arr[midlle] == pc_number)
        {
            return arr[midlle];
        }
        if (arr[midlle] < pc_number)
        {
            left = midlle + 1;
        }
        else
        {
            right = midlle - 1;
        }
    }
}

void check_user_number(const int &pc_number, int &attempt, const std::string name_user, int max_random_number)
{
    int user_number;
    char help;
    bool write = false;
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
            write = true;
        }
        attempt++;
        if (attempt > 10)
        {
            std::cout << "Вы слишком много раз угадывали не правильно хотите чтобы компьютер отгадал за вас число? [y/n]";
            std::cin >> help;
            if (help != 'y')
            {
                continue;
            }
            else
            {
                std::cout << "Загаданное компьютером число: " << help_user(max_random_number,pc_number) << std::endl;
                user_number = help_user(max_random_number,pc_number);
            } 
        }

    }
    if (write)
        write_records(name_user, attempt);
}