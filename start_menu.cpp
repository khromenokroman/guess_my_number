#include <iostream>

void choice_menu_item(int &answer)
{
    while (true)
    {
        std::cout << "***********************************"<< std::endl;
        std::cout << "\tИГРА УГАДАЙ ЧИСЛО!!!"<< std::endl;
        std::cout << "***********************************"<< std::endl;
        std::cout << "1.Начать играть"<< std::endl;
        std::cout << "2.Просмотреть результаты"<< std::endl;
        std::cout << "3.Выход"<< std::endl;
        std::cout << "***********************************"<< std::endl;
        std::cout << "Сделайте выбор: ";
        std::cin >> answer;
        break;
    }
    
}