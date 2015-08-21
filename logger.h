#pragma once
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <mutex>

class Logger
{

public:

    Logger(std::string filename);
    ~Logger();
    void log(const char * msg);
    std::ofstream logfile;


private:
    static std::vector<std::string> files;
    static std::mutex mutex_logger;
};

