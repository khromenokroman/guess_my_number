#include <iostream>
#include <unistd.h>

void choice_menu_item(int &answer)
{
    while (true)
    {
        system("clear");
        std::cout << "***********************************" << std::endl;
        std::cout << "\tИГРА УГАДАЙ ЧИСЛО!!!" << std::endl;
        std::cout << "***********************************" << std::endl;
        std::cout << "1.Начать играть" << std::endl;
        std::cout << "2.Просмотреть результаты" << std::endl;
        std::cout << "3.Выход" << std::endl;
        std::cout << "***********************************" << std::endl;
        std::cout << "Сделайте выбор: ";
        std::cin >> answer;
        if (std::cin.good())
        {
            if (answer <= 0 || answer > 3)
            {
                std::cout << "Вы ввели не правильные данные!!!" << std::endl;
                sleep(1);
                continue;
            }
            break;
        }
        else
        {
            std::cout << "Вы ввели буквы, надо цифры!!" << std::endl;
            sleep(1);
            break;
        }
    }
}