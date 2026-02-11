#include <iostream>

#include "Matriz.h"

using namespace std;

int main()
{
    Matriz a(5, 7);
    Matriz b(2, 7);

    cin >> a;
    cin >> b;


    cout << a;
    cout << b;
    cout << a - b;



    return 0;
}
