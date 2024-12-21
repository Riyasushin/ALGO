//
// Created by Yasushin Ri on 2024/12/19.
//

#include <iostream>

using namespace std;

int dp[105][105] = {};
int n;
int arr[105] = {};

int main() {

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
        arr[i] += arr[i - 1];
    }

    for (int len = 2; len <= n; ++len) {
        for (int i = 1; i + len - 1 <= n; ++i) {
            int j = i + len - 1;
            dp[i][j] = 0xee0000;
            for (int k = i; k < j; ++k) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + arr[j] - arr[i - 1]);
            }
        }
    }

    //cout << 0xee0000 << endl;
    cout << dp[1][n] << endl;
    return 0;
}
