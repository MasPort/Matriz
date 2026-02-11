#include <iostream>

#include "Matriz.h"

using namespace std;

int main()
{
    Matriz a(1, 1);
    Matriz b(2, 2);

    cin >> a;

    cout << 1.0 / a.determinante();
    cout << a.inversa() * (1.0 / a.determinante());

    return 0;
}
