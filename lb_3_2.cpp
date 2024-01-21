#include <iostream>
#include <cmath>

using namespace std;

int fib(int n);

int main(){
 int a = 356, fib_les_a, fib_over_a, n = 1;

int *les_pointer = &fib_les_a;
int *more_pointer = &fib_over_a;
while (*more_pointer < a) {
    *les_pointer = fib(n);
    n++;
    *more_pointer = fib(n); 
}
fib_over_a = fib(n);
fib_les_a = fib(n-1);
cout << n <<"\t"<<fib_les_a<<"\t"<<fib_over_a<<"\n";
 return 0;
}

int fib(int n) 
{ 
    if (n <= 1) 
        return n; 
    return fib(n - 1) + fib(n - 2); 
} 
