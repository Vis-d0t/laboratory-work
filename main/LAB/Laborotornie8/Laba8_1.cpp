#include <iostream>

class Figure
{
protected:
    std::string nm;

public:

    Figure(std::string n)
    {
        nm = n;
    }

    virtual double pl()
    {
        return 0;
    }

    virtual double pr()
    {
        return 0;
    }

    void vw()
    {
        std::cout << "\nФигура: " << nm << "\n";
        std::cout << "Площадь: " << pl() << "\n";
        std::cout << "Периметр: " << pr() << "\n";
    }
};

class Circle : public Figure
{
private:
    double r;

public:

    Circle(double x) : Figure("Круг")
    {
        r = x;
    }

    double pl() override
    {
        return 3.14 * r * r;
    }

    double pr() override
    {
        return 2 * 3.14 * r;
    }
};

class Rectangle : public Figure
{
private:
    double a;
    double b;

public:

    Rectangle(double x, double y) : Figure("Прямоугольник")
    {
        a = x;
        b = y;
    }

    double pl() override
    {
        return a * b;
    }

    double pr() override
    {
        return 2 * (a + b);
    }
};

class Triangle : public Figure
{
private:
    double a;
    double b;
    double c;

public:

    Triangle(double x, double y, double z)
        : Figure("Треугольник")
    {
        a = x;
        b = y;
        c = z;
    }

    double pr() override
    {
        return a + b + c;
    }

    double pl() override
    {
        double p = pr() / 2;

        return sqrt(p * (p - a) * (p - b) * (p - c));
    }
};

int main()
{
    Circle c(5);
    Rectangle r(4, 6);
    Triangle t(3, 4, 5);

    c.vw();
    r.vw();
    t.vw();

    return 0;
}