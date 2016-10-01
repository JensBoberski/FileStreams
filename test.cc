#include "filestreams.hh"
#include <vector>

int main(){
  File_Streams fs1;
  File_Streams fs2;
  std::vector<size_t> test1 (10,1);
  fs1.write(1,test1,"test1.dat");
  
  std::vector<float> test2 (10,1.213);
  fs1.write(2,test2,"test2.dat");
  
  std::vector<std::string> test3 (10,"This is the test");
  fs2.write(3,test3,"test3.dat");

  //two fileStreamers can write in the same file... overwriting each others output
  std::vector<std::string> test4 (10,"same file");
  fs1.write(4,test4,"test3.dat");

  return 1;
}
