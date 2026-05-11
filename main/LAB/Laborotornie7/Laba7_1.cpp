#include <iostream>

class Pr
{
private:
    double dl;
    double sh;

public:

    // Конструктор по умолчанию
    Pr()
    {
        dl = 1;
        sh = 1;
    }

    // Конструктор с параметрами
    Pr(double d, double s)
    {
        if (d > 0 && s > 0)
        {
            dl = d;
            sh = s;
        }
        else
        {
            dl = 1;
            sh = 1;
        }
    }

    // Конструктор для квадрата
    Pr(double a)
    {
        if (a > 0)
        {
            dl = a;
            sh = a;
        }
        else
        {
            dl = 1;
            sh = 1;
        }
    }

    // Деструктор
    ~Pr()
    {
        std::cout << "Сработал деструктор\n";
    }

    // Площадь
    double pl()
    {
        return dl * sh;
    }

    // Периметр
    double pr()
    {
        return 2 * (dl + sh);
    }

    // Вывод данных
    void vw()
    {
        std::cout << "Длина: " << dl << "\n";
        std::cout << "Ширина: " << sh << "\n";
        std::cout << "Площадь: " << pl() << "\n";
        std::cout << "Периметр: " << pr() << "\n\n";
    }
};

int main()
{
    // Объект по умолчанию
    Pr a;

    // Объект с параметрами
    Pr b(5, 3);

    // Квадрат
    Pr c(4);

    std::cout << "Прямоугольник 1:\n";
    a.vw();

    std::cout << "Прямоугольник 2:\n";
    b.vw();

    std::cout << "Квадрат:\n";
    c.vw();

    return 0;
}