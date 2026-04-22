#include "test.hpp"

vect2::vect2()
{
  this->x = 0;
  this->y = 0;
}

vect2::vect2(int num1, int num2)
{
  this->x = num1;
  this->y = num2;
}

vect2::vect2(const vect2 &source)
{
  *this = source;
}

vect2& vect2::operator=(const vect2& source)
{
  if(this != &source)
  {
    this->x = source.x;
    this->y = source.y;
  }
  return(*this);
}

int vect2::operator[](int index) const
{
  if(index == 0)
    return (this->x);
  return(this->y);
}

int& vect2::operator[](int index)
{
  if (index == 0)
    return(this->x);
  return(this->y);
}

vect2 vect2::operator-()const
{
  vect2 temp = *this;

  temp.x = -this->x;
  temp.y = -this->y;

  return(temp);
}

vect2 vect2::operator*(int num) const
{
  vect2 temp = *this;
  temp.x *= num;
  temp.y *= num;

  return(temp);
}

vect2& vect2::operator*=(int num)
{
  this->x *= num;
  this->y *= num;

  return(*this);
}

vect2& vect2::operator+=(const vect2& obj)
{
  this->x += obj.x;
  this->y += obj.y;

  return(*this);
}

vect2& vect2::operator-=(const vect2& obj)
{
  this->x -= obj.x;
  this->y -= obj.y;

  return(*this);
}

vect2& vect2::operator*=(const vect2& obj)
{
  this->x *= obj.x;
  this->y *= obj.y;

  return(*this);
}

vect2 vect2::operator+(const vect2& obj) const
{
  vect2 temp = *this;

  temp.x += obj.x;
  temp.y += obj.y;

  return(temp);
}

vect2 vect2::operator-(const vect2& obj) const
{
  vect2 temp = *this;

  temp.x -= obj.x;
  temp.y -= obj.y;

  return(temp);
}

vect2 vect2::operator*(const vect2& obj) const
{
  vect2 temp = *this;

  temp.x *= obj.x;
  temp.y *= obj.y;

  return(temp);
}

vect2& vect2::operator++()
{
  this->x += 1;
  this->y += 1;

  return(*this);
}

vect2 vect2::operator++(int)
{
  vect2 temp = *this;

  this->x += 1;
  this->y += 1;
  return (temp);
}

vect2& vect2::operator--()
{
  this->x -= 1;
  this->y -= 1;

  return(*this);
}

vect2 vect2::operator--(int)
{
  vect2 temp = *this;

  this->x -= 1;
  this->y -= 1;
  return (temp);
}

bool vect2::operator==(const vect2 &obj) const
{
  if(this->x == obj.x && this->y == obj.y)
    return(true);
  return(false);
}

bool vect2::operator!=(const vect2 &obj) const
{
  if (this->x == obj.x && this->y == obj.y)
    return (false);
  return(true);
}

vect2::~vect2()
{

}

vect2 operator*(int num, const vect2 &obj)
{
  vect2 temp = obj;

  temp *= num;

  return (temp);
}

std::ostream& operator<<(std::ostream& os, const vect2 &obj)
{
  os << "{" << obj[0] << ", "<<obj[1] << "}";
  return (os);
}
