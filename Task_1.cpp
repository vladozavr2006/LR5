#include <iostream>
#include <cmath>
double vectorvector(double* massive1, double* massive2, size_t n)
{
	double sum = 0;
	for (int i = 0; i < n; ++i)
	{
		sum = sum + (massive1[i] * massive2[i]);
	}
	return sum;
}
int main()
{
    std::cout << "Вариант 6. Выполнил Борисевич Владислав." << '\n';
    double a, b;
    b = 0;
    double *x = new double[10];
    double *y = new double[10];
    std::cout << "Введите элементы первого вектора: " << '\n';
    for (int i = 0; i < 10; ++i)
    {
        std::cout << i + 1 << ". ";
        std::cin >> x[i];
        if (std::cin.fail() || std::cin.peek() != '\n')
            {
                do
                {
                    std::cin.clear();
                    std::cout << "Введите число: ";
                    std::cin.ignore(32767, '\n');
                    std::cin >> x[i];
                } while (std::cin.fail() || std::cin.peek() != '\n');
            }
    }
    std::cout << "Элементы второго массива равны: " << '\n';
    for (int i = 0; i < 10; ++i)
    {
        y[i] = 0.1 * tan(0.1 * i);
        std::cout << i + 1 << ". " << y[i] << '\n';
    }
    for (int i = 0; i < 10; ++i)
    {
        a = x[i] * y[i];
        b = a + b;
    }
    std::cout << "Произведение равно: " << b;
    delete[] x;
    delete[] y;
    return 0;
}