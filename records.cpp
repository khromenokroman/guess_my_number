#include <iostream>
#include <fstream>

int get_count_line()
{
    int count_line = 0;
    std::string line;
    std::fstream file("records.txt");
    while (getline(file, line))
        ++count_line;
    return count_line;
}

void clear_file()
{
    std::string path = "records.txt";
    std::ofstream file(path);
    file << "";
}

void get_results()
{
    if (get_count_line() / 2 <= 0)
    {
        std::cout << "В эту игру еще никто не играл :(((\nСтань первым!!!" << std::endl;
    }
    int max_item = get_count_line() / 2;
    std::string rec_name[max_item];
    int rec_attempt[max_item];
    std::string rec_temp[max_item];
    std::fstream file_in;
    std::string file_in_line;
    int count = 0, temp = 0;
    file_in.open("records.txt", std::fstream::in);
    for (; getline(file_in, file_in_line);) // читаем файл и создаем 2 массива
    {
        if (count % 2 == 0)
        {
            rec_name[count / 2] = file_in_line;
        }
        if (count % 2 != 0)
        {
            rec_attempt[count / 2] = std::stoi(file_in_line);
        }
        count++;
    }
    file_in.close();

    for (int i = 0; i < max_item; i++) // клеим строки чтоб можно было найти
    {
        rec_temp[i] = rec_name[i] + "#" + std::to_string(rec_attempt[i]);
    }

    for (int i = 0; i < max_item; i++) // сортируем массив
    {
        for (int j = 0; j < max_item - 1 - i; j++)
        {
            if (rec_attempt[j] > rec_attempt[j + 1])
            {
                std::swap(rec_attempt[j], rec_attempt[j + 1]);
            }
        }
    }

    std::string temp_buf;
    for (int i = 0; i < max_item; i++)
    {
        for (int j = 0; j < max_item; j++)
        {
            temp_buf = rec_temp[j].substr(rec_temp[j].length() - 2, rec_temp[j].length());
            if (temp_buf[0] == '#')
                temp_buf.erase(0, 1);
            if (rec_attempt[i] == std::stoi(temp_buf))
            {
                std::cout << rec_temp[j].substr(0, rec_temp[j].length() - 2) + " " + temp_buf << std::endl;
            }
        }
    }
}

void write_records(const std::string &name_user, const int &attempt)
{
    int max_line = get_count_line(), count = 0;
    std::string arr_line[max_line];
    std::fstream file_in;
    std::string file_in_line;
    file_in.open("records.txt", std::fstream::in);
    for (; getline(file_in, file_in_line);) // читаем файл и создаем массив
    {
        arr_line[count] = file_in_line;
        count++;
    }
    file_in.close();
    count = 0;
    bool add_user = true;
    bool replace_data = false;
    for (int i = 1; i < max_line; i+=2)
    {
        if (attempt == std::stoi(arr_line[i]) && name_user == arr_line[i - 1] ) // проверка если сыграл так же то пропуск
        {
            continue;
        }    
        if (attempt == std::stoi(arr_line[i])) // если такой же результат уже у когото есть
        {
            
            arr_line[i - 1] = name_user;
            arr_line[i] = std::to_string(attempt);
            replace_data = true;
        }
        if (name_user == arr_line[i] || attempt == std::stoi(arr_line[i])) //не добовляем если совпало
            add_user = false;
    }

    if (replace_data) // читаем массив и пишем в файл
    {
        clear_file();
        std::fstream file_out;
        int count = 0;
        file_out.open("records.txt", std::fstream::app);
        for (int i = 0; i < max_line; i++)
        {
            if (i == max_line - 1) //на последней строке не делаем перевод строки
            {
                file_out << arr_line[i];
                break;
            }
            file_out << arr_line[i] << std::endl;
        }
        file_out.close();
    }

    if (add_user) // добавляем в конец файла
    {
        std::fstream file_out;

        file_out.open("records.txt", std::fstream::app);
        file_out << std::endl << name_user << std::endl;
        file_out << attempt;
        file_out.close();
    }
}
