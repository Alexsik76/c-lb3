#include <iostream>
#include <cmath>

using namespace std;

int k = 3, n = 8;

int get_binom(int n, int k);
long get_factorial(int x);
double get_bernoulli(int x);
double get_tg(float x);

int main()
{

    for (float i = -2; i <= 2; i += 0.5)
    {
        float tg = get_tg(i);
        cout << "self tg     \t" << i << "\t =" << tg << "\n";
        cout << "standart tg \t" << i << "\t =" << tan(i) << "\n";
        cout << "-----------------------------------------------\n";
    }

    return 0;
}
int get_binom(int n, int k)
{
    int res = get_factorial(n) / (get_factorial(k) * get_factorial(n - k));
    // cout << "Binom of " << n <<" and "<< k << " = " << res << "\n";
    return res;
}
long get_factorial(int x)
{
    long res = 0;
    if ((x < 0) || (x > 20))
    {
        cout << "Error! Factorial.";
        return res;
    }
    else
    {
        res = 1.0;
        for (int i = 1; i <= x; i++)
        {
            res *= i;
        }
        // cout << "Fact of " << x << " = " << res << "\n";
        return res;
    }
}
double get_bernoulli(int x)
{
    double res = 0;
    if (x == 1)
    {
        res = -0.5;
    }
    else if (x == 0)
    {
        res = 1;
    }
    else if (x == 2)
    {
        res = 1.0 / 6;
    }
    else if ((x % 2) == 1)
    {
        res = 0;
    }
    else
    {
        res = 0;
        for (int i = 1; i <= x; i++)
        {
            double old_bernouli = get_bernoulli(x - i);
            int binom = get_binom((x + 1), (i + 1));
            double t = binom * old_bernouli;
            res += t;
        }
        res *= (-1.0 / (x + 1));
    }
    return res;
}
double get_tg(float x)
{
    double res = 0;
    for (int i = 1; i <= 5; i++)
    {
        double y = ((get_bernoulli(2 * i) * pow(-4, i) * (1 - pow(4, i))) / get_factorial(2 * i)) * pow(x, (2 * i - 1));
        res += y;
    }
    return res;
}
