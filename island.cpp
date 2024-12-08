#include <iostream>
#include <vector>
#include <unordered_set>
#include <climits>

using namespace std;

// 计算从start到end的奶牛所唱音符的种类数
int countNotes(const vector<int>& cows, int start, int end) {
    unordered_set<int> noteSet;
    for (int i = start; i <= end; ++i) {
        noteSet.insert(cows[i]);
    }
    return noteSet.size();
}

int mian() {
    int n, m;
    cin >> n >> m;

    vector<int> cows(n);
    for (int i = 0; i < n; ++i) {
        cin >> cows[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, INT_MAX));
    vector<vector<int>> s(n + 1, vector<int>(n + 1));  // 记录决策点

    for (int i = 0; i <= n; ++i) {
        dp[i][i] = 1;  // 单个奶牛作为一组，不和谐值为0
        s[i][i] = i;
    }

    for (int len = 2; len <= n; ++len) {  // 区间长度从2开始遍历
        for (int i = 1; i <= n - len + 1; ++i) {  // 区间起点
            int j = i + len - 1;  // 区间终点
            for (int k = s[i][j - 1]; k <= s[i + 1][j]; k++) {  // 利用决策单调性缩小k的取值范围
                int notes = countNotes(cows, i - 1, j - 1);
                int temp = dp[i][k - 1] + dp[k][j] + notes * notes;
                if (temp < dp[i][j]) {
                    dp[i][j] = temp;
                    s[i][j] = k;
                }
            }
        }
    }

    cout << dp[1][n] << endl;

    return 0;
}