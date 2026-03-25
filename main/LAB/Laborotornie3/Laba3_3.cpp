#include <iostream>
using namespace std;

// Функция вычисляет A^2, A^3, A^4
void pwr(double a, double &b, double &c, double &d) {
    b = a * a;        // A^2
    c = b * a;        // A^3
    d = c * a;        // A^4
}

int main() {
    double a, b, c, d;

    for (int i = 1; i <= 5; i++) {
        cout << "a" << i << ": ";
        cin >> a;

        pwr(a, b, c, d);

        cout << "a^2=" << b << " a^3=" << c << " a^4=" << d << endl;
    }

    return 0;
}