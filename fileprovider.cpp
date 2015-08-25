#include "fileprovider.h"


std::map<std::string, std::shared_ptr<File>> FileProvider::files;
std::mutex FileProvider::m_files;


FileProvider::FileProvider(std::string f)
{
    std::lock_guard<std::mutex> lock(m_files);

    if(files.count(f)>0)
    {
        file = files[f];
        return;
    }

    files[f].reset(new File);
    files[f]->file.open(f, std::ios::app);
    files[f]->file_name = f;
    file = files[f];

}
FileProvider::~FileProvider()
{

}

void FileProvider::write_line(std::string line)
{
    file->file << line << std::endl;
}


