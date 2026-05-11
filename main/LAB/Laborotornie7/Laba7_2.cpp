#include <iostream>
#include <cstdlib>

class Dr
{
private:
    int ch;
    int zn;

    // НОД
    int nd(int a, int b)
    {
        while (b != 0)
        {
            int t = b;
            b = a % b;
            a = t;
        }

        return std::abs(a);
    }

    // Сокращение дроби
    void sc()
    {
        int d = nd(ch, zn);

        ch /= d;
        zn /= d;

        // Знак переносится в числитель
        if (zn < 0)
        {
            ch = -ch;
            zn = -zn;
        }
    }

public:

    // Конструктор
    Dr(int c, int z)
    {
        if (z == 0)
        {
            std::cout << "Знаменатель не может быть 0\n";

            ch = 0;
            zn = 1;
        }
        else
        {
            ch = c;
            zn = z;

            sc();
        }
    }

    // Сложение
    Dr sl(Dr d)
    {
        int c = ch * d.zn + d.ch * zn;
        int z = zn * d.zn;

        return Dr(c, z);
    }

    // Вычитание
    Dr vt(Dr d)
    {
        int c = ch * d.zn - d.ch * zn;
        int z = zn * d.zn;

        return Dr(c, z);
    }

    // Умножение
    Dr um(Dr d)
    {
        int c = ch * d.ch;
        int z = zn * d.zn;

        return Dr(c, z);
    }

    // Деление
    Dr dl(Dr d)
    {
        if (d.ch == 0)
        {
            std::cout << "Деление на 0 невозможно\n";

            return Dr(0, 1);
        }

        int c = ch * d.zn;
        int z = zn * d.ch;

        return Dr(c, z);
    }

    // Проверка равенства
    bool rv(Dr d)
    {
        return ch == d.ch && zn == d.zn;
    }

    // Вывод дроби
    void vw()
    {
        std::cout << ch << "/" << zn;
    }
};

int main()
{
    Dr a(2, 4);
    Dr b(-3, 5);

    std::cout << "Дробь 1: ";
    a.vw();

    std::cout << "\nДробь 2: ";
    b.vw();

    // Сложение
    Dr s = a.sl(b);

    std::cout << "\n\nСложение: ";
    s.vw();

    // Вычитание
    Dr v = a.vt(b);

    std::cout << "\nВычитание: ";
    v.vw();

    // Умножение
    Dr u = a.um(b);

    std::cout << "\nУмножение: ";
    u.vw();

    // Деление
    Dr d = a.dl(b);

    std::cout << "\nДеление: ";
    d.vw();

    // Проверка равенства
    if (a.rv(b))
    {
        std::cout << "\n\nДроби равны\n";
    }
    else
    {
        std::cout << "\n\nДроби не равны\n";
    }

    return 0;
}