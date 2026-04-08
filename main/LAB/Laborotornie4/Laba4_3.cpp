#include <iostream>
#include <cstdlib>
#include <ctime>

// создание
int** createMat(int r, int c) {
    int** m = new int*[r];
    for (int i = 0; i < r; i++)
        m[i] = new int[c];
    return m;
}

// заполнение
void fillMat(int** m, int r, int c) {
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            m[i][j] = rand() % 201 - 100;
}

// вывод
void printMat(int** m, int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++)
            std::cout << m[i][j] << "\t";
        std::cout << std::endl;
    }
}

// поиск максимума
void findMax(int** m, int r, int c, int& val, int& ri, int& ci) {
    val = m[0][0];
    ri = 0;
    ci = 0;

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            if (m[i][j] > val) {
                val = m[i][j];
                ri = i;
                ci = j;
            }
}

int main() {
    std::srand(std::time(0));

    int r, c;
    std::cout << "rows cols: ";
    std::cin >> r >> c;

    int** m = createMat(r, c);

    fillMat(m, r, c);

    printMat(m, r, c);

    int val, ri, ci;
    findMax(m, r, c, val, ri, ci);

    std::cout << "Max: " << val << " [" << ri << "," << ci << "]\n";
}