#include <iostream>
#include <fstream>
#include <string>

struct Sb
{
    std::string nm;
    int oc;
};

struct St
{
    std::string fn;
    std::string fk;
    std::string gr;
    Sb sb[5];
};

int main()
{
    const int n = 3;

    St st[n];

    // Ввод данных
    for (int i = 0; i < n; i++)
    {
        std::cout << "Студент " << i + 1 << "\n";

        std::cout << "ФИО: ";
        std::getline(std::cin, st[i].fn);

        std::cout << "Факультет: ";
        std::getline(std::cin, st[i].fk);

        std::cout << "Группа: ";
        std::getline(std::cin, st[i].gr);

        for (int j = 0; j < 5; j++)
        {
            std::cout << "Предмет: ";
            std::getline(std::cin, st[i].sb[j].nm);

            std::cout << "Оценка: ";
            std::cin >> st[i].sb[j].oc;
            std::cin.ignore();
        }
    }

    // Запись в файл
    std::ofstream of("stud.txt");

    for (int i = 0; i < n; i++)
    {
        of << st[i].fn << '\n';
        of << st[i].fk << '\n';
        of << st[i].gr << '\n';

        for (int j = 0; j < 5; j++)
        {
            of << st[i].sb[j].nm << '\n';
            of << st[i].sb[j].oc << '\n';
        }
    }

    of.close();

    // Чтение из файла
    std::ifstream inf("stud.txt");

    std::string fn, fk, gr, nm;
    int oc;

    std::cout << "\nСтуденты со средним баллом больше 4:\n";

    while (std::getline(inf, fn))
    {
        std::getline(inf, fk);
        std::getline(inf, gr);

        int sm = 0;

        for (int j = 0; j < 5; j++)
        {
            std::getline(inf, nm);
            inf >> oc;
            inf.ignore();

            sm += oc;
        }

        double sr = sm / 5.0;

        if (sr > 4)
        {
            std::cout << "\nФИО: " << fn << "\n";
            std::cout << "Факультет: " << fk << "\n";
            std::cout << "Группа: " << gr << "\n";
            std::cout << "Средний балл: " << sr << "\n";
        }
    }

    inf.close();

    return 0;
}