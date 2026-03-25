#include <iostream>
using namespace std;

// рекурсивный вывод
void fr(int n, int a = 0, int b = 1) {
    if (n <= 0) return;
    cout << a << " ";
    fr(n - 1, b, a + b);
}

// итеративный вывод
void fi(int n) {
    int a = 0, b = 1, c;

    for (int i = 0; i < n; i++) {
        cout << a << " ";
        c = a + b;
        a = b;
        b = c;
    }
}

int main() {
    int n;

    cout << "n: ";
    cin >> n;

    if (n <= 0) {
        cout << "Ошибка\n";
        return 1;
    }

    cout << "Итеративно:\n";
    fi(n);

    cout << "\nРекурсивно:\n";
    fr(n);

    cout << endl;
    return 0;
}