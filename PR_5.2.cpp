#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

const double PI = 3.14159265358979323846;

// Обчислює суму ряду S = x + sum(a_n) з точністю eps.
// n - кількість доданків (параметр-посилання), s - сума (параметр-посилання)
void S(const double x, const double eps, int& n, double& s);

// Обчислює наступний доданок a за рекурентним співвідношенням: a_n = a_{n-1} * R
void A(const double x, const int n, double& a);

#ifndef UNIT_TEST
int main()
{
    double xp, xk, x, dx, eps, s = 0;
    int n = 0;
    cout << "xp = "; cin >> xp;
    cout << "xk = "; cin >> xk;
    cout << "dx = "; cin >> dx;
    cout << "eps = "; cin >> eps;

    cout << fixed;
    cout << "-----------------------------------------------------" << endl;
    cout << "|" << setw(7) << "x" << " |"
        << setw(10) << "arccos(x)" << " |"
        << setw(10) << "S" << " |"
        << setw(10) << "pi/2 - S" << " |"
        << setw(5) << "n" << " |"
        << endl;
    cout << "-----------------------------------------------------" << endl;

    x = xp;
    while (x <= xk + 1e-12)   // невелика похибка для накопичення dx
    {
        S(x, eps, n, s);
        cout << "|" << setw(7) << setprecision(2) << x << " |"
            << setw(10) << setprecision(5) << acos(x) << " |"
            << setw(10) << setprecision(5) << s << " |"
            << setw(10) << setprecision(5) << PI / 2 - s << " |"
            << setw(5) << n << " |"
            << endl;
        x += dx;
    }
    cout << "-----------------------------------------------------" << endl;
    return 0;
}
#endif

void S(const double x, const double eps, int& n, double& s)
{
    n = 0;          // номер першого доданку
    double a = x;   // перший доданок a_0 = x
    s = a;
    do {
        n++;
        A(x, n, a);
        s += a;
    } while (fabs(a) >= eps);
}

void A(const double x, const int n, double& a)
{
    // коефіцієнт рекурентності R = x^2 * (2n-1)^2 / (2n * (2n+1))
    double R = x * x * (2.0 * n - 1) * (2.0 * n - 1) / (2.0 * n * (2.0 * n + 1));
    a *= R;
}
