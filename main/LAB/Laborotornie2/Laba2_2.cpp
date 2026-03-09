#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double sum;
    int category;

    cout << "Введите стоимость покупки (в рублях): ";
    cin >> sum;

    cout << "Категория покупателя:\n";
    cout << "1 - Студент\n";
    cout << "2 - Пенсионер\n";
    cout << "3 - Прочие\n";
    cout << "Введите номер категории: ";
    cin >> category;

    double discount = 0.0;  // Процент скидки

    // Определение скидки в зависимости от суммы и категории
    if (sum < 1000) {
        discount = 0.0;
    }
    else if (sum < 3000) {
        switch (category) {
            case 1: discount = 0.03; break;
            case 2: discount = 0.05; break;
            case 3: discount = 0.02; break;
            default: cout << "Некорректная категория.\n"; return 0;
        }
    }
    else if (sum < 5000) {
        switch (category) {
            case 1: discount = 0.07; break;
            case 2: discount = 0.10; break;
            case 3: discount = 0.05; break;
            default: cout << "Некорректная категория.\n"; return 0;
        }
    }
    else {
        switch (category) {
            case 1: discount = 0.10; break;
            case 2: discount = 0.15; break;
            case 3: discount = 0.08; break;
            default: cout << "Некорректная категория.\n"; return 0;
        }
    }

    double final_price = sum * (1 - discount);  // Итоговая стоимость с учетом скидки

    cout << fixed << setprecision(2);  // Установка формата вывода для денежных значений
    cout << "Итоговая стоимость: " << final_price << " руб." << endl;

    return 0;
}