#ifndef MATRIZ_H
#define MATRIZ_H

#include <iostream>

class Matriz
{
    public:
        Matriz(unsigned int filas, unsigned int columnas);
        virtual ~Matriz();

        void operator=(int** entradas);
        int* operator[](int n);
        void operator+(const Matriz& a);
        void operator-(const Matriz& a);

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
