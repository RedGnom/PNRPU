#include <iostream>
using namespace std;

int f(int n) {
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return f(n - 2) + f(n - 1);
}

int main() {
    setlocale(LC_ALL, "RU");
    cout << "Число Фибоначчи " << f(12);
    return 0;
}
