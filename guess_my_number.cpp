#include <iostream>

#include "pc_work.h"
#include "user_work.h"
#include "start_menu.h"
#include "records.h"

int main()
{
    system("clear");
    int answer, max_random_number;
    choice_menu_item(answer);
    if (answer == 1)
    {
        std::string name_user;
        std::cout << "Введите ваше имя: ";
        std::cin.ignore(32767,'\n'); //чищу буфер
        std::getline(std::cin, name_user); //получаю всю строку
        std::cout << "Введите верхний диапазон загадываемого числа: ";
        std::cin >> max_random_number; // проверка на 0 и меньше
        if (max_random_number <= 0)
        {
            std::cout << "Вы ввели недопустимое число!!" << std::endl;
            return -1;
        }
        int pc_number, attempt = 1;
        create_pc_number(pc_number, max_random_number);
        std::cout << "===========================================================" << std::endl;
        std::cout << "\t\t\tОписание игры:\n\nКомпьютер загадывает число, тебе надо это число угадать, все просто :)\n\n"
                  << "Если видишь сообщение \"Очень далеко\" занчит разница больше 30\n"
                  << "Если видишь сообщение \"Почти угадал\" занчит разница от 15 до 30\n"
                  << "Если видишь сообщение \"Совсем близко\" занчит разница от 5 до 15\n"
                  << "Если видишь сообщение \"Рикошет\" занчит разница от 1 до 5\n"
                  << std::endl;
        check_user_number(pc_number, attempt, name_user);
    }
    else if (answer == 2)
    {
        get_results();
    }
    else
        std::cout << "До скорой встречи!!!" << std::endl;
    return 0;
}