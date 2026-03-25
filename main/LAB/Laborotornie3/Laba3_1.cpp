#include <iostream>
using namespace std;

// проверка на палиндром
bool pal(int n) {
    int o = n, r = 0;

    while (n > 0) {
        r = r * 10 + n % 10;
        n /= 10;
    }

    return o == r;
}

int main() {
    int a, b;

    cout << "A: ";
    cin >> a;
    cout << "B: ";
    cin >> b;

    if (a >= b) {
        cout << "Ошибка\n";
        return 1;
    }

    cout << "Палиндромы:\n";

    for (int i = a; i <= b; i++) {
        if (pal(i)) cout << i << " ";
    }

    cout << endl;
    return 0;
}