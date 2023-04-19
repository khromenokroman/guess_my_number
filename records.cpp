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
    const int MAX_RECORDS_ITEMS = get_count_line();
    int records_line = 0;
    std::fstream file_in;
    std::string file_in_line;
    std::string records_items[MAX_RECORDS_ITEMS];

    file_in.open("records.txt", std::fstream::in);
    for (file_in_line; getline(file_in, file_in_line);)
    {
        if (records_line == MAX_RECORDS_ITEMS)
            break;
        records_items[records_line] = file_in_line;
        records_line++;
    }
    file_in.close();

    system("clear");

    for (int i = 0; i < MAX_RECORDS_ITEMS; i++)
    {
        if (records_items[i].size() == 0)
            continue;
        std::cout << records_items[i] << std::endl;
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

