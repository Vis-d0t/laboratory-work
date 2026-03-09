#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int n;
    double x;

    cout << "Введите n: ";
    cin >> n;

    cout << "Введите x (|x| < 1): ";
    cin >> x;

    double sum = 0.0;  // Сумма ряда
    double step = 1.0;  // Текущий член ряда (x^k)

    for (int i = 0; i < n; i++) {
        sum += step;
        step = step * x;  // рекуррентное вычисление степени
    }

    double function_value = 1 / (1 - x);  // Вычисление значения функции 1/(1-x)

    cout << fixed << setprecision(6);  // Установка формата вывода для чисел с плавающей точкой
    cout << "Сумма ряда: " << sum << endl;
    cout << "Значение функции 1/(1-x): " << function_value << endl;

    return 0;
}