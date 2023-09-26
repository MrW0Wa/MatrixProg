#include <iostream>
#include <vector>

using namespace std;

int main() {
    int r1, c1, r2, c2;

    cout << "количество строк и столбцов первой матрицы: ";
    cin >> r1 >> c1;

    cout << "количество строк и столбцов второй матрицы: ";
    cin >> r2 >> c2;

    vector<vector<int>> matrix1(r1, vector<int>(c1));
    vector<vector<int>> matrix2(r2, vector<int>(c2));
    vector<vector<int>> result(r2, vector<int>(c2));

    cout << "Введите элементы первой матрицы:" << endl;
    for (int i = 0; i < r1; ++i) {
        for (int j = 0; j < c1; ++j) {
            cin >> matrix1[i][j];
        }
    }

    cout << "Введите элементы второй матрицы:" << endl;
    for (int i = 0; i < r2; ++i) {
        for (int j = 0; j < c2; ++j) {
            cin >> matrix2[i][j];
        }
    }

    for (int i = 0; i < r1; ++i) {
        for (int j = 0; j < c1; ++j) {
            for (int n = 0; n < r1; ++n) {
                result[i][j] += matrix1[i][n] * matrix2[n][j];
            }
        }
    }

    cout << "Первая матрица:" << endl;
    for (int i = 0; i < r1; ++i) {
        for (int j = 0; j < c1; ++j) {
            cout << matrix1[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Вторая матрица:" << endl;
    for (int i = 0; i < r2; ++i) {
        for (int j = 0; j < c2; ++j) {
            cout << matrix2[i][j] << " ";
        }
        cout << endl;
    }

    cout << "умножение" << endl;
    for (int i = 0; i < r2; ++i) {
        for (int j = 0; j < c2; ++j) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    cin >> r2;
}
