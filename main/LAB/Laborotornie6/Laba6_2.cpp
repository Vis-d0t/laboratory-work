#include <iostream>
#include <fstream>

bool pr(int x)
{
    if (x < 2)
    {
        return false;
    }

    for (int i = 2; i < x; i++)
    {
        if (x % i == 0)
        {
            return false;
        }
    }

    return true;
}

// Вывод бинарного файла
void vw(std::ifstream& f)
{
    int x;

    while (f.read((char*)&x, sizeof(x)))
    {
        std::cout << x << " ";
    }

    std::cout << "\n";
}

int main()
{
    // Создание текстового файла
    std::ofstream tf("num.txt");

    for (int i = 1; i <= 20; i++)
    {
        tf << i << " ";
    }

    tf.close();

    // Перепись в бинарный файл
    std::ifstream inf("num.txt");
    std::ofstream bf("num.bin", std::ios::binary);

    int x;

    while (inf >> x)
    {
        bf.write((char*)&x, sizeof(x));
    }

    inf.close();
    bf.close();

    // Изменение записи
    std::fstream fb("num.bin", std::ios::binary |
                                std::ios::in |
                                std::ios::out);

    int id, nv;

    std::cout << "Номер записи: ";
    std::cin >> id;

    std::cout << "Новое значение: ";
    std::cin >> nv;

    fb.seekp((id - 1) * sizeof(int));

    fb.write((char*)&nv, sizeof(nv));

    fb.close();

    // Разделение на простые и составные
    std::ifstream rb("num.bin", std::ios::binary);

    std::ofstream pf("prime.bin", std::ios::binary);
    std::ofstream cf("comp.bin", std::ios::binary);

    while (rb.read((char*)&x, sizeof(x)))
    {
        if (pr(x))
        {
            pf.write((char*)&x, sizeof(x));
        }
        else
        {
            cf.write((char*)&x, sizeof(x));
        }
    }

    rb.close();
    pf.close();
    cf.close();

    // Вывод простых чисел
    std::ifstream p1("prime.bin", std::ios::binary);

    std::cout << "\nПростые числа:\n";
    vw(p1);

    p1.close();

    // Вывод составных чисел
    std::ifstream p2("comp.bin", std::ios::binary);

    std::cout << "\nСоставные числа:\n";
    vw(p2);

    p2.close();

    return 0;
}