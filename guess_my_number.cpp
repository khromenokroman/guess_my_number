#include <iostream>

#include "pc_work.h"
#include "user_work.h"
#include "start_menu.h"
#include "records.h"

int main()
{
    system("clear");
    int answer;
    choice_menu_item(answer);
    if (answer == 1)
    {
        std::string name_user;
        std::cout << "Введите ваше имя: ";
        std::cin >> name_user;
        int pc_number, attempt = 1;
        create_pc_number(pc_number);
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