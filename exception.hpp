// data: martedì, dicembre  7 2010

#include <exception>
#include <iostream>
#include <sstream>


#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

class VLCRubyException: public std::exception{
public:
  VLCRubyException() throw(){};
  virtual ~VLCRubyException() throw(){};
  virtual const char* what() const throw(){
    std::cout << libvlc_errmsg() << std::endl;
  }
};



#endif
