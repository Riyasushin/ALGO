//
// Created by Yasushin Ri on 2024/12/12.
//
#include <iostream>
#include <stdio.h>
#include <cctype>
#include <cstring>
using namespace std;

int n, m, sum[203][203] = {};
int dp[203][203] = {}; /// dp[k + 1][x] = max(dp[k][i] + |sum[k+1][i] - sum[k + 1][x] |)

int main() {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    while (cin >> n >> m) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                cin >> sum[i][j];
                sum[i][j] += sum[i][j - 1];
            }
        }

        for (int i = 1; i <= n; ++i) {
            for (int x = 1; x <= m; ++x) {
                dp[i][x] = -0xee0000;
                for (int l = 1; l <= m; ++l) {

                    int dis = 0;
                    if (l < x) {
                        dis = sum[i][x] - sum[i][l - 1];
                    } else {
                        dis = sum[i][l] - sum[i][x - 1];
                    }
                    dp[i][x] = max(dp[i][x], dp[i - 1][l] + dis);
                }
            }
        }
        int maxx = -0xee0000;
        for (int x = 1; x <= m; ++x) {
            maxx = max(maxx, dp[n][x]);
        }

        cout << maxx << endl;
    }
    return 0;
}
