#ifndef MATRIZ_H
#define MATRIZ_H

#include <iostream>

class Matriz
{
    public:
        Matriz(unsigned int filas, unsigned int columnas);
        Matriz(unsigned int filas, unsigned int columnas, int** entradas);
        virtual ~Matriz();

        void operator=(int** entradas);
        int* operator[](int n);
        Matriz operator+(const Matriz& a);
        Matriz operator-(const Matriz& a);
        Matriz operator*(const int a);


        void redimensionar(int filas, int columnas);

        friend std::ostream& operator<<(std::ostream& os, const Matriz& a);
        friend std::istream& operator>>(std::istream& is, Matriz& a);
    protected:

    private:
        unsigned int filas = 1;
        unsigned int columnas = 1;
        int** entradas;

        int** generarTabla(unsigned int filas, unsigned int columnas);
};

#endif // MATRIZ_H
