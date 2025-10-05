#include "ENGINE/UTIL.HPP"

std::string ReadFileToTxt(const std::string& a_path)
{
   std::ifstream file(a_path);
   if (file.is_open() == false)
   {
      std::cerr << "Failed to open file: " << a_path << std::endl;
      return nullptr;
   }
   std::string line;
   std::string content;
   while (std::getline(file, line))
   {
      content += line + "\n";
   }
   file.close();
   return content;
}