#include <iostream> // вариант 3
#include <cstdlib>
#include <ctime>

// заполнение
void fillArr(double* arr, int n, double A, double B) {
    for (int i = 0; i < n; i++)
        arr[i] = A + (double)rand() / RAND_MAX * (B - A);
}

// вывод
void printArr(double* arr, int n) {
    for (int i = 0; i < n; i++) std::cout << arr[i] << " ";
    std::cout << std::endl;
}

// среднее
double avgArr(double* arr, int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) sum += arr[i];
    return sum / n;
}

// сортировка выбором (убывание)
void sortSel(double* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int max_i = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] > arr[max_i]) max_i = j;

        double t = arr[i];
        arr[i] = arr[max_i];
        arr[max_i] = t;
    }
}

int main() {
    std::srand(std::time(0));

    int n;
    double A, B;

    std::cout << "n: ";
    std::cin >> n;

    std::cout << "A B: ";
    std::cin >> A >> B;

    double* arr = new double[n];

    fillArr(arr, n, A, B);

    std::cout << "Исходный:\n";
    printArr(arr, n);

    std::cout << "Среднее: " << avgArr(arr, n) << std::endl;

    sortSel(arr, n);

    std::cout << "Отсортированный:\n";
    printArr(arr, n);
}