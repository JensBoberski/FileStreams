#include <boost/shared_ptr.hpp>
#include <vector>
#include <map>
#include <fstream>

class File_Streams {

public:
  File_Streams(bool enableFlag=true);
  ~File_Streams();

  template <typename T>
  void write(int index, const std::vector<T> & vector, const std::string & fileName);

private:
  std::ofstream & getFileStreamRef(const std::string & fileName);
  void createNewFileStream(const std::string & fileName);
  bool fileStreamExists(const std::string & fileName);

  std::map<std::string, boost::shared_ptr<std::ofstream> > mapFileNameToFileStream;
  bool enableWriting;
};

File_Streams::File_Streams(bool enableFlag)
  : enableWriting(enableFlag)
{}

File_Streams::~File_Streams(){

  std::map<std::string,boost::shared_ptr<std::ofstream> >::iterator it;
  for (it = mapFileNameToFileStream.begin(); it != mapFileNameToFileStream.end(); ++it){
    it->second->close();
  }
}

  template <typename T>
  void File_Streams::write(int index, const std::vector<T> & vector, const std::string & fileName){

    if (!enableWriting) {return;}

    std::ofstream & fileStream = getFileStreamRef(fileName);
    fileStream << index;
    for (unsigned ii = 0; ii < vector.size(); ++ii){
      fileStream << " " << vector[ii];
    }
    fileStream << std::endl;
  }

std::ofstream & File_Streams::getFileStreamRef(const std::string & fileName){

  if (!fileStreamExists(fileName)) {
    createNewFileStream(fileName);
  }

  return *mapFileNameToFileStream[fileName];

}

void File_Streams::createNewFileStream(const std::string & fileName){

  mapFileNameToFileStream[fileName] = boost::shared_ptr<std::ofstream>(new std::ofstream(fileName.c_str()));

}

bool File_Streams::fileStreamExists(const std::string & fileName){

  if (mapFileNameToFileStream.find(fileName) == mapFileNameToFileStream.end()) {
    return false;
  } else {
    return true;
  }
}
