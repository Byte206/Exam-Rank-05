#ifndef VECT2_HPP
# define VECT2_HPP
# include <iostream>

class vect2 
{
  private:
    int x;
    int y;
  public:
    vect2();
    vect2(int num1, int num2);
    vect2(const vect2& source);
    
    //Asignacion
    vect2& operator=(const vect2& source);

    //Acceso solo por lectura
    int operator[](int index)const;

    //Acceso por indice con modificacion
    int& operator[](int index);

    //negacion unitaria
    vect2 operator-()const;

    //multiplicar por int,devuelve nuevo vector
    vect2 operator*(int num) const;

    //multiplica y asigna vector por un int
    vect2& operator*=(int num);

    //Suma,resta y multiplica y asigna a otro vector por este mismo
    
    vect2& operator*=(const vect2 &obj);
    vect2& operator-=(const vect2 &obj);
    vect2& operator+=(const vect2 &obj);

    //Suma,resta y multiplica devolviendo un nuevo vector

    vect2 operator+(const vect2 &obj) const;
    vect2 operator-(const vect2 &obj) const;
    vect2 operator*(const vect2 &obj) const;

    //pre-incremento ++v
    vect2& operator++();

    //post-incremento, devuelve una copia y despues incrementa
    vect2 operator++(int);

    //pre-decremento --v 
    vect2& operator--();

    //post-decremento v--, devuelve una copia y despues resta
    vect2 operator--(int);

    bool operator==(const vect2 &obj) const;
    bool operator!=(const vect2 &obj) const;

    ~vect2();
};

//permite escribir escalar(numro) * vector 3 * vector ,devuele nuevo vector 
vect2 operator*(int num, const vect2& obj);

//permite imprimir vector en stdout
std::ostream& operator<<(std::ostream &os, const vect2 &obj);

#endif
