/*Даны натуральные числа n, m. Получить наименьшее общее кратное (НОК) 
чисел n, m. НОК(n, m) = n  m / НОД(n, m).*/

#include <iostream>
#include<math.h>
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    int a, b, nod;
    double nok;
    cout << "Введите первое число:";
    cin >> a;
    cout << "Введите второе число:";
    cin >> b;

    for (int i = 1; i <= a; i++) {
        if (a % i == 0 && b % i == 0)
            nod = i;
    }
    nok = a * b / nod;
    cout << "НОK: " << nok;
}
