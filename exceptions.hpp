//exceptions

#ifndef exceptions_hpp
#define exceptions_hpp
#include <iostream>

class VLE : public std::exception{
public:
    const char * what (){
        return "Vector length cannot be 0 ";
    }
};

#endif
