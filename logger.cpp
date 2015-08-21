#include "logger.h"
#include <algorithm>
#include <iostream>


std::vector<std::string> Logger::files;
std::mutex Logger::mutex_logger;


Logger::Logger(std::string filename)
{
    std::lock_guard<std::mutex> lock(mutex_logger);

    if(std::find(files.begin(), files.end(), filename) != files.end())
    {
        return;
    }
    files.push_back(filename);
    logfile.open(filename, std::ios::app);




}
Logger::~Logger()
{
    for(std::vector<std::string>::iterator it = files.begin(); it != files.end(); ++it)
    {
        std::cout << *it <<std::endl;
    }
    logfile.close();
}

void Logger::log(const char *msg)
{
    logfile << msg << std::endl;
}





