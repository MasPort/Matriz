#include "Matriz.h"
#include <iostream>
#include <cmath>

Matriz::Matriz(unsigned int filas, unsigned int columnas)
{
    this->filas = filas;
    this->columnas = columnas;

    this->entradas = generarTabla(this->filas, this->columnas);
}

Matriz::Matriz(unsigned int filas, unsigned int columnas, double** entradas)
{
    this->filas = filas;
    this->columnas = columnas;

    this->entradas = entradas;
}

Matriz::~Matriz()
{
    for (unsigned int i = 0; i < filas; i++) {
        delete[] entradas[i];
    }
    delete[] entradas;
}

double* Matriz::operator[](int n)
{
    return entradas[n];
}

Matriz Matriz::operator*(const Matriz& a)
{
    if(this->columnas != a.filas) throw "Error: Tamano de matrices incorrecto";
    double** resultado = generarTabla(this->filas, a.columnas);

    for(unsigned int i = 0; i <  this->filas; ++i) {
        for(unsigned int j = 0; j < a.columnas; ++j) {
            for(unsigned int k = 0; k < this->columnas; ++k) {
                resultado[i][j] += this->entradas[i][k] * a.entradas[k][j];
            }
        }
    }

    return Matriz(this->filas, a.columnas, resultado);
}

void Matriz::transpuesta()
{
    double** resultado = generarTabla(this->columnas, this->filas);
    for(unsigned int i = 0; i < this->filas; ++i) {
        for(unsigned int j = 0; j < this->columnas; ++j) {
            resultado[j][i] = this->entradas[i][j];
        }
    }
    this->entradas = resultado;
    unsigned int temp = this->columnas;
    this->columnas = this->filas;
    this->filas = temp;
}

void Matriz::redimensionar(int filas, int columnas)
{
    double** nuevo = generarTabla(filas, columnas);

    for(int i = 0; i < std::min((int) this->filas, filas); ++i) {
        for(int j = 0; j < std::min((int) this->columnas, columnas); ++j) {
            nuevo[i][j] = this->entradas[i][j];
        }
    }

    for(unsigned int i = 0; i < this->filas; ++i) {
            delete[] this->entradas[i];
    }
    delete[] this->entradas;

    this->entradas = nuevo;
    this->filas = filas;
    this->columnas = columnas;
}

std::ostream& operator<<(std::ostream& os, const Matriz& a)
{
    for(unsigned int i = 0; i < a.filas; ++i) {
        for(unsigned int j = 0; j < a.columnas; ++j) {
            os << a.entradas[i][j] << " ";
        }
        os << std::endl;
    }

    return os;
}

std::istream& operator>>(std::istream& is, Matriz& a)
{
    int filas, columnas;
    std::cout << "Ingrese la cantidad de filas:\n";
    is >> filas;

    std::cout << "Ingrese la cantidad de columnas:\n";
    is >> columnas;

    a.redimensionar(filas, columnas);

    std::cout << "Ingrese los valores de la matriz (" << filas << "x" << columnas << "):\n";
    for(int i = 0; i < filas; ++i) {
        for(int j = 0; j < columnas; ++j) {
            is >> a[i][j];
        }
    }

    return is;
}

double** Matriz::generarTabla(unsigned int filas, unsigned int columnas)
{
    double** tabla;
    tabla = new double*[filas];
    for (unsigned int i = 0; i < filas; ++i) {
        tabla[i] = new double[columnas];
    }

    for(unsigned int i = 0; i < filas; ++i) {
        for(unsigned  int j = 0; j < columnas; ++j) {
            tabla[i][j] = 0;
        }
    }

    return tabla;
}

Matriz Matriz::cofactor()
{
    if (filas != columnas) throw "Error: La matriz no es cuadrada";
    int size = filas;
    double** resultado = generarTabla(size, size);

    for(int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            double** sub = generarTabla(size - 1, size - 1);
        }
    }
}
/*
 * Sobrecarga del operador * para multiplicar una matriz por un escalar.
 * @param a Escalar por el cual se multiplicará la matriz.
 * @return Nueva matriz resultado de la multiplicación.
 */
Matriz Matriz::operator*(const double a)
{
    double** Resultado = generarTabla(this->columnas, this->filas);
    for (unsigned int i = 0; i < this->filas; i++) {
        for (unsigned int j = 0; j < this->columnas; j++) {
            Resultado[i][j]= this->entradas[i][j]*a;
        }
    }
    return Matriz(this->filas, this->columnas, Resultado);

}
/*
 * Sobrecarga del operador + para sumar dos matrices.
 * @param a Matriz que se sumará con la matriz actual.
 * @return Nueva matriz resultado de la suma.
 * @throw Lanza una excepción si las dimensiones no coinciden.
 */
Matriz Matriz::operator+(const Matriz& a)
{

    if (this->columnas == a.columnas && this->filas == a.filas){
        double** Resultado = generarTabla(a.columnas, a.filas);
        for (unsigned int i = 0; i < this->filas; i++) {
            for (unsigned int j = 0; j < this->columnas; j++) {
                Resultado[i][j]= this->entradas[i][j] + a.entradas[i][j];
            }
        }
        return Matriz(a.filas, a.columnas, Resultado);
    }else{
      throw "no se pudo" ;
    }
}
/*
 * Sobrecarga del operador - para restar dos matrices.
 * @param a Matriz que se restará de la matriz actual.
 * @return Nueva matriz resultado de la resta.
 * @throw Lanza una excepción si las dimensiones no coinciden.
 */
Matriz Matriz::operator-(const Matriz& a)
{

    if (this->columnas == a.columnas && this->filas == a.filas){
        double** Resultado = generarTabla(a.columnas, a.filas);
        for (unsigned int i = 0; i < this->filas; i++) {
            for (unsigned int j = 0; j < this->columnas; j++) {
                Resultado[i][j]= this->entradas[i][j] - a.entradas[i][j];
            }
        }
        return Matriz(a.filas, a.columnas, Resultado);
    }else{
      throw "no se pudo" ;
    }
}
/*
 * Sobrecarga del operador * para permitir multiplicación
 * escalar * matriz.
 * @param escalar Valor escalar.
 * @param a Matriz a multiplicar.
 * @return Nueva matriz resultado.
 */
Matriz operator*(double escalar, Matriz& a)
{

    return a * escalar;
}
/*
 * Sobrecarga del operador de asignación.
 * @param a Matriz que será asignada.
 */
void Matriz::operator=(const Matriz& a)
{

double** Resultado = generarTabla(a.columnas, a.filas);
for (unsigned int i = 0; i < a.filas; i++) {
    for (unsigned int j = 0; j < a.columnas; j++) {
        Resultado[i][j]= a.entradas[i][j];
        }
    }
   redimensionar( a.filas, a.columnas);
   this->entradas=Resultado;


}

