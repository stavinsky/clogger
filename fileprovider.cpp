#include "fileprovider.h"
#include "iostream"

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

    files[f] = std::make_shared<File>();
    files[f]->file.open(f, std::ios::app);
    files[f]->file_name = f;
    file = files[f];

}
FileProvider::~FileProvider()
{

    if(file.use_count() == 2)
    {
        std::lock_guard<std::mutex> lock(m_files);
        std::cout << "destructor of "<< file->file_name<<std::endl;
        files.erase(file->file_name);
    }
}

void FileProvider::write_line(std::string line)
{
    std::lock_guard<std::mutex> lock(file->m_file);
    file->file << line << std::endl;
}


