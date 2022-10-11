#include <iostream>

static class Math
{
public:
    static double Sin(double x)
    {
        return sin(x);
    }
};


class Money
{
    static float course;
    const int MaxKops = 100;
    int rub;
    int kop;

    void Service()
    {
        rub += kop / MaxKops;
        kop = kop % MaxKops;
    }
public:
    Money(int rub, int kop) : rub{ rub }, kop{ kop } { Service(); }
    Money() : Money(0, 0) {}

    Money ToDollar()
    {
        int summa = (rub * 100 + kop) * course;
        Money result(0, summa);
        return result;
    }

    static void SetCourse(float c)
    {
        course = c;
    }
    static float GetCourse()
    {
        return course;
    }
};

float Money::course = 60;

int main()
{
    Money m1(10, 50);
    Money m2(20, 25);

    std::cout << Money::GetCourse() << "\n";

    Money::SetCourse(70);

    std::cout << Money::GetCourse() << "\n";

    Math::Sin(10);
}
