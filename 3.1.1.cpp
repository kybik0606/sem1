/*3.1.1. Для тестирования программы предусмотреть возможность задавать 
элементы массива различным образом: при описании с инициализацией, присвоением значений (в том числе случайных), 
или вводом необходимых значений.
Вариант 5: Определите сумму элементов массива, расположенных до максимального 
значения.*/

#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");

    srand(time(NULL));
    int x, n, k = 0;
    int t = 0;
    int summa = 0;
    cout << "Введите способ задания массива:\n" << "1: описание с инициализацией\n" <<
    "2: присвоением значений (в том числе случайных)\n" << "3: ввод необходимых значений\n"
    << "Введите число от 1 до 3: ";
    cin >> x;
    switch(x)
    {    
        case 1:
        {
            int array[5] = { 1,2,3,4,5 };
            int max = array[0];
            for (int i = 0; i <= 5; i++)
            {
                if (array[i] > max)
                {
                    max = array[i];
                    k = i;
                }
            }
            for (int i = 0; i <= 5; i++)
            {
                if (array[i] == max) t++;
            }
            if (t > 1)
                cout << "В массиве не одно максимальное значение";
            else
            {
                for (int i = 0; i < k; i++)
                    summa += array[i];
                cout << "Сумма элементов массива, расположенных до максимального значения: " << summa;
            }
            break;
        }
        case 2:
        {
            int array[5]{};
            for (int i = 1; i <= 5; i++)
            {
                array[i-1] = rand() % (20 - 10 + 1) + 10;
            }

            int max = array[0];
            for (int i = 0; i <= 5; i++)
            {
                if (array[i] > max)
                {
                    max = array[i];
                    k = i;
                }
            }
            for (int i = 1; i <= 5; i++)
                cout << array[i-1] << " ";

            for (int i = 0; i <= 5; i++)
            {
                if (array[i] == max) t++;
            }
            if (t > 1)
                cout << "В массиве не одно максимальное значение";
            else
            {
                for (int i = 0; i < k; i++)
                    summa += array[i];
                cout << "Сумма элементов массива, расположенных до максимального значения: " << summa;
            }
            break;
        }
        case 3:
        {
            cout << "Введите количество элементов массива:";
            cin >> n;
            
            int* array = new int[n];
            for (int i = 0; i < n; i++) 
            {
                cout << "Element" << i << " ";
                cin >> array[i]; cout << endl;
            }

            int max = array[0];
            for (int i = 0; i <= n; i++)
            {
                if (array[i] > max)
                {
                    max = array[i];
                    k = i;
                }
            }
            for(int i = 0;i <= n; i++)
            {
                if (array[i] == max) t++;
            }
            if (t > 1)
                cout << "В массиве не одно максимальное значение";
            else
            {
                for (int i = 0; i < k; i++)
                    summa += array[i];
                cout << "Сумма элементов массива, расположенных до максимального значения: " << summa;
            }   
            break;
        }
    }
    return 0;
}


