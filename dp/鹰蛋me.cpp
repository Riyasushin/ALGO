#pragma GCC optimize(2)
#include <algorithm>
#include <iostream>

using namespace std;

int dp[400006][21] = {};

int main() {
    cin.tie(0);
    cin.sync_with_stdio(false);

    for (int i = 0; i <= 400001; ++i) {
        dp[i][1] = i;
    }

    for (int i = 2; i <= 20; ++i) {
        int pre = 0;
        dp[1][i] = 1;
        for (int st = 2; st <= 400001; ++st) {
            if (max(dp[pre][i], dp[st - pre - 1][i - 1]) + 1 == dp[st - 1][i]) {
                dp[st][i] = dp[st - 1][i];
            } else {
                dp[st][i] = dp[st - 1][i] + 1;
                pre = st - 1;
            }
        }
    }

    int n, m;

    while (cin >> n >> m) {
        if (n == 0) {
            break;
        }

        if (m > 20) {
            m = 20;
        }
        cout << dp[n][m] << endl;
    }
}
