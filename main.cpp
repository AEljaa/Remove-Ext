#include <iostream>
#include <filesystem>
#include <cstdlib>
#include <string>

int main(){
  
  std::string dir,fileExt,file;
  namespace fs=std::filesystem;
  std::cout<<"What Directory should be worked on ?: "<<std::endl;
  std::cin >> dir;
  std::cout<<"What file Extension should be removed? Include the . e.g '.jpg' :"<<std::endl;
  std::cin >> fileExt;


  for (const auto& entry : fs::directory_iterator(dir)){
    if(fs::is_regular_file(entry.path())){
      if(entry.path().extension().string()==fileExt){
        file=entry.path().string();
        fs::remove(entry.path());
        std::cout<<"Removed "<<file<<" with ext '"<<fileExt<<"' "<<std::endl;
      }
    }
  }



}
