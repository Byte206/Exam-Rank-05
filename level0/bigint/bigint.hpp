#ifndef BIGINT
# define BIGINT

#include <sstream>
#include <iostream>
#include <string>
#include <cstdlib>

class bigint 
{
  private:
    std::string str;
  public:
    bigint();
    bigint(unsigned int num);
    bigint(const bigint &source);
    
    std::string getStr()const;

    bigint& operator=(const bigint&source);

    //addition
    bigint operator+(const bigint& other)const;
    bigint& operator+=(const bigint &other);
    
    //increment
    bigint& operator++(); //++x
    bigint operator++(int); //x++

    //shift with int 
    bigint operator<<(unsigned int n)const;
    bigint operator>>(unsigned int n)const;
    bigint &operator<<=(unsigned int n);
    bigint &operator>>=(unsigned int n);
    
    //shift with class 
    bigint operator<<(const bigint &other) const;
    bigint operator>>(const bigint &other) const;
    bigint& operator<<=(const bigint &other);
    bigint& operator>>=(const bigint &other);

    // ==, !=, <, >, <=, >=
    bool operator==(const bigint& other) const;
    bool operator!=(const bigint& other) const;
    bool operator<(const bigint& other) const;
    bool operator>(const bigint& other) const;
    bool operator<=(const bigint& other) const;
    bool operator>=(const bigint& other) const;
  
};

std::ostream &operator<<(std::ostream &output, const bigint &obj);

#endif
