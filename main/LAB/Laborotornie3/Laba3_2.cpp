#include <iostream>
using namespace std;

// рекурсивный факториал
long long fr(int n) {
    if (n <= 1) return 1;
    return n * fr(n - 1);
}

// итеративный факториал
long long fi(int n) {
    long long r = 1;
    for (int i = 1; i <= n; i++) {
        r *= i;
    }
    return r;
}

int main() {
    int n;

    cout << "n: ";
    cin >> n;

    if (n < 0) {
        cout << "Ошибка\n";
        return 1;
    }

    cout << "Итеративно: " << fi(n) << endl;
    cout << "Рекурсивно: " << fr(n) << endl;

    return 0;
}