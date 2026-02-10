#include <iostream>

#include "Matriz.h"

using namespace std;

int main()
{
    Matriz a(5, 7);

    cin >> a;

    cout << a;

    a.redimensionar(2, 5);

    cout << "\n" << a;

    return 0;
}
