/*Вариант 5
Дана последовательность натуральных чисел длины n. Вычислить сумму тех из них, которые – простые числа.*/

#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");
    int n, s = 2, d = 0;
    cout << "Введите длину последовательности, n: ";
    cin >> n;
    if (n == 1 || n == 0) s = 0; else 
    {
        for (int i = 3; i <= n; i++)
        {
            d++;
            if (i % 2 != 0) 
            {
                for (int j = 2; j <= i; j++) 
                {
                    if (i % j == 0) d++; 
                }
                if (d == 2) s += i;
            } d = 0;
        }
    }cout << "Суммы простых чисел последовательности: " << s;
    return 0;
}