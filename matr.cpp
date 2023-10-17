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

vector<vector<int>> Mult(vector<vector<int>> m1,int n, int r, int c) {
    vector<vector<int>> result = m1;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            result[i][j] = m1[i][j] * n;
        }
    }
    return result;
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

vector<vector<int>> Minus(vector<vector<int>> m1, vector<vector<int>> m2, int r, int c) {
    vector<vector<int>> result = m1;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            result[i][j] = m1[i][j] - m2[i][j];
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

    vector< vector<vector<int>>> mas;
    vector<int> st;

    int step = 2;
    while (step*2 < n) {
        mas.push_back(result);
        st.push_back(step);
        step += step;
        result = Mult(result, result, r, c);
    }

    if (step + 1 != n) {
        for (int i = st.size() - 1; i > 0; i--) {
            if (st[i] <= n - step) {
                step += st[i];
                result = Mult(result, mas[i], r, c);
            }
        }
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

vector<vector<int>> Smena(vector<vector<int>> v, int k, int s) {
        for (int i = 0; i < v.size(); i++) {
            swap(v[k - 1][i], v[s - 1][i]);
        }
    
        return v;
    }

vector<vector<int>> StrMult(vector<vector<int>> v, int k, int b) {
    for (int i = 0; i < v.size(); i++) {
        v[k - 1][i] *= b;
    }

    return v;
}

vector<vector<int>> StrPlus(vector<vector<int>> v, int k, int s, int b) {
    for (int i = 0; i < v.size(); i++) {
        v[k - 1][i] += v[s-1][i] * b;
    }

    return v;
}

//FLOAT

vector<vector<float>> InputF(int r, int c) {
    vector<vector<float>> matrix(r, vector<float>(c));
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cin >> matrix[i][j];
        }
    }
    return matrix;
}

vector<vector<float>> Smena(vector<vector<float>> v, int k, int s) {
    for (int i = 0; i < v.size(); i++) {
        swap(v[k - 1][i], v[s - 1][i]);
    }

    return v;
}

vector<vector<float>> StrMult(vector<vector<float>> v, int k, int b) {
    for (int i = 0; i < v.size(); i++) {
        v[k - 1][i] *= b;
    }

    return v;
}

vector<vector<float>> StrPlus(vector<vector<float>> v, int k, int s, float b) {
    for (int i = 0; i < v.size(); i++) {
        v[k - 1][i] += v[s - 1][i] * b;
    }

    return v;
}

void Show(vector<vector<float>> v, int r, int c) {
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}


vector<vector<float>> Inverse(vector<vector<float>> v) {
    vector<vector<float>> v1(v.size(), vector<float>(v.size()));
    for (int i = 0; i < v1.size(); i++) {
        for (int j = 0; j < v1.size(); j++) {
            if (i == j) v1[i][j] = 1;
            else v1[i][j] = 0;
        }
    }


    for (int j = 0 ; j < v.size()-1; j++){
        for (int i = j+1; i < v.size(); i++) {
            if (v[j][j] == 0) {

            }
            float cof = v[i][j] / v[j][j];
            v = StrPlus(v, i+1, j+1, -cof);
            v1 = StrPlus(v1, i+1, j+1, -cof);

        }
    }
    Show(v, v.size(), v.size());

    //for (int j = 1; j < v.size(); j++) {
    //    for (int i = j; i < v.size()-1; i++) {

    //        float cof = v[j-1][j] / v[i][i];
    //        v = StrPlus(v, i+1 , j+1, -cof);
    //        v1 = StrPlus(v1, i + 1, j + 1, -cof);

    //    }
    //}
    //Show(v, v.size(), v.size());
    return {};
}

//vector<vector<int>> Smena(vector<vector<int>> v, int k, int s) {
//    vector<vector<int>> v1(v.size(), vector<int>(v.size()));
//    for (int i = 0; i < v1.size(); i++) {
//        for (int j = 0; j < v1.size(); j++) {
//            if (i == j) v1[i][j] = 1;
//            else v1[i][j] = 0;
//        }
//    }
//    v1[k - 1][s - 1] = 1;
//    v1[s - 1][k - 1] = 1;
//    v1[k - 1][k - 1] = 0;
//    v1[s - 1][s - 1] = 0;
//
//    return Mult(v1, v, v.size(), v.size());
//}
//
//vector<vector<int>> StrMult(vector<vector<int>> v, int k, int b) {
//    vector<vector<int>> v1(v.size(), vector<int>(v.size()));
//    for (int i = 0; i < v1.size(); i++) {
//        for (int j = 0; j < v1.size(); j++) {
//            if (i == k - 1 && j == k - 1) v1[i][j] = b;
//            else if (i == j) v1[i][j] = 1;
//            else v1[i][j] = 0;
//        }
//    }
//
//    return Mult(v1, v, v.size(), v.size());
//}
//vector<vector<int>> StrPlus(vector<vector<int>> v, int k, int s, int b) {
//    vector<vector<int>> v1(v.size(), vector<int>(v.size()));
//    for (int i = 0; i < v1.size(); i++) {
//        for (int j = 0; j < v1.size(); j++) {
//            if (i == k - 1 && j == s - 1) v1[i][j] = b;
//            else if (i == j) v1[i][j] = 1;
//            else v1[i][j] = 0;
//        }
//    }
//
//    return Mult(v1, v, v.size(), v.size());
//}

void E(vector<int> v, int x1, int xn) {
    if (x1 == xn) {
        for (int i : v) {
            cout << i << ' ';
        }
        cout << endl;
        return;
    }
    for (int i = x1; i <= xn; i++) {
        swap(v[x1], v[i]);
        E(v, x1 + 1, xn);
        swap(v[x1], v[i]);
    }

}

int main() {

    setlocale(LC_ALL, "Russian");
    int r1, c1, r2, c2;

    //cout << "количество строк и столбцов первой матрицы: ";
    cin >> r1 >> c1;

    //cout << "количество строк и столбцов второй матрицы: ";
    //cin >> r2 >> c2;

    vector<vector<float>> matrix1(r1, vector<float>(c1));
    //vector<vector<int>> matrix2(r2, vector<int>(c2));
    //vector<vector<int>> mult(r2, vector<int>(c2));
    //vector<vector<int>> stepen(r1, vector<int>(c1));

    cout << "Введите элементы первой матрицы:" << endl;
    matrix1 = InputF(r1, c1);

    Inverse(matrix1);


    //cout << "Введите элементы второй матрицы:" << endl;
    //matrix2 = Input(r2, c2);


    //cout << "Первая матрица:" << endl;
    //Show(matrix1, r1, c1);

    //cout << "Вторая матрица:" << endl;
    //Show(matrix2, r1, c1);

    //mult = Mult(matrix1, matrix2, r1, c1);

    //cout << "умножение" << endl;
    //Show(mult, r1, c1);

    //cout << "введите степень для первой матрицы:" << endl;
    //int n;
    //cin >> n;
    //stepen = Stepen(matrix1, c1, r1, n);
    //Show(stepen, r1, c1);



    //int n;
    //cout << "Введите n: ";
    //cin >> n;
    //vector<int> v(n);
    //for (int i = 0; i < n; i++) {
    //    v[i] = i + 1;
    //}
    //E(v, 0, n-1);
    
}


