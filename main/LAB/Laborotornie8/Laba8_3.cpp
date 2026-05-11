#include <iostream>
#include <cmath>

class Dr
{
private:
    int cl;
    int ch;
    int zn;

    // Сокращение дроби
    void sc()
    {
        int a = std::abs(ch);
        int b = std::abs(zn);

        while (b != 0)
        {
            int t = b;
            b = a % b;
            a = t;
        }

        ch /= a;
        zn /= a;
    }

    // Перевод в неправильную дробь
    int fc() const
    {
        return cl * zn + ch;
    }

public:

    Dr(int c, int n, int z)
    {
        cl = c;
        ch = n;

        if (z == 0)
        {
            zn = 1;
        }
        else
        {
            zn = z;
        }

        sc();
    }

    // Сложение
    Dr operator+(Dr d)
    {
        int a = fc();
        int b = d.fc();

        int c = a * d.zn + b * zn;
        int z = zn * d.zn;

        return Dr(c / z, c % z, z);
    }

    // Вычитание
    Dr operator-(Dr d)
    {
        int a = fc();
        int b = d.fc();

        int c = a * d.zn - b * zn;
        int z = zn * d.zn;

        return Dr(c / z, c % z, z);
    }

    // Умножение
    Dr operator*(Dr d)
    {
        int c = fc() * d.fc();
        int z = zn * d.zn;

        return Dr(c / z, c % z, z);
    }

    // Деление
    Dr operator/(Dr d)
    {
        int b = d.fc();

        if (b == 0)
        {
            std::cout << "Деление на 0 невозможно\n";

            return Dr(0, 0, 1);
        }

        int c = fc() * d.zn;
        int z = zn * b;

        return Dr(c / z, c % z, z);
    }

    // Дружественная функция
    friend double dc(Dr d);

    void vw()
    {
        std::cout << cl << " " << ch << "/" << zn;
    }
};

// Перевод в десятичную дробь
double dc(Dr d)
{
    return d.cl + (double)d.ch / d.zn;
}

int main()
{
    Dr a(1, 1, 2);
    Dr b(2, 3, 4);

    std::cout << "Дробь 1: ";
    a.vw();

    std::cout << "\nДесятичная: " << dc(a);

    std::cout << "\n\nДробь 2: ";
    b.vw();

    std::cout << "\nДесятичная: " << dc(b);

    Dr s = a + b;

    std::cout << "\n\nСложение:\n";
    s.vw();

    std::cout << "\nДесятичная: " << dc(s);

    Dr v = a - b;

    std::cout << "\n\nВычитание:\n";
    v.vw();

    std::cout << "\nДесятичная: " << dc(v);

    Dr u = a * b;

    std::cout << "\n\nУмножение:\n";
    u.vw();

    std::cout << "\nДесятичная: " << dc(u);

    Dr d = a / b;

    std::cout << "\n\nДеление:\n";
    d.vw();

    std::cout << "\nДесятичная: " << dc(d);

    return 0;
}