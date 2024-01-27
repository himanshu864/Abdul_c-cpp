#include <iostream>
using namespace std;

double person(double x, double n, double i = 1, double curr = 1)
{
    if (n == 0)
        return 1;
    curr *= (x / i++);
    return curr + person(x, n - 1, i, curr);
}

double e(double x, double n)
{
    static double ctrl = 1;
    if (n == 0)
        return 1;
    double shift = e(x, n - 1); // notice this is head-recursion
    ctrl *= (x / n);
    return ctrl + shift;
}

int main()
{
    double x = 1;
    double n = 10;
    cout << e(x, n) << endl;
    cout << person(x, n) << endl;
    return 0;
}

// this is tyler series where e^x = 1 + x/1 + x^2/2! + x^3/3! + ... n terms
// x is the power of e
// n is the number of terms
