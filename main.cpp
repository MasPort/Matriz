#include <iostream>

#include "Matriz.h"

using namespace std;

int main()
{
    Matriz a(2, 2);

    cin >> a;

    cout << a;

    a.redimensionar(3, 3);

    cout << a;

    return 0;
}
