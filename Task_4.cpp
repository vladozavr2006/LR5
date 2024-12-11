#include <iostream>
void zeroes(double **massive, int n, int k)
{
    int l = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < k; ++j)
        {
            if (massive[i][j] == 0)
            {
                ++l;
            }
        }
    }
    std::cout << "Количество элементов равных нулю: " << l;
    if (l != 0)
    {
        std::cout << '\n' << "Их индексы: " << '\n';
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < k; ++j)
        {
            if (massive[i][j] == 0)
            {
                std::cout << "[" << i << "]" << "[" << j << "]" << '\n';
            }
        }
    }

}
int main()
{
    std::cout << "Вариант 6. Выполнил Борисевич Владислав." << '\n';
    int n, k;
    std::cout << "Введите количство строк: ";
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
    std::cout << "Введите количество столбцов: ";
    std::cin >> k;
    if (std::cin.fail() || std::cin.peek() != '\n')
    {
        do
        {
            std::cin.clear();
            std::cout << "Введите число: ";
            std::cin.ignore(32767, '\n');
            std::cin >> k;
        } while (std::cin.fail() || std::cin.peek() != '\n');
    }
    double **massive = new double*[n];
    for (int i = 0; i < n; ++i)
    {
        massive[i] = new double[k];  
    } 
    std::cout << "Введите значения элементов массива: " << '\n';
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < k; ++j)
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
    zeroes(massive, n, k);
    std::cout << '\n';
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < k; ++j)
        {
            std::cout << massive[i][j] << " ";
        }
        std::cout << '\n';
    }
    std::cout << '\n';
    double **massive2 = new double*[n];
    for (int i = 0; i < n; ++i)
    {
        massive2[i] = new double[k];
    }
    int a = n - 1;
    int b = k - 1;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < k; ++j)
        {
            massive2[i][j] = massive[a][b];
            --b;
        }
        b = k - 1;
        --a;
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < k; ++j)
        {
            std::cout << massive2[i][j] << " ";
        }
        std::cout << '\n';
    }
    for (int i = 0; i < n; ++i)
    {
        delete[] massive[i];
        delete[] massive2[i];
    }
    delete[] massive;
    delete[] massive2;
    return 0;
}