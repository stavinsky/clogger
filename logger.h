#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <map>

class Logger
{

public:

    Logger(std::string file);
    ~Logger();
    void log(const char * msg);

private:
    static std::map<std::string, int> files;
    static std::mutex mutex_logger;
    std::ofstream logfile;
    std::string filename;
};

