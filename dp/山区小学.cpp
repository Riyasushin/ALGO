#include <iostream>

using namespace std;
int dp[504][504]; // 到i 为止，建 j 个学校，结果最小为
int dist[504][504];
int total[504][504];

int main() {
    int n, m;
    /// m 村落
    /// n 学校
    cin >> m >> n;
    for (int i = 1; i < m; ++i) {
        cin >> dist[i][i + 1];
    }
    for (int i = 1; i <= m; ++i) {
        for (int j = i + 1; j <= m; ++j) {
            dist[i][j] = dist[i][j - 1] + dist[j - 1][j];
            dist[j][i] = dist[i][j];
        }
    }

    /// 算 i ~ j 建一个学校总需的路程
    for (int i = 1; i <= m; ++i) {
        for (int j = i + 1; j <= m; ++j) {
            int mid = i + (j - i) / 2;
            for (int k = i; k <= j; ++k) {
                total[i][j] += dist[k][mid];
            }
        }
    }
    for (int i = 1; i <= m; ++i) {
        dp[i][1] = total[1][i];
    }

    for (int i = 1; i <= m; i++) {
        for (int schools = 2; schools <= n; schools++) {
            dp[i][schools] = 0xee0000;
            for (int k = schools - 1; k <= i; k++) {
                dp[i][schools] = min(dp[i][schools], dp[k][schools - 1] + total[k + 1][i]);
            }
        }
    }
    cout << dp[m][n] << endl;

    return 0;
}
