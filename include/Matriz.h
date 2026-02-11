/*
 * Archivo: Matriz.h
 * Descripción: Definición de la clase Matriz y sus operadores
 *              sobrecargados.
 * Autor(es): Equipo de trabajo
 */
#ifndef MATRIZ_H
#define MATRIZ_H

#include <iostream>

/*
 * Clase Matriz
 * Representa una matriz de números reales almacenada
 * dinámicamente en memoria.
 * Permite operaciones como suma, resta, multiplicación,
 * determinante, inversa y transposición.
 */
class Matriz
{
    /* Operadores friend */
    friend std::ostream& operator<<(std::ostream& os, const Matriz& a);
    friend std::istream& operator>>(std::istream& is, Matriz& a);
    friend Matriz operator*(double escalar, Matriz& a);

public:

    /*
     * Constructor.
     * @param filas Número de filas.
     * @param columnas Número de columnas.
     */
    Matriz(unsigned int filas, unsigned int columnas);

    /*
     * Constructor con tabla inicial.
     * @param filas Número de filas.
     * @param columnas Número de columnas.
     * @param entradas Tabla de valores.
     */
    Matriz(unsigned int filas, unsigned int columnas, double** entradas);

    /*
     * Destructor.
     * Libera la memoria dinámica utilizada.
     */
    virtual ~Matriz();

    void operator=(int** entradas);
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
