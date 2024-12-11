#include <iostream>
#include <cmath>
double func(double* massive, int a)
{
    if (a == 0)
    {
        return sin(massive[a]) * cos(massive[a]);
    }
    else
    {
        return sin(massive[a]) * cos(massive[a]) + func(massive, --a);
    }
}
int main()
{
    std::cout << "Вариант 6. Выполнил Борисевич Владислав." << '\n';
    int n;
    std::cout << "Введите размер массива: ";
    std::cin >> n;
    if (std::cin.fail() || std::cin.peek() != '\n')
    {
        do
        {
            std::cin.clear();
            std::cout << "Введите число: ";
            std::cin.ignore(32767, '\n');
            std::cin >> n;
        } while (std::cin.fail() || std::cin.peek() != '\n');
    }
    double* massive = new double[n];
    std::cout << "Введите элементы массива: " << '\n';
    for (int i = 0; i < n; ++i)
    {
        std::cout << i + 1 << ". ";
        std::cin >> massive[i];
        if (std::cin.fail() || std::cin.peek() != '\n')
            {
                do
                {
                    std::cin.clear();
                    std::cout << "Введите число: ";
                    std::cin.ignore(32767, '\n');
                    std::cin >> massive[i];
                } while (std::cin.fail() || std::cin.peek() != '\n');
            }
    }
    --n;
    std::cout << func(massive, n);
    return 0;
}