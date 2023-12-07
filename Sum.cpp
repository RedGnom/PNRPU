#include <iostream>
using namespace std;
int main()
{
    double s = 0;
    int n;
    int i = 1;
    double x;
    double u = 1;

    setlocale(LC_ALL, "ru");
    cout << "Введите количество элементов: " << endl;
    cin >> n;
    cout << "Введите x: " << endl;
    cin >> x;

    while (i <= n)
    {
        s += u;
        u = u * x / i;
        i ++;
    }
    cout << "Сумма элементов: " << s;
    return 0;
}
