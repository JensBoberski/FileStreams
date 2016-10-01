#include <map>
#include <fstream>
#include <boost/shared_ptr.hpp>

#include "filestreams.hh"

class File_Streams::impl {

public:
  
  template <typename T>
  void write(int index, const std::vector<T> & vector, const std::string & fileName){
    
    std::ofstream & fileStream = getFileStreamRef(fileName);
    fileStream << index;
    for (unsigned ii = 0; ii < vector.size(); ++ii){
      fileStream << " " << vector[ii];
    }
    fileStream << std::endl;
  }
  
  std::map<std::string, boost::shared_ptr<std::ofstream> > mapFileNameToFileStream;
  bool enableWriting;

private:

  std::ofstream & getFileStreamRef(const std::string & fileName){
    if (!fileStreamExists(fileName)) {
      createNewFileStream(fileName);
    }
    return *mapFileNameToFileStream[fileName];
  }

  void createNewFileStream(const std::string & fileName){
    mapFileNameToFileStream[fileName] = boost::shared_ptr<std::ofstream>(new std::ofstream(fileName.c_str()));
  }

  bool fileStreamExists(const std::string & fileName){
    if (mapFileNameToFileStream.find(fileName) == mapFileNameToFileStream.end()) {
      return false;
    } else {
      return true;
    }
  }

};



File_Streams::File_Streams()
  : pimpl(new impl)
{}

File_Streams::~File_Streams(){
  std::map<std::string,boost::shared_ptr<std::ofstream> >::iterator it;
  for (it = pimpl->mapFileNameToFileStream.begin(); it != pimpl->mapFileNameToFileStream.end(); ++it){
    it->second->close();
  }
}

void File_Streams::write(int index, const std::vector<int> & vector, const std::string & fileName){
pimpl->write(index, vector, fileName);
}
void File_Streams::write(int index, const std::vector<long int> & vector, const std::string & fileName){
  pimpl->write(index, vector, fileName);
}
void File_Streams::write(int index, const std::vector<unsigned int> & vector, const std::string & fileName){
  pimpl->write(index, vector, fileName);
}
void File_Streams::write(int index, const std::vector<unsigned long int> & vector, const std::string & fileName){
  pimpl->write(index, vector, fileName);
}
void File_Streams::write(int index, const std::vector<float> & vector, const std::string & fileName){
  pimpl->write(index, vector, fileName);
}
void File_Streams::write(int index, const std::vector<double> & vector, const std::string & fileName){
  pimpl->write(index, vector, fileName);
}
void File_Streams::write(int index, const std::vector<long double> & vector, const std::string & fileName){
  pimpl->write(index, vector, fileName);
}
void File_Streams::write(int index, const std::vector<std::string> & vector, const std::string & fileName){
  pimpl->write(index, vector, fileName);
}

