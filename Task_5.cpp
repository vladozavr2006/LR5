#include <iostream>
double func(int* massive, int n)
{
    double sum = 0;
    for (int i = 0; i < n; ++i)
    {
        sum = sum + massive[i];
    } 
    return sum / n;
}
int main()
{
    char q;
    do{
    std::cout << "Вариант 6. Выполнил Борисевич Владислав." << '\n';
    int a, b;
    std::cout << "Введите количество строк массива: ";
    std::cin >> a;
    if (std::cin.fail() || std::cin.peek() != '\n')
    {
        do
        {
            std::cin.clear();
            std::cout << "Введите число: ";
            std::cin.ignore(32767, '\n');
            std::cin >> a;
        } while (std::cin.fail() || std::cin.peek() != '\n');
    }
    std::cout << "Введите количество столбцов массива: ";
    std::cin >> b;
    if (std::cin.fail() || std::cin.peek() != '\n')
    {
        do
        {
            std::cin.clear();
            std::cout << "Введите число: ";
            std::cin.ignore(32767, '\n');
            std::cin >> b;
        } while (std::cin.fail() || std::cin.peek() != '\n');
    }
    int **massive = new int *[a];
    for (int i = 0; i < a; ++i)
    {
        massive[i] = new int[b];
    }
    std::cout << "Введите значения элементов массива: " << '\n';
    for (int i = 0; i < a; ++i)
    {
        for (int j = 0; j < b; ++j)
        {
            std::cout << "[" << i << "][" << j << "]: ";
            std::cin >> massive[i][j];
            if (std::cin.fail() || std::cin.peek() != '\n')
            {
                do
                {
                    std::cin.clear();
                    std::cout << "Введите число: ";
                    std::cin.ignore(32767, '\n');
                    std::cin >> massive[i][j];
                } while (std::cin.fail() || std::cin.peek() != '\n');
            }
        }
    }
    int n = 0;
    for (int i = 0; i < a; ++i)
    {
        for (int j = 0; j < b; ++(++j))
        {
            if (massive[i][j] % 2 == 1)
            {
                ++n;
            }
        }
    }
    for (int i = 0; i < a; ++i)
    {
        for (int j = 0; j < b; ++j)
        {
            std::cout << massive[i][j] << " ";
        }
        std::cout << '\n';
    }
    if (n == 0)
    {
        std::cout << "Нет таких элементов";
    }
    else
    {   
        int *massive2 = new int[n];
        int l = 0;
        for (int i = 0; i < a; ++i)
        {
            for (int j = 0; j < b; ++(++j))
            {
                if (massive[i][j] % 2 == 1)
                {
                    massive2[l] = massive[i][j];
                    ++l;
                }
            }
        }
        std::cout << "Среднее арифметическое равно: " << func(massive2, n);
        delete[] massive2;
    }
    for (int i = 0; i < a; ++i)
    {
        delete[] massive[i];
    }
    delete[] massive;
    std::cout << '\n' << "Введите '0', если хотите завершить программу;" << '\n' << "Введите '1', если хотите продолжить: ";
    std::cin >> q;
    if (q == '0')
    {
        return 0;
    }
    } while (1 ==1);
    return 0;
}