//
// Created by Yasushin Ri on 2024/12/19.
//
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;


const int N = 400011;
int dp[30][N] = {};

int pow2[] = {1, 2, 4, 8, 16, 32, 64, 128, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 121072, 262144, 524288};

int dfs(int n, int h) {
    if (h == 0) {
        return 0;
    }
    if (n == 1) {
        return h;
    } else {
        if (n > 19) {
            n = 19;
        }
        if (dp[n][h] < 0) {

            dp[n][h] = 0xeeeeeee;
            for (int k = 1; k <= h; ++k) {
                dp[n][h] = min(dp[n][h], 1 +  max(dfs(n, h - k), dfs(n - 1, k - 1)));
            }
        }

        return dp[n][h];
    }
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(false);

    int n, k;
    memset(dp, 128, sizeof(dp));
    while (cin >> n >> k) {
        if (n == 0 && k == 0) {
            break;
        }
        cout << dfs(k, n) << endl;
    }

    return 0;
}
