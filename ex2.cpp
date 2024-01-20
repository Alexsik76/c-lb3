#include <iostream>
#include <cmath>
#include <typeinfo>
using namespace std;


long long  get_factorial(int x)
{
    long long res = 0;
    if ((x < 0) || (x > 40))
    {
        cout << "Error! Factorial.";
        return res;
    }
    else
    {
        res = 1;
        for (int i = 1; i <= x; i++)
        {
            if ((res * i) >= res){
            res *= i;
            }
            else {
                cout << i << "\t"<<res << endl;
                cout << "Too big factorial.\n";
            } 
        }
        // cout << "Fact of " << x << " = " << res << "\n";
        return res;
    }
}
double get_cos(double x)
{
 double res = 0;
 int n = 0;
 while (n < 10)
 {
  res += pow(-1, n)*(pow(x, 2*n) / (get_factorial(2*n)));
  n++;
 }
 return res;
}
double get_sin(double x)
{
 double res = 0;
 int n = 0;
 while (n < 8)
 {
  res += pow(-1, n)*pow(x, (2*n+1)) / (get_factorial(2*n +1));
  n++;
 }
 return res;
}
int main() {

double x, eps=0.001, y;

for (double i=-3; i <=3; i += 0.5){
    cout << "sin:\n";
    double _sin = get_sin(i);
    cout << i << "\t" << _sin << "\n";
    cout << i << "\t" << sin(i) << "\n";
    cout << "------------------\n";
    cout << "cos:\n";
    double _cos = get_cos(i);
    cout << i << "\t" << _cos << "\n";
    cout << i << "\t" << cos(i) << "\n";
    cout << "------------------\n";
    cout << "tan:\n";
    double _tn = _sin / _cos;
    double _tn2 = sin(i)/cos(i);
    cout << i << "\t" << _tn << "\n";
    cout << i << "\t" << _tn2 << "\n";
    cout << i << "\t" << tan(i) << "\n";
    cout << "------------------\n";

}
}