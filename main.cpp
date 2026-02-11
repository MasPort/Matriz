#include <iostream>

#include "Matriz.h"

using namespace std;

int main()
{
    Matriz a(1, 1);
    Matriz b(3, 3);
    cin >> a;


    b = a;
    cout << b;

    return 0;
}
