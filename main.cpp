#include <iostream>

#include "Matriz.h"

using namespace std;

int main()
{
    Matriz a(1, 1);
    Matriz b(1, 1);

    cin >> a;
    cout << a << endl;

    cin >> b;
    cout << b << endl;

    cout << a * b;

    return 0;
}
