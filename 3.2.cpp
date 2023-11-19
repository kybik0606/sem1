/*Задана целочисленная матрица порядка n * n. Для тестирования программы 
предусмотреть возможность задавать элементы массива различным образом: 
при описании с инициализацией, присвоением значений (в том числе случайных), 
или вводом необходимых значений. Выбор способа инициализации массива сделать через меню с использованием перечисления (enum).
Вариант 5:
Cреди столбцов заданной матрицы, содержащих только такие элементы, 
которые по модулю не больше заданного натурального N, найти столбец с минимальным произведением элементов. 
Найти сумму элементов тех строк, в которых находится наибольший элемент матрицы.*/

#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main()
{
	setlocale(LC_ALL, "RU");
	srand(time(NULL));

	int count_N = 0;
	int modul = 0;
	int comp = 1;
	double min = DBL_MAX;
	int k = 0, k1 = 0;
	int summa = 0, summa1 = 0;

	enum Init { descr_w_init, random_value, entering_required_values };
	cout << "Виды инициализации\n";
	cout << descr_w_init << " - Описание с инициализацией\n";
	cout << random_value << " - Присвоcение значений (в том числе случайных)\n";
	cout << entering_required_values << " - Ввод необходимых значений\n\n";

	Init choice = descr_w_init;
	cout << "Выберите вид инициализации: ";
	int type = 0;
	cin >> type;
	choice = Init(type);

	switch (choice)
	{
	case descr_w_init:
	{
		const int I = 5, J = 5, N = 25;
		int a[I][J] = { { 1 , 10, 11, 20, 21 },
						{ 2 , 9 , 12, 19, 22 },
						{ 3 , 25, 13, 18, 23 },
						{ 4 , 7 , 14, 17, 24 },
						{ 5 , 6 , 25, 16, 25 }
		};
		int max = a[0][0];
		cout << "матрица:" << endl;
		for (int i = 0; i < I; i++)
		{
			for (int j = 0; j < J; j++)
				cout << setw(3) << a[i][j];
			cout << endl;
		}

		for (int j = 0; j < J; j++)
		{
			count_N = 0;
			comp = 1;
			for (int i = 0; i < I; i++)
			{
				modul = abs(a[i][j]);
				if (modul <= N)
					count_N++;
				if (count_N == I)
				{
					for (i = 0; i < I; i++)
						comp *= a[i][j];
					if (comp < min)
						min = comp;
				}
			}
		}
		if (min == DBL_MAX)
		{
			cout << "Таких столбов нет" << endl;
		}
		else
			cout << "столбец с минимальным произведением элементов: " << min << endl;

		for (int i = 0; i < I; i++)
		{
			for (int j = 0; j < J; j++)
			{
				if (max < a[i][j])
				{
					max = a[i][j];
				}
			}
		}
		cout << "максимальное значение: " << max << endl;
		int d = 0;
		for (int i = 0; i < I; i++)
		{
			d = 0;
			for (int j = 0; j < J; j++)
			{
				if (a[i][j] == max)
				{
					if(d < 1)
					{ 
						for(int j = 0; j < J; j++)
						{
							summa += a[i][j];
							d++;
						}
					}

				}
			}
		}
		cout << "сумма элементов строк: " << summa;
		break;
	}
	case random_value:
	{
		const int I = 5, J = 5, N = 25;
		int a[I][J];
		for (int i = 0; i < I; i++)
		{
			for (int j = 0; j < J; j++)
			{
				a[i][j] = rand() % 30;
			}
		}
		int max = a[0][0];
		for (int i = 0; i < I; i++)
		{
			for (int j = 0; j < J; j++)
				cout << setw(3) << a[i][j];
			cout << endl;
		}

		for (int j = 0; j < J; j++)
		{
			count_N = 0;
			comp = 1;
			for (int i = 0; i < I; i++)
			{
				modul = abs(a[i][j]);
				if (modul <= N)
					count_N++;
				if (count_N == I)
				{
					for (i = 0; i < I; i++)
						comp *= a[i][j];
					if (comp < min)
						min = comp;
				}
			}
		}
		if (min == DBL_MAX)
		{
			cout << "Таких столбов нет" << endl;
		}
		else
			cout << "столбец с минимальным произведением элементов: " << min << endl;

		for (int i = 0; i < I; i++)
		{
			for (int j = 0; j < J; j++)
			{
				if (max < a[i][j])
				{
					max = a[i][j];
				}
			}
		}
		cout << "максимальное значение: " << max << endl;
		int d = 0;
		for (int i = 0; i < I; i++)
		{
			d = 0;
			for (int j = 0; j < J; j++)
			{
				if (a[i][j] == max)
				{
					if (d < 1)
					{
						for (int j = 0; j < J; j++)
						{
							summa += a[i][j];
							d++;
						}
					}

				}
			}
		}
		cout << "сумма элементов строк: " << summa;
		break;
	}
	case entering_required_values:
	{
		const int I = 3, J = 3, N = 25;
		int a[I][J];
		for (int i = 0; i < I; i++)
		{
			for (int j = 0; j < J; j++)
			{
				cout << "Element " << i << " " << j << ": ";
				cin >> a[i][j]; cout << endl;
			}
		}
		int max = a[0][0];
		for (int i = 0; i < I; i++)
		{
			for (int j = 0; j < J; j++)
				cout << setw(3) << a[i][j];
			cout << endl;
		}

		for (int j = 0; j < J; j++)
		{
			count_N = 0;
			comp = 1;
			for (int i = 0; i < I; i++)
			{
				modul = abs(a[i][j]);
				if (modul <= N)
					count_N++;
				if (count_N == I)
				{
					for (i = 0; i < I; i++)
						comp *= a[i][j];
					if (comp < min)
						min = comp;
				}
			}
		}
		if (min == DBL_MAX)
		{
			cout << "Таких столбов нет" << endl;
		}
		else
			cout << "столбец с минимальным произведением элементов: " << min << endl;

		for (int i = 0; i < I; i++)
		{
			for (int j = 0; j < J; j++)
			{
				if (max < a[i][j])
				{
					max = a[i][j];
				}
			}
		}
		cout << "максимальное значение: " << max << endl;
		int d = 0;
		for (int i = 0; i < I; i++)
		{
			d = 0;
			for (int j = 0; j < J; j++)
			{
				if (a[i][j] == max)
				{
					if (d < 1)
					{
						for (int j = 0; j < J; j++)
						{
							summa += a[i][j];
							d++;
						}
					}

				}
			}
		}
		cout << "сумма элементов строк: " << summa;
		break;
	}
	default:
		cout << "Введите число от 0 до 2\n";
		break;
	}
	return 0;
}
	

