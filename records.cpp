#include <iostream>
#include <fstream>


void get_results()
{
    std::fstream file_in;
    std::string file_in_line;
    
    system("clear");
    file_in.open("records.txt", std::fstream::in);
    for (; getline(file_in, file_in_line);)
    {
        std::cout << file_in_line << std::endl;
    }
    file_in.close();

}

void write_records(const std::string &name_user, const int &attempt)
{
    std::fstream file_out;

    file_out.open("records.txt", std::fstream::app);
    file_out << name_user << std::endl;
    file_out << attempt << std::endl;
    file_out.close();
}
