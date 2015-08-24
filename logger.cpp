#include "logger.h"
#include <algorithm>
#include <iostream>


std::map<std::string, int> Logger::files;
std::mutex Logger::mutex_logger;


Logger::Logger(std::string file)
{
    filename = file;

    std::lock_guard<std::mutex> lock(mutex_logger);

    if(files.count(file)>0)
    {
        files[file]++;
        return;
    }
    else
    {
        files[file] = 0;
    }

    logfile.open(file, std::ios::app);

    std::cout << "opening file "<<file<<std::endl;






}
Logger::~Logger()
{
    std::cout << "destructor of " << filename << std::endl;
    std::lock_guard<std::mutex> lock(mutex_logger);
    if(files.count(filename)>0)
    {
        if(files[filename]==0)
        {
            std::cout << "closing file "<<filename<<std::endl;
            logfile.close();
        }
        if(files[filename]>0)
        {
            files[filename]--;
        }
    }


}

void Logger::log(const char *msg)
{
    logfile << msg << std::endl;
}





