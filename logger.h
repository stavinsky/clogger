#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <map>
#include "fileprovider.h"

class Logger
{

public:


    Logger(std::string f);
    ~Logger(){}
    void log(std::string msg);

private:
    FileProvider provider;
};

