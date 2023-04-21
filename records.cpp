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
            temp_buf = rec_temp[j].substr(rec_temp[j].length()-2,rec_temp[j].length());
            if (temp_buf[0] == '#')
                temp_buf.erase(0,1);
            if (rec_attempt[i] == std::stoi(temp_buf))
            {
                std::cout << rec_temp[j].substr(0,rec_temp[j].length()-2) + " " + temp_buf << std::endl;
            }


        }
        
    }

}

void write_records(const std::string &name_user, const int &attempt)
{
    std::fstream file_out;

    file_out.open("records.txt", std::fstream::app);
    file_out << name_user << std::endl;
    file_out << attempt << std::endl;
    file_out.close();
}
