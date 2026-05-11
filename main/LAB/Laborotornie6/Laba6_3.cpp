#include <iostream>
#include <fstream>
#include <cstring>

// Перечисление разрядов
enum Rd
{
    R1 = 1,
    R2,
    R3
};

struct Rb
{
    char fn[50];
    char dl[30];
    Rd rd;
    float ok;
};

// Вывод файла
void vw(std::ifstream& f)
{
    Rb r;

    while (f.read((char*)&r, sizeof(r)))
    {
        std::cout << "\nФИО: " << r.fn << "\n";
        std::cout << "Должность: " << r.dl << "\n";
        std::cout << "Разряд: " << r.rd << "\n";
        std::cout << "Оклад: " << r.ok << "\n";
    }
}

// Замена оклада
void ch(const char* nm, float nv)
{
    std::fstream f("rab.bin",
                    std::ios::binary |
                    std::ios::in |
                    std::ios::out);

    Rb r;

    while (f.read((char*)&r, sizeof(r)))
    {
        if (std::strcmp(r.fn, nm) == 0)
        {
            r.ok = nv;

            f.seekp(-sizeof(r), std::ios::cur);

            f.write((char*)&r, sizeof(r));

            break;
        }
    }

    f.close();
}

int main()
{
    int n;

    std::cout << "Количество работников: ";
    std::cin >> n;

    std::cin.ignore();

    std::ofstream of("rab.bin", std::ios::binary);

    Rb r;

    // Ввод данных
    for (int i = 0; i < n; i++)
    {
        std::cout << "\nРаботник " << i + 1 << "\n";

        std::cout << "ФИО: ";
        std::cin.getline(r.fn, 50);

        std::cout << "Должность: ";
        std::cin.getline(r.dl, 30);

        int x;

        std::cout << "Разряд (1-3): ";
        std::cin >> x;

        r.rd = (Rd)x;

        std::cout << "Оклад: ";
        std::cin >> r.ok;

        std::cin.ignore();

        of.write((char*)&r, sizeof(r));
    }

    of.close();

    // Вывод работников с окладом больше 25000
    std::ifstream inf("rab.bin", std::ios::binary);

    std::cout << "\nРаботники с окладом больше 25000:\n";

    while (inf.read((char*)&r, sizeof(r)))
    {
        if (r.ok > 25000)
        {
            std::cout << "\nФИО: " << r.fn << "\n";
            std::cout << "Должность: " << r.dl << "\n";
            std::cout << "Разряд: " << r.rd << "\n";
            std::cout << "Оклад: " << r.ok << "\n";
        }
    }

    inf.close();

    // Замена оклада
    char nm[50];
    float nv;

    std::cout << "\nВведите ФИО для изменения оклада: ";
    std::cin.getline(nm, 50);

    std::cout << "Введите новый оклад: ";
    std::cin >> nv;

    ch(nm, nv);

    // Проверка файла
    std::ifstream rf("rab.bin", std::ios::binary);

    std::cout << "\nСодержимое файла:\n";

    vw(rf);

    rf.close();

    return 0;
}