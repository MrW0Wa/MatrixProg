#include <iostream>
#include <vector>


using namespace std;



vector<vector<int>> Input(int r, int c) {
    vector<vector<int>> matrix(r, vector<int>(c));

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cin >> matrix[i][j];
        }
    }
    return matrix;
}

void Show(vector<vector<int>> v, int r, int c) {
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

vector<vector<int>> Plus(vector<vector<int>> m1, vector<vector<int>> m2, int r, int c) {
    vector<vector<int>> result = m1;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            result[i][j] = m1[i][j] + m2[i][j];
        }
    }
    return result;
}

vector<vector<int>> Mult(vector<vector<int>> m1, vector<vector<int>> m2, int r, int c) {
    vector<vector<int>> result(r, vector<int>(c));
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            for (int n = 0; n < r; ++n) {
                result[i][j] += m1[i][n] * m2[n][j];
            }
        }
    }
    return result;
}

vector<vector<int>> Stepen(vector<vector<int>> v, int r, int c, int n) {
    vector<vector<int>> result = Mult(v, v, r, c);
    //for (int i = 0; i < n-1; ++i) {
    //    result = Mult(result, v, r, c);
    //}
    int step = 2;
    while (step*2 < n) {
        step += step;
        result = Mult(result, result, r, c);
    }
    while (step != n) {
        step++;
        result = Mult(result, v, r, c);
    }
    /*}
    if (n % 2 == 0) {
        for (int i = 0; i < n/2 - 1; ++i) {
            result = Mult(result, v, r, c);
        }
        result = Mult(result, result, r, c);
    }
    else {
        for (int i = 0; i < n / 2 - 1; ++i) {
            result = Mult(result, v, r, c);
        }
        result = Mult(result, result, r, c);
        result = Mult(result, v, r, c);
    }*/
    return result;
}

int main() {

    setlocale(LC_ALL, "Russian");
    int r1, c1, r2, c2;

    cout << "количество строк и столбцов первой матрицы: ";
    cin >> r1 >> c1;

    cout << "количество строк и столбцов второй матрицы: ";
    cin >> r2 >> c2;

    vector<vector<int>> matrix1(r1, vector<int>(c1));
    vector<vector<int>> matrix2(r2, vector<int>(c2));
    vector<vector<int>> mult(r2, vector<int>(c2));
    vector<vector<int>> stepen(r1, vector<int>(c1));

    cout << "Введите элементы первой матрицы:" << endl;
    matrix1 = Input(r1, c1);

    //cout << "Введите элементы второй матрицы:" << endl;
    //matrix2 = Input(r2, c2);


    cout << "Первая матрица:" << endl;
    Show(matrix1, r1, c1);

    //cout << "Вторая матрица:" << endl;
    //Show(matrix2, r1, c1);

    //mult = Mult(matrix1, matrix2, r1, c1);

    //cout << "умножение" << endl;
    //Show(mult, r1, c1);

    cout << "введите степень для матрицы:" << endl;
    int n;
    cin >> n;
    stepen = Stepen(matrix1, c1, r1, n);
    Show(stepen, r1, c1);
    
}


