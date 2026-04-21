#include <iostream>
#include <fstream>

int main() {
    int n;
    std::cout << "Сколько чисел ввести: ";
    std::cin >> n;

    std::ofstream f("nums.txt");

    int x;
    for (int i = 0; i < n; i++) {
        std::cout << "Введите число: ";
        std::cin >> x;
        f << x << " ";
    }

    f.close();

    int m;
    std::cout << "Сколько чисел считать: ";
    std::cin >> m;

    std::ifstream g("nums.txt");

    int s = 0;
    for (int i = 0; i < m; i++) {
        if (g >> x) {
            s += x;
        }
    }

    g.close();

    std::cout << "Сумма: " << s << std::endl;

    std::ofstream h("nums.txt", std::ios::app);
    h << std::endl << "Сумма: " << s;
    h.close();

    return 0;
}