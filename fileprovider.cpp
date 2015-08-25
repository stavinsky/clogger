#include "fileprovider.h"


std::map<std::string, int> Logger::files;
std::mutex Logger::mutex_files_map;


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

}
Logger::~Logger()
{
    std::lock_guard<std::mutex> lock(mutex_logger);
    if(files.count(filename)>0)
    {
        if(files[filename]==0)
        {
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


