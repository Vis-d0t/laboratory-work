#include <iostream>
#include <fstream>

double f(double x) {
    return 2.5 * x - x * x + 10;
}

int main() {
    double a, b, h;

    std::cout << "Введите a и b: ";
    std::cin >> a >> b;

    std::cout << "Введите шаг: ";
    std::cin >> h;

    std::ofstream f1("tab.txt");

    f1 << "x\tf(x)" << std::endl;
    f1 << "----------------" << std::endl;

    for (double x = a; x <= b; x += h) {
        f1 << x << "\t" << f(x) << std::endl;
    }

    f1.close();

    std::cout << "Таблица записана в файл tab.txt" << std::endl;

    return 0;
}