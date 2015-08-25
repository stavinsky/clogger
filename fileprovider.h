#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <map>
#include <memory>


struct File
{
   std::ofstream file;
   std::mutex m_file;
   std::string file_name;

};

class FileProvider
{
public:
    FileProvider(std::string f);
    ~FileProvider();
    void write_line(std::string line);
private:
    static std::map<std::string, std::shared_ptr<File>> files;
    static std::mutex m_files;
    std::shared_ptr<File> file;


};
