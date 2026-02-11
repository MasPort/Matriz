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
    try {
        cout << b + a;
    }
    catch (...){
        cout << "no see pudo";
    }

    cout << "\n" << a;

    return 0;
}
