#include <iostream>

#include "Matriz.h"

using namespace std;

int main()
{
    Matriz a(1, 1);

    cin >> a;

    cout << a.inversa()*a;

    return 0;
}
