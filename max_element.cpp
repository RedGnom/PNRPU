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
	cout << "������� ���������� ���������: ";
	cin >> n;
	while (n <= 0) {
		cout << "������� ��� ��� n" << endl;
		cin >> n;
	}
	cout << "������� ������ ������� ������������������: ";
	cin >> a;
	max = a;
	while (i <= n)
	{
		cout << "������� ��������� �������: ";
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

	cout << "������������ ����� � ������������������: " << max << endl;
	cout << "����������: " << s << endl;
	cout << "�����: " << j << endl;
	return 0;
}
