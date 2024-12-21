#include <iostream>
#include <cstring>
using namespace std;

const int N = 35;
struct Matrix {
    int m[N * 2][N * 2];
};

int n, k, m;

Matrix mul(Matrix &a, Matrix &b) {
    Matrix temp;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            temp.m[i][j] = 0;
            for (int k = 1; k <= n; k++) {
                temp.m[i][j] += (a.m[i][k] * b.m[k][j] % m);
                temp.m[i][j] %= m;
            }
        }
    return temp;
}

Matrix quickExp(Matrix &a, int x) {
    Matrix mat;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            mat.m[i][j] = (i == j ? 1 : 0);
        }
    for (; x; x >>= 1) {
        if (x & 1) {
            mat = mul(a, mat);
        }
        a = mul(a, a);
    }
    return mat;
}


int main() {
    cin.tie(0);
    cin.sync_with_stdio(false);

    cin >> n >> k >> m;

    Matrix mat1, mat2;
    memset(mat1.m, 0, sizeof(mat1.m));
    memset(mat2.m, 0, sizeof(mat2.m));
    for (int i = 1; i <= n; i++) {
        mat2.m[i][i] = mat2.m[i + n][i] = 1;
    }
    for (int i = 1; i <= n; i++)
        for (int j = n + 1; j <= 2 * n; j++) {
            cin >> mat1.m[i][j];
            mat2.m[n + i][j] = mat1.m[i][j];
        }
    n *= 2;
    mat2 = quickExp(mat2, k);
    mat1 = mul(mat1, mat2);
    for (int i = 1; i <= n / 2; i++)
        for (int j = 1; j <= n / 2; j++) {
            cout << mat1.m[i][j];
            if (j != n / 2) cout << " ";
            else cout << endl;
        }
    return 0;
}
