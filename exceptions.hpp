//exceptions

#ifndef exceptions_hpp
#define exceptions_hpp
#include <iostream>

class VLE : public std::exception{
public:
    const char * what (){
        return "Vector length cannot be 0\n";
    }
};

class SIE : public std::exception{
public:
    const char * what(){
        return " \"t\" interval must be between 0 and 1\n";
    }
};

class EqualPointException : public std::exception{
public:
    EqualPointException(int num1, int num2){
        this->num1=num1;
        this->num2=num2;
    }
    const char * pointsException (){
        std::cout<<num1<< " " << num2;
        return "Matching points";
    }
private:
    int num1;
    int num2;
};
#endif
