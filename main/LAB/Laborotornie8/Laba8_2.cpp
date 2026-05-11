#include <iostream>
#include <fstream>

class Monitor
{
private:
    int dg;

public:

    Monitor()
    {
        dg = 15;
    }

    Monitor(int d)
    {
        dg = d;
    }

    int gd()
    {
        return dg;
    }

    void sd(int d)
    {
        dg = d;
    }

    void vw()
    {
        std::cout << "Монитор: " << dg << " дюймов\n";
    }
};

class Keyboard
{
private:
    std::string tp;

public:

    Keyboard()
    {
        tp = "Механическая";
    }

    Keyboard(std::string t)
    {
        tp = t;
    }

    void vw()
    {
        std::cout << "Клавиатура: " << tp << "\n";
    }
};

class Mouse
{
private:
    std::string tp;

public:

    Mouse()
    {
        tp = "Проводная";
    }

    Mouse(std::string t)
    {
        tp = t;
    }

    std::string gt()
    {
        return tp;
    }

    void st(std::string t)
    {
        tp = t;
    }

    void vw()
    {
        std::cout << "Мышь: " << tp << "\n";
    }
};

class Computer
{
private:
    std::string nm;
    Monitor mn;
    Keyboard kb;
    Mouse ms;

public:

    Computer()
    {
        nm = "ПК";
    }

    Computer(std::string n,
            Monitor m,
            Keyboard k,
            Mouse s)
    {
        nm = n;
        mn = m;
        kb = k;
        ms = s;
    }

    void ch()
    {
        // Замена монитора
        if (mn.gd() == 15)
        {
            mn.sd(17);
        }

        // Замена мыши
        if (ms.gt() == "Проводная")
        {
            ms.st("Беспроводная");
        }
    }

    void wr(std::ofstream& f, std::string dt)
    {
        f << "\nДата: " << dt << "\n";

        f << "Компьютер: " << nm << "\n";
        f << "Монитор: " << mn.gd() << "\n";
        f << "Мышь: " << ms.gt() << "\n";
    }

    void vw()
    {
        std::cout << "\nКомпьютер: " << nm << "\n";

        mn.vw();
        kb.vw();
        ms.vw();
    }
};

int main()
{
    const int n = 2;

    Computer pc[n] =
    {
        Computer("PC1",
                Monitor(15),
                Keyboard("Механическая"),
                Mouse("Проводная")),

        Computer("PC2",
                Monitor(17),
                Keyboard("Мембранная"),
                Mouse("Проводная"))
    };

    // Запись в файл
    std::ofstream f("pc.txt");

    for (int i = 0; i < n; i++)
    {
        pc[i].wr(f, "11.05.2026");
    }

    // Изменения
    for (int i = 0; i < n; i++)
    {
        pc[i].ch();
    }

    // Допись в файл
    for (int i = 0; i < n; i++)
    {
        pc[i].wr(f, "12.05.2026");
    }

    f.close();

    // Вывод
    for (int i = 0; i < n; i++)
    {
        pc[i].vw();
    }

    return 0;
}