#include <iostream>
using namespace std;
int main()
{
	int max;
	int s = 1;
	int a;
	int n;
	int j = 1;
	int i = 2;

	setlocale(LC_ALL, "Ru");
	cout << "Введите количество элементов: ";
	cin >> n;
	while (n <= 0) {
		cout << "Введите еще раз n" << endl;
		cin >> n;
	}
	cout << "Введите первый элемент последовательности: ";
	cin >> a;
	max = a;
	while (i <= n)
	{
		cout << "Введите следующий элемент: ";
		cin >> a;

		if (max < a)
		{
			max = a;
			j = i;
			s = 1;
		}

		else
		{
			if (max == a)
			{
				s += 1;
			}
		}

		i += 1;

	}

	cout << "Максимальное число в последовательности: " << max << endl;
	cout << "Количество: " << s << endl;
	cout << "Номер: " << j << endl;
	return 0;
}
