#include <iostream>

int main() {

	using namespace std;

	int m = 0;
	int n = 0;
	cout << "введите размеры матрицы :\n";
	cin >> n >> m;
	int mas[100][100];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> mas[i][j];
		}
	}


}