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
    std::fstream file_in;
    std::string file_in_line;
    int count_line_file = 0;
    if (get_count_line() / 2 != 0)
    {  
        int array_records[get_count_line() / 2];
        

        system("clear");
        file_in.open("records.txt", std::fstream::in);
        for (file_in_line; getline(file_in, file_in_line);)
        {
            std::cout << file_in_line << std::endl;
            if (count_line_file % 2 != 0)
            {
                // array_records[count_line_file-1] = static_cast<int>(file_in_line);
                // count_line_file++;
            }
        }
        file_in.close();
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
