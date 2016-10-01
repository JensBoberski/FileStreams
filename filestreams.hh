// pimple implementation

#ifndef _FILE_STREAMS_
#define _FILE_STREAMS_

#include <boost/scoped_ptr.hpp>
#include <vector>

class File_Streams {

public:
  File_Streams();
  ~File_Streams();

  void write(int index, const std::vector<int> & vector, const std::string & fileName);
  void write(int index, const std::vector<long int> & vector, const std::string & fileName);
  void write(int index, const std::vector<unsigned int> & vector, const std::string & fileName);
  void write(int index, const std::vector<unsigned long int> & vector, const std::string & fileName);
  void write(int index, const std::vector<float> & vector, const std::string & fileName);
  void write(int index, const std::vector<double> & vector, const std::string & fileName);
  void write(int index, const std::vector<long double> & vector, const std::string & fileName);
  void write(int index, const std::vector<std::string> & vector, const std::string & fileName);

private:
  class impl;
  boost::scoped_ptr<impl> pimpl;

};

#endif
