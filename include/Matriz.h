/**
 * \file matriz.hpp
 * \brief Definici&oacute;n de la clase Matriz para operaciones algebraicas.
 *
 * Esta clase permite realizar operaciones b&aacute;sicas entre matrices
 * como suma, resta, multiplicaci&oacute;n, c&aacute;lculo de determinante,
 * matriz inversa y transpuesta.
 *
 * Implementa memoria din&aacute;mica utilizando punteros dobles
 * para el almacenamiento de los datos.
 *
 * \author Jorge Alberto Guerrero Hernandez, Angel Mora Loustaunau
 * \date 10/02/2026
 */
#ifndef MATRIZ_H
#define MATRIZ_H

#include <iostream>

/**
 * @class Matriz
 * @brief Clase que representa una matriz din&aacute;mica de n&uacute;meros reales (double).
 *
 * Permite realizar operaciones b&aacute;sicas entre matrices como suma, resta,
 * multiplicaci&oacute;n matricial, multiplicaci&oacute;n por escalar, c&aacute;lculo de determinante,
 * matriz inversa, transpuesta y cofactor.
 */
class Matriz
{

    /**
     * @brief Sobrecarga del operador de salida.
     * Permite imprimir una matriz usando std::cout.
     */
    friend std::ostream& operator<<(std::ostream& os, const Matriz& a);

     /**
     * @brief Sobrecarga del operador de entrada.
     * Permite leer una matriz usando std::cin.
     */
    friend std::istream& operator>>(std::istream& is, Matriz& a);

    /**
     * @brief Multiplicaci&oacute;n de escalar por matriz (escalar * matriz).
     */
    friend Matriz operator*(double escalar, Matriz& a);
public:
    /**
     * @brief Constructor que crea una matriz vac&iacute;a con dimensiones dadas.
     * @param filas N&uacute;mero de filas.
     * @param columnas N&uacute;mero de columnas.
     */
    Matriz(unsigned int filas, unsigned int columnas);

    /**
     * @brief Constructor que crea una matriz usando una tabla ya existente.
     * @param filas N&uacute;mero de filas.
     * @param columnas N&uacute;mero de columnas.
     * @param entradas Puntero doble con los valores iniciales.
     */
    Matriz(unsigned int filas, unsigned int columnas, double** entradas);

    /**
     * @brief Constructor copia.
     * Crea una nueva matriz copiando otra existente.
     */
    Matriz(const Matriz& otra);

    /**
     * @brief Destructor.
     * Libera la memoria din&aacute;mica utilizada por la matriz.
     */
    virtual ~Matriz();

    /**
     * @brief Permite acceder a una fila de la matriz.
     * @param n &iacute;ndice de la fila.
     * @return Puntero a la fila n.
     */
    double* operator[](int n);

     /**
     * @brief Multiplicaci&oacute;n matricial.
     * @param a Matriz a multiplicar.
     * @return Nueva matriz resultado.
     */
    Matriz operator*(const Matriz& a);

    /**
     * @brief Suma de matrices.
     * @param a Matriz a sumar.
     * @return Nueva matriz resultado.
     */
    Matriz operator+(const Matriz& a);

    /**
     * @brief Resta de matrices.
     * @param a Matriz a restar.
     * @return Nueva matriz resultado.
     */
    Matriz operator-(const Matriz& a);

    /**
     * @brief Operador de asignaci&oacute;n.
     * Copia el contenido de otra matriz.
     */
    Matriz& operator=(const Matriz& a);

    /**
     * @brief Multiplicaci&oacute;n por escalar (matriz * escalar).
     * @param a Valor escalar.
     * @return Nueva matriz resultado.
     */
    Matriz operator*(const double a);

    /**
     * @brief Convierte la matriz en su transpuesta.
     */
    void transpuesta();

    /**
     * @brief Calcula y devuelve la matriz inversa.
     * @return Matriz inversa.
     */
    Matriz inversa();

    /**
     * @brief Calcula el determinante de la matriz.
     * @return Valor del determinante.
     */
    double determinante();

    /**
     * @brief Calcula la matriz de cofactores.
     * @return Matriz cofactor.
     */
    Matriz cofactor();

    /**
     * @brief Cambia el tamaño de la matriz.
     * @param filas Nuevo n&uacute;mero de filas.
     * @param columnas Nuevo n&uacute;mero de columnas.
     */
    void redimensionar(int filas, int columnas);
protected:

private:

    /// N&uacute;mero de filas de la matriz.
    unsigned int filas = 1;

    /// N&uacute;mero de columnas de la matriz.
    unsigned int columnas = 1;

    /// Puntero doble que almacena los valores de la matriz.
    double** entradas;

    /**
     * @brief Genera una tabla din&aacute;mica de tamaño filas x columnas.
     * @return Puntero doble con memoria reservada.
     */
    double** generarTabla(unsigned int filas, unsigned int columnas);
};

#endif // MATRIZ_H
