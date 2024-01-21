#include <iostream>
#include <cmath>

using namespace std;

void fib(int *les_pointer, int *more_pointer, int *a_pointer);

int main()
{
    int a = 2584, fib_les_a, fib_over_a;

    fib(&fib_les_a,  &fib_over_a, &a);

    cout << fib_les_a << " <= " << a << " <= " << fib_over_a << "\n";
    return 0;
}

void fib(int *les_pointer, int *more_pointer, int *a_pointer)
{
    int a = 0, b = 1, c = 0, i;

    while (c < *a_pointer)
    {
        c = a + b;
        a = b;
        b = c;
    }

    *more_pointer = c;
    *les_pointer = a;
}
