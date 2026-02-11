#include "Matriz.h"
#include <iostream>
#include <cmath>

/*
 * Constructor que crea una matriz con dimensiones dadas.
 * @param filas Número de filas.
 * @param columnas Número de columnas.
 */
Matriz::Matriz(unsigned int filas, unsigned int columnas)
{
    this->filas = filas;
    this->columnas = columnas;

    this->entradas = generarTabla(this->filas, this->columnas);
}

/*
 * Constructor que crea una matriz con dimensiones dadas
 * y una tabla ya inicializada.
 * @param filas Número de filas.
 * @param columnas Número de columnas.
 * @param entradas Tabla de valores.
 */
Matriz::Matriz(unsigned int filas, unsigned int columnas, double** entradas)
{
    this->filas = filas;
    this->columnas = columnas;

    this->entradas = entradas;
}

/*
 * Destructor. Libera la memoria dinámica utilizada.
 */
Matriz::~Matriz()
{
    for (unsigned int i = 0; i < filas; i++) {
        delete[] entradas[i];
    }
    delete[] entradas;
}

/*
 * Sobrecarga del operador [] para acceder a una fila.
 * @param n Índice de la fila.
 * @return Puntero a la fila solicitada.
 */
double* Matriz::operator[](int n)
{
    return entradas[n];
}

/*
 * Sobrecarga del operador * para multiplicación matriz * matriz.
 * @param a Matriz a multiplicar.
 * @return Nueva matriz resultado.
 * @throw Lanza excepción si las dimensiones no son compatibles.
 */
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

/*
 * Convierte la matriz actual en su transpuesta.
 */
void Matriz::transpuesta()
{
    double** resultado = generarTabla(columnas, filas);
    for(unsigned int i = 0; i < filas; ++i) {
        for(unsigned int j = 0; j < columnas; ++j) {
            resultado[j][i] = entradas[i][j];
        }
    }

    for (unsigned int i = 0; i < filas; ++i) {
        delete[] entradas[i];
    }
    delete[] entradas;

    entradas = resultado;
    std::swap(filas, columnas);
}

/*
 * Calcula la matriz inversa.
 * @return Matriz inversa.
 * @throw Lanza excepción si la matriz no es cuadrada o no tiene inversa.
 */
Matriz Matriz::inversa()
{
    if (filas != columnas) throw "La matriz no es cuadrada";
    double det = determinante();
    if (det == 0) throw "La matriz no tiene inversa";

    Matriz adj = cofactor();
    adj.transpuesta();

    return adj * (1.0 / det);
}

/*
 * Calcula el determinante de la matriz.
 * @return Valor del determinante.
 * @throw Lanza excepción si la matriz no es cuadrada.
 */
double Matriz::determinante()
{
    if (filas != columnas) throw "La matriz no es cuadrada";
    if (filas == 1) return entradas[0][0];
    if (filas == 2) return entradas[0][0] * entradas[1][1] - entradas[0][1] * entradas[1][0];

    double det = 0.0;

    for (unsigned int j = 0; j < columnas; ++j) {

        double** sub = generarTabla(filas - 1, columnas - 1);

        int subi = 0;
        for (unsigned int i = 1; i < filas; ++i) {
            int subj = 0;
            for (unsigned int k = 0; k < columnas; ++k) {
                if (k == j) continue;
                sub[subi][subj++] = entradas[i][k];
            }
            subi++;
        }
        Matriz menor(filas - 1, columnas - 1, sub);
        det += std::pow(-1, j) * entradas[0][j] * menor.determinante();
    }

    return det;
}

/*
 * Redimensiona la matriz conservando los valores existentes.
 * @param filas Nuevo número de filas.
 * @param columnas Nuevo número de columnas.
 */
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

/*
 * Sobrecarga del operador << para salida por flujo.
 */
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

/*
 * Sobrecarga del operador >> para entrada por flujo.
 */
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

/*
 * Genera dinámicamente una tabla bidimensional
 * inicializada en cero.
 */
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

/*
 * Calcula la matriz de cofactores.
 * @return Matriz de cofactores.
 */
Matriz Matriz::cofactor()
{
    if (filas != columnas) throw "Error: La matriz no es cuadrada";

    int n = filas;
    double** resultado = generarTabla(n, n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            double** sub = generarTabla(n - 1, n - 1);

            int subi = 0;
            for (int fi = 0; fi < n; ++fi) {
                if (fi == i) continue;

                int subj = 0;
                for (int cj = 0; cj < n; ++cj) {
                    if (cj == j) continue;
                    sub[subi][subj++] = entradas[fi][cj];
                }
                subi++;
            }

            Matriz menor(n - 1, n - 1, sub);
            resultado[i][j] = pow(-1, i + j) * menor.determinante();
        }
    }
    return Matriz(n, n, resultado);
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

