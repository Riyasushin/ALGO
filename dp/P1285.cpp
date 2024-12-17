//
// Created by Yasushin Ri on 2024/12/8.
//
/// 基础动归
/// 复杂度分析
#include <iostream>
#include <cmath>
using namespace std;

long long sum = 0;
int  n, dp[800][800], temp, a[44];

double area(int i, int j, int k) {
    double p = double(sum) / 2;
    return sqrt(p * (p - i) * (p - j) * (p - k));
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }

    dp[0][0] = 1;
    //// 这里要到0！！
    for (int k = 0; k < n; ++k) {
        for (int j = sum / 2; j >= 0; --j) {
            for (int i = sum / 2; i >= 0; --i) {
                if (i - a[k] >= 0 && dp[i - a[k]][j]) dp[i][j] = 1;
                if (j - a[k] >= 0 && dp[i][j - a[k]]) dp[i][j] = 1;
            }
        }
    }

    double maxx = -1;
    for (int i = 1; i <= sum / 2; ++i) {
        for (int j = sum / 2; j > 0; --j) {
            if (dp[i][j] == 1 && i + j > sum - i - j) {
                maxx = max(maxx, area(i, j, sum - i - j));
            }
        }
    }

    cout << (maxx == -1 ? -1 : (long long) (maxx * 100)) << endl;

    return 0;
}
