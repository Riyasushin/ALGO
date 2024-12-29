//
// Created by Yasushin Ri on 2024/12/29.
//

#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

int const N = 60;
int n, c;
long long pos[N] = {}, dp[N][N][2] = {};
int power[N] = {};
int outPower[N][N] = {};

int main() {
    cin >> n >> c;
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> pos[i] >> power[i];
        sum += power[i];
    }

    //c = lower_bound(pos + 1, pos + 1 + n, c) - pos;


    for (int i = 1; i <= n; ++i) {
         outPower[i][i] = sum - power[i];
    }
    for (int len = 2; len <= n; ++len) {
        for (int i = 1; i + len - 1 <= n; ++i) {
            const int j = i + len - 1;
            outPower[i][j] = outPower[i][j - 1] - power[j];
        }
    }

    memset(dp, 0x3f, sizeof(dp)); /// 导致溢出不行！！
    dp[c][c][0] = 0;
    dp[c][c][1] = 0;
    for (int len = 2; len <= n; ++len) {
        for (int i = 1; i + len - 1 <= n; ++i) {
            int const j = i + len - 1;
            dp[i][j][0] =
                min(dp[i + 1][j][0] + (pos[i + 1] - pos[i]) * outPower[i + 1][j],
                    dp[i + 1][j][1] + (pos[j] - pos[i]) * outPower[i + 1][j]);
            dp[i][j][1] =
                min(dp[i][j - 1][1] + (pos[j] - pos[j - 1]) * outPower[i][j - 1],
                    dp[i][j - 1][0] + (pos[j] - pos[i]) * outPower[i][j - 1]);
        }
    }

    cout << min(dp[1][n][0], dp[1][n][1]) << endl;

    return 0;
}


/// 这个 “路灯号”怎么理解
/// gank，语文题，麻，误读了
