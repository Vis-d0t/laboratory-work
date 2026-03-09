#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    cout << "Выберите тип фигуры:\n";
    cout << "1 - Прямоугольник\n";
    cout << "2 - Треугольник\n";
    cout << "Введите номер: ";

    int type;
    cin >> type;

    if (type == 1) {
        // Прямоугольник
        double side_a, side_b;

        cout << "Введите длину первой стороны: ";
        cin >> side_a;
        cout << "Введите длину второй стороны: ";
        cin >> side_b;

        double area = side_a * side_b;
        double perimeter = 2 * (side_a + side_b);

        cout << fixed << setprecision(2);
        cout << "Площадь: " << area << endl;
        cout << "Периметр: " << perimeter << endl;
    }
    else if (type == 2) {
        // Треугольник
        double side_a, side_b, side_c;

        cout << "Введите первую сторону: ";
        cin >> side_a;
        cout << "Введите вторую сторону: ";
        cin >> side_b;
        cout << "Введите третью сторону: ";
        cin >> side_c;

        // Проверка существования треугольника
        if (side_a + side_b > side_c &&
            side_a + side_c > side_b &&
            side_b + side_c > side_a) {

            double semi_perimeter = (side_a + side_b + side_c) / 2;
            double area = sqrt(semi_perimeter *
                               (semi_perimeter - side_a) *
                               (semi_perimeter - side_b) *
                                (semi_perimeter - side_c));

            double perimeter = side_a + side_b + side_c;

            cout << fixed << setprecision(2);
            cout << "Площадь: " << area << endl;
            cout << "Периметр: " << perimeter << endl;
        }
        else {
            cout << "Треугольник с такими сторонами не существует." << endl;
        }
    }
    else {
        cout << "Некорректный выбор." << endl;
    }

    return 0;
}