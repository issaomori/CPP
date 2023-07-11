#include <string>
#include <iostream>
#include <fstream>


int main (int argc, char **argv){

    if (argc != 4){
        std::cout << "Error. Incorrect numbers of arguments." << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    if (filename.empty() || s1.empty() || s2.empty()){
        std::cout << "Error. One or more arguments are empty.";
        return 1;
    }
    std::ifstream file_in(filename.c_str());
    std::string output_filename(filename + ".replace");
    std::ofstream file_out(output_filename.c_str());


    if (file_in.fail()){
        std::cout << "Error. Failed to open the file." << std::endl;
        return 1;
    }

    if (file_out.fail()){
        std::cout << "Error. Failed to create the file." << std::endl;
        return 1;
    }

    std::string buffer;
    std::string::size_type pos;
    while (getline(file_in, buffer)){
        while((pos = buffer.find(s1)) != std::string::npos){
            file_out << buffer.substr(0, pos);
            buffer.erase(0, pos + s1.length());
            file_out << s2;
        }
        file_out << buffer;
        if (!file_in.eof())
            file_out << std::endl;
    }
    return 0;
}
