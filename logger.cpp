#include "logger.h"
#include <algorithm>
#include <iostream>




Logger::Logger(std::string f): provider(f)
{


}

void Logger::log(std::string msg)
{
   provider.write_line(msg);
}




