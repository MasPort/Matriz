#include <iostream>

#include "Matriz.h"

using namespace std;

int main()
{
    Matriz a(1, 1);

    cin >> a;
    cout << a << endl;

    a.transpuesta();

    cout << a << endl;

    return 0;
}
