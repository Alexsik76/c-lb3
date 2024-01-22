#include <iostream>
#include <cmath>

using namespace std;

double sin_t(double x, int n);
double cos_t(double x, int n);
double tg_t(double x, int n);

double sin_t(double x, int n_t)
// gets sin(x) by Taylor series
{
    double res = x;
    int n = 1;
    long long denom = 1;
    while (n <= n_t)
    {
        denom *= (2 * n + 1) * 2 * n;
        res += pow(-1, n) * pow(x, (2 * n + 1)) / denom;
        n++;
    }
    return res;
}

double cos_t(double x, int n_t)
// gets cos(x) by Taylor series
{
    double res = 1;
    int n = 1;
    long long denom = 1;
    while (n <= n_t)
    {
        denom *= (2 * n - 1) * 2 * n;
        res += pow(-1, n) * pow(x, (2 * n)) / denom;
        n++;
    }
    return res;
}

double tg_t(double x, int n)
{
    if (n > 9)
    {
        // because we gets (2*n)! and 20! > LONG_LONG_MAX
        n = 9;
    }
    return sin_t(x, n) / cos_t(x, n);
}
