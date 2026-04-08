#include <iostream> // вариант 3

// вывод
void printArr(int* arr, int n) {
    for (int i = 0; i < n; i++) std::cout << arr[i] << " ";
    std::cout << std::endl;
}

// удаление кратных 3
void del3(int* arr, int& n) {
    for (int i = 0; i < n; i++) {
        if (arr[i] % 3 == 0) {
            for (int j = i; j < n - 1; j++)
                arr[j] = arr[j + 1];
            n--;
            i--;
        }
    }
}

// вставка 0 после K
void addK(int* arr, int& n, int K) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == K) {
            for (int j = n; j > i + 1; j--)
                arr[j] = arr[j - 1];
            arr[i + 1] = 0;
            n++;
            i++;
        }
    }
}

int main() {
    int n, K;

    std::cout << "n: ";
    std::cin >> n;

    int* arr = new int[n + 100]; // запас

    for (int i = 0; i < n; i++) std::cin >> arr[i];

    std::cout << "Исходный:\n";
    printArr(arr, n);

    del3(arr, n);

    std::cout << "После удаления:\n";
    printArr(arr, n);

    std::cout << "K: ";
    std::cin >> K;

    addK(arr, n, K);

    std::cout << "После вставки:\n";
    printArr(arr, n);
}