//
// Created by Yasushin Ri on 2024/12/9.
//
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string line, s = "";
int dp[52][52] = {};

int dfs(int l, int r) {
    if (l > r)
        return 0;
    if (l == r)
        return 1;

    if (dp[l][r] == 0) {
        dp[l][r] = 1 + dfs(l + 1, r); // 初始值：单独涂第一个字符

        for (int i = l + 1; i <= r; ++i) {
            if (s[i - 1] == s[l - 1]) { // 只有颜色相同的部分才可能减少涂色次数
                dp[l][r] = min(dp[l][r], dfs(l + 1, i - 1) + dfs(i, r));
            }
        }
    }

    return dp[l][r];
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> line;

    // 去掉重复的相邻字符，优化计算
    s += line[0];
    for (int i = 1, len = line.size(); i < len; i++) {
        if (line[i] != line[i - 1]) {
            s += line[i];
        }
    }

    cout << dfs(1, s.size()) << endl;
}
