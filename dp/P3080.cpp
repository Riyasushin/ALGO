//
// Created by Yasushin Ri on 2024/12/29.
//

#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

int const N = 1055;
int n;
int pos[N] = {}, dp[N][N][2] = {};

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> pos[i];
    }
    sort(pos + 1, pos + 1 + n);

    int c = lower_bound(pos + 1, pos + n + 1, 0) - pos;
    for (int i = n + 1; i > c; --i) { /// 倒着，为什么，不能相互影响
        pos[i] = pos[i - 1];
    }
    pos[c] = 0;

    memset(dp, 0x3f, sizeof(dp)); /// 导致溢出不行！！

    dp[c][c][0] = 0;
    dp[c][c][1] = 0;
    for (int len = 2; len <= n + 1; ++len) {
        for (int i = 1; i + len - 1 <= n + 1; ++i) {
            int const j = i + len - 1;
            dp[i][j][0] =
                min(dp[i + 1][j][0] + (pos[i + 1] - pos[i]) * (n - j + i + 1),
                    dp[i + 1][j][1] + (pos[j] - pos[i]) * (n - j + i + 1));
            dp[i][j][1] =
                min(dp[i][j - 1][1] + (pos[j] - pos[j - 1]) * (n - j + i + 1),
                    dp[i][j - 1][0] + (pos[j] - pos[i]) * (n - j + i + 1));
        }
    }

    cout << min(dp[1][n + 1][0], dp[1][n + 1][1]) << endl;

    return 0;
}
