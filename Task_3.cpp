#include <iostream>
int main()
{
    std::cout << "Вариант 6. Выполнил Борисевич Владислав." << '\n';
    int n, k;
    k = 0;
    std::cout << "n = ";
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
    int **massive = new int *[n];
    for (int i = 0; i < n; ++i)
    {
        massive[i] = new int[n];
    }
    std::cout << "Введите значения элементов массива:" << '\n';
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
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
    int j = 0;
    for (int i = 0; i < n; ++i)
    {
        if (massive[i][j] % 2 == 0)
        {
            ++k;
        }
        ++j;
    }
    int *diag = new int[k];
    std::cout << "Значения элементов нового массива: " << '\n';
    j = 0;    
    int h = 0;    
    for (int i = 0; i < n; ++i)
    {
        if (massive[i][j] % 2 == 0)
        {
            diag[h] = massive[i][j];
            std::cout << h + 1 << ". " << diag[h] << '\n';
            ++h;
        }
        ++j;
    }
    if (h == 0)
    {
        std::cout << "Нет таких элементов";
        for (int i = 0; i < n; ++i)
        {
            delete[] massive[i];
        }
        delete[] massive;
        delete[] diag;
        return 0;
    }
    int res = diag[0];
    for (int h = 1; h < k; ++h)
    {
        res = res * diag[h];
    }
    std::cout << "Произведение: " << res;
    for (int i = 0; i < n; ++i)
    {
        delete[] massive[i];
    }
    delete[] massive;
    delete[] diag;
    return 0;
}