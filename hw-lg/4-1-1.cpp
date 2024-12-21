//
// Created by Yasushin Ri on 2024/12/19.
//

#include <iostream>
#include <vector>
using namespace std;

void Print(const vector<vector<int> > &a) {
    int n = a.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << a[i][j] << (j == n - 1 ? "" : " ");
        }
        cout << endl;
    }
}

vector<vector<int> > matrixMul(const vector<vector<int> > &a, const vector<vector<int> > &b, int m) {
    int n = a.size();
    vector<vector<int> > result(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                result[i][j] += a[i][k] * b[k][j];
                result[i][j] %= m;
            }
        }
    }
    return result;
}

vector<vector<int> > matrixPow(const vector<vector<int> > &a, long long k, int m) {
    if (k == 1) {
        return a;
    } else if (k == 2) {
        return matrixMul(a, a, m);
    }


    return matrixMul(matrixPow(a, k / 2, m), matrixPow(a, k - k / 2, m), m);
}

vector<vector<int> > addMatrix(const vector<vector<int> > &a, const vector<vector<int> > &b, const int m) {
    const int n = a.size();
    vector<vector<int> > result(n, vector<int>(n, 0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            result[i][j] = a[i][j] + b[i][j];
            result[i][j] %= m;
        }
    }

    return result;
}

vector<vector<int> > matrixSum(const vector<vector<int> > &a, long long k, int m) {
    if (k == 1) {
        return a;
    }
    vector<vector<int> > half = matrixSum(a, k / 2, m);

    // Print( matrixPow(a, k / 2, m));
    // Print(matrixMul(half, matrixPow(a, k / 2, m), m));
    vector<vector<int> > result = addMatrix(half, matrixMul(half, matrixPow(a, k / 2, m), m), m);
    if (k % 2 == 1) {
        vector<vector<int> > add = matrixPow(a, k, m);
        int n = result.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                result[i][j] += add[i][j];
                result[i][j] %= m;
            }
        }
    }
    return result;
}

int main() {
    int n, m;
    long long k;
    cin >> n >> k >> m;
    vector<vector<int> > matrix(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }
    vector<vector<int> > sumMatrix = matrixSum(matrix, k, m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << sumMatrix[i][j] << (j == n - 1 ? "" : " ");
        }
        cout << endl;
    }
    return 0;
}
