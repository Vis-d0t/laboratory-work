#include <iostream>

using namespace std;

int main() {
    int number;
    int sum = 0;

    do {
        cout << "Введите целое число (0 для завершения): ";
        cin >> number;

        // Проверяем, что число не равно нулю, чтобы не обрабатывать его
        if (number != 0) {
            int temp = abs(number);
            int d_sum = 0;

            // Вычисляем сумму цифр числа
            while (temp > 0) {
                d_sum += temp % 10;
                temp /= 10;
            }

            // Проверяем, является ли сумма цифр нечётной
            if (d_sum % 2 != 0) {
                cout << "Число " << number << " имеет нечётную сумму цифр." << endl;
                sum++;
            }
        }

    } while (number != 0);  // Цикл продолжается, пока пользователь не введёт 0

    cout << "Количество таких чисел: " << sum << endl;

    return 0;
}