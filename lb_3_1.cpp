#include <iostream>
#include <cmath>
#include "tg.h"

using namespace std;

double f1(double x, double *dev_pointer, int *n_pointer);
double f2(double x, double *dev_pointer, int *n_pointer);
double get_y(float x, double *dev_pointer, int *n_pointer);

// int main()
// {
//     int n = 8; // the length of the Taylor series
//     for (float i = -3; i <= 3; i += 0.5)
//     {   
//         int *n_pointer = &n;
//         double deviation = 0;
//         double *dev_pointer = &deviation;
//         double y = get_y(i, dev_pointer, n_pointer);
//         cout << "with x = " << i << "\t y = " << y << "\t n = " << n ;
//         cout <<  "\t deviation = " << deviation << "\n"; 
//         cout << "----------------------------------------------------------------\n";
//     }

//     return 0;
// }

double f1(double x, double *dev_pointer, int *n_pointer)
{
    int n = *n_pointer;
    double res = (tg_t(x, n) - (x / 2)) / (tg_t((2 * x), n));
    double st = (tan(x) - (x / 2)) / (tan(2 * x));
    *dev_pointer = fabs(res - st);
    return res;
}

double f2(double x, double *dev_pointer, int *n_pointer)
{
    int n = *n_pointer;
    double res = tg_t((x + 2), n) - pow(tg_t((2 * x), n), 2);
    double st = tan(x +2) - pow(tan(2 * x), 2);
    *dev_pointer = fabs(res - st);
    return res;
}

double get_y(float x, double *dev_pointer, int *n_pointer)
{
    double res;
    if ((x >= -2) && (x < 0))
    {
        res = f1(x, dev_pointer, n_pointer);
    }
    else if ((x <= 2) && (x > 0))
    {
        res = f2(x, dev_pointer, n_pointer);
    }
    else
    {
        res = NAN;
    }
    return res;
}
