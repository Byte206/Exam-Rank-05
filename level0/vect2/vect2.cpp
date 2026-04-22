#include "vect2.hpp"


//constructor pro defecto
vect2::vect2()
{
  this->x = 0;
  this->y = 0;
}


//constructor con argumentos
vect2::vect2(int num1, int num2)
{
  this->x = num1;
  this->y = num2;
}

//constructor copia
vect2::vect2(const vect2& source)
{
  *this = source;
}

//operador de igualar vector
vect2& vect2::operator=(const vect2& source)
{
  if(this != &source)
  {
    this->x = source.x;
    this->y = source.y;
  }
  return(*this);
}

//operador de acceso por indice solo lectura
int vect2::operator[](int index)const
{
  if(index == 0)
    return(this->x);
  return(this->y);
}

int& vect2::operator[](int index)
{
  if(index == 0)
    return(this->x);
  return(this->y);
}

//negacion urinaria,devuelve el vector con los signos cambiados
vect2 vect2::operator-() const
{
  vect2 temp = *this;
  temp[0] = -temp[0];
  temp[1] = -temp[1];
  return temp;
}

//multipilcar vector por un entero
vect2 vect2::operator*(int num)const
{
  vect2 temp;

  temp.x = this->x * num;
  temp.y = this->y * num;

  return(temp);
}

//multiplicacion y asignacion por un entero
vect2& vect2::operator*=(int num)
{
  this->x *= num;
  this->y *= num;
  return (*this);
}

//suma y asignacion por otro vector
vect2& vect2::operator+=(const vect2& obj)
{
  this->x += obj.x;
  this->y += obj.y;

  return(*this);
}

// resta y asignacion por otro vector
vect2& vect2::operator-=(const vect2& obj)
{
  this->x -= obj.x;
  this->y -= obj.y;

  return(*this);
}

//multipilacion y asignacion por otro vector
vect2& vect2::operator*=(const vect2& obj)
{
  this->x *= obj.x;
  this->y *= obj.y;

  return(*this);
}

//Multiplicacion,suma,resta por otro vector(devolviendo uno nuevo)
vect2 vect2::operator+(const vect2& obj) const
{
  vect2 temp = *this;

  temp.x += obj.x;
  temp.y += obj.y;

  return temp;
}

vect2 vect2::operator-(const vect2& obj) const
{
  vect2 temp = *this;
  temp.x -= obj.x;
  temp.y -= obj.y;

  return temp;
}

vect2 vect2::operator*(const vect2& obj) const
{
  vect2 temp = *this;
  temp.x *= obj.x;
  temp.y *= obj.y;

  return temp;
}

//Pre-incremento ++v 

vect2& vect2::operator++()
{
  this->x += 1;
  this->y += 1;

  return(*this);
}

//Post-incremento v++

vect2 vect2::operator++(int)
{
  vect2 temp = *this;

  ++(*this);
  return(temp);
}

//Pre-decremento --v 

vect2& vect2::operator--()
{
  this->x -= 1;
  this->y -= 1;

  return(*this);
}

//Post-decremento v--

vect2 vect2::operator--(int)
{
  vect2 temp = *this;

  --(*this);
  return(temp);
}


//comparaciones


bool vect2::operator==(const vect2& obj)const
{
  if(this->x == obj.x && this->y == obj.y)
    return(true);
  return(false);
}

bool vect2::operator!=(const vect2& obj)const
{
  return (!(obj == *this));
}

//destructor
vect2::~vect2()
{

}

//sobre carga del <<
std::ostream& operator<<(std::ostream& os, const vect2& obj)
{
  os <<"{"<< obj[0] << ", " << obj[1] << "}";
  return(os);
}

vect2 operator*(int num, const vect2& obj)
{
  vect2 temp(obj);

  temp *= num;

  return temp;
}
