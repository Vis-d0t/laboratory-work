#include <iostream>
using namespace std;

// ВАРИАНТ 3
// вычисление суммы ряда e^x
double sr(double x, double e) {
    double s = 1.0;   // сумма
    double t = 1.0;   // текущий член
    int n = 1;

    while (t > e) {
        t = t * x / n;  // рекуррентная формула
        s += t;
        n++;
    }

    return s;
}

int main() {
    double x, e;

    cout << "x: ";
    cin >> x;
    cout << "eps: ";
    cin >> e;

    if (e <= 0) {
        cout << "Ошибка\n";
        return 1;
    }

    cout << "Сумма ряда: " << sr(x, e) << endl;

    return 0;
}