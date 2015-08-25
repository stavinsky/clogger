#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <map>


struct File
{
   std::ofstream file;
   std::mutex m_file;
};

class FileProvider
{
public:
    FileProvider(std::string f);
    ~FileProvider();
    write_line(std::string line);
private:
    static std::map<std::string, int> files;
    static std::mutex m_files;
    std::ofstream file;
    std::string file_name;
};
