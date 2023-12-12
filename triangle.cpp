#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");
    int n, z = 1, p;
    cout << "Введите число больше 3 и нечетное ";
    cin >> n;
    while ((n % 2 == 0) || (3 >= n)) {
        cout << "Введите еще раз ";
        cin >> n;
    }
    p = (n - 1) / 2;
    cout << endl;
    for (int i = 1; i <= (n + 1) / 2; i++) {
        for (int j = 1; j <= p; j++)
        {
            cout << " ";
        }
        p--;
        for (int j = 1; j <= z; j++) {
            cout << "*";
        }
        z = z + 2;
        cout << endl;
    }
    return 0;
}