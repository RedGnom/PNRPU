#include < iostream>
#include <ctime>

using namespace std;
const int n = 10;
const int row = 4;

void d(int arr[][row], int& n) {
	int k = 0;
	for (int i = 0; i < n; i += 2) {
		for (int j = 0; j < row; j++) {
			arr[k][j] = arr[i][j];
		}
		k++;
	}
	if (n % 2 != 0) {
		for (int j = 0; j < row; j++) {
			arr[k][j] = arr[n - 1][j];
		}
		k++;
		n = k - 1;
	}
	else {
		n = k;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < row; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

void d(int b[], int& n) {
	int k = 0;
	for (int i = 0; i < n - 1; i++) {
		if (b[i] == 0) {
			int index = i;
			b[i] = b[i + 1];
			while (b[i] != 0) {
				k++;
				i++;
			}
			k++;
			i++;
			int l = n - i;
			for (int j = 0; j < l; j++) {
				b[index++] = b[i];
				i++;

			}
		}
	}
	n -= k;
	for (int i = 0; i < n; i++) {
		cout << b[i] << " ";
	}
}
int main() {
	int fake = n;
	int& nt = fake;
	int a[n][row] = { {1,1,1,1},{2,2,2,2},{3,3,3,3},{4,4,4,4}, {5,5,5,5}, {6,6,6,6}, {7,7,7,7},{8,8,8,8} };
	int b[n] = { 1,2,0,4,5,6,0,8, 9 , 10};
	d(b, nt);
}