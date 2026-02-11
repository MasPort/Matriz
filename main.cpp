#include <iostream>

#include "Matriz.h"

using namespace std;

int main()
{
    Matriz a(2, 2);

    cin >> a;
    cout << a * 5 << endl;


    cout << 5 * a << endl;

    return 0;
}
