#include <algorithm>
#include <cctype>
#include <cstring>
#include <iostream>
#include <string>
#include <map>

using namespace std;

int a[2100] = {}, b[2100] = {};
int n, m;
int dp[2][2100] = {};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    memset(dp[0], 127, sizeof(dp[0]));
    memset(dp[1], 127, sizeof(dp[1]));

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }

    int nowLine = 1, last = 0;
    dp[last][a[0]] = 0;
    dp[last][b[0]] = min(dp[last][b[0]], 1);
    for (int i = 1; i < n; ++i) {
        for (int k = m; k >= 0; --k) {
            if (k >= a[i]) {
                dp[nowLine][k] = min(dp[nowLine][k], dp[last][k - a[i]]);
            }
            if (k >= b[i] ) {

                dp[nowLine][k] = min(dp[nowLine][k], dp[last][k - b[i]] + 1);
            }
        }

        /// !!!!
        memset(dp[last], 127, sizeof(dp[last]));
        swap(nowLine, last);
    }

    for (int k = 0; k <= m; ++k) {
        cout << (dp[last][k] > m ? -1 : dp[last][k]) << endl;
    }
    return 0;
}
