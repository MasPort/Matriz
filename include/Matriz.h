#ifndef MATRIZ_H
#define MATRIZ_H

#include <iostream>

class Matriz
{
    friend std::ostream& operator<<(std::ostream& os, const Matriz& a);
    friend std::istream& operator>>(std::istream& is, Matriz& a);
    friend Matriz operator*(double escalar, Matriz& a);
    public:
        Matriz(unsigned int filas, unsigned int columnas);
        Matriz(unsigned int filas, unsigned int columnas, double** entradas);
        Matriz(consta Matriz& otra);
        virtual ~Matriz();

        Matriz& operator=(int** entradas);
        double* operator[](int n);
        Matriz operator*(const Matriz& a);
        Matriz operator+(const Matriz& a);
        Matriz operator-(const Matriz& a);
        void operator=(const Matriz& a);
        Matriz operator*(const double a);

        void transpuesta();
        Matriz inversa();
        double determinante();
        Matriz cofactor();
        void redimensionar(int filas, int columnas);
    protected:

    private:
        unsigned int filas = 1;
        unsigned int columnas = 1;
        double** entradas;

        double** generarTabla(unsigned int filas, unsigned int columnas);
};

#endif // MATRIZ_H
