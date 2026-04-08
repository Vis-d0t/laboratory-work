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

// удаление строки
void delRow(int**& m, int& r, int row) {
    for (int i = row; i < r - 1; i++)
        m[i] = m[i + 1];
    r--;
}

// вставка строки
void addRow(int**& m, int& r, int c, int pos) {
    int** nm = new int*[r + 1];

    for (int i = 0; i < pos; i++) nm[i] = m[i];

    nm[pos] = new int[c];
    for (int j = 0; j < c; j++) nm[pos][j] = 0;

    for (int i = pos; i < r; i++) nm[i + 1] = m[i];

    m = nm;
    r++;
}

int main() {
    std::srand(std::time(0));

    int r, c;
    std::cout << "rows cols: ";
    std::cin >> r >> c;

    int** m = createMat(r, c);
    fillMat(m, r, c);

    std::cout << "До:\n";
    printMat(m, r, c);

    int row;
    std::cout << "Удалить строку: ";
    std::cin >> row;

    delRow(m, r, row);

    std::cout << "После удаления:\n";
    printMat(m, r, c);

    int pos;
    std::cout << "Вставить строку: ";
    std::cin >> pos;

    addRow(m, r, c, pos);

    std::cout << "После вставки:\n";
    printMat(m, r, c);
}