#include <iostream>

#include <cstring>
/// 我们少了i物品就是在原来的基础上少了一次这样的转移
/// 所以我们在原来的基础上顺推减去这样的一次转移就ok了
/// 爆long long 取%%
using namespace std;

int n, m;
int w[2005];
long long dp[2005], copp[2005];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> w[i];
    }

    dp[0] = 1;
    for (int i = n; i >= 1; --i) {
        for (int j = m; j >= 0; --j) {
            if (j - w[i] >= 0) dp[j] += dp[j - w[i]];
            dp[j] = (dp[j] + 10) % 10;
        }
    }


    for (int k = 1; k <= n; ++k) {
        memcpy(copp, dp, sizeof(dp));
        for (int x = 1; x <= m; ++x) {
            if (x >= w[k]) {
                copp[x] -= copp[x - w[k]];
                copp[x] = (copp[x] + 10) % 10;
            }
            cout << (copp[x] % 10);
        }
        cout << endl;
    }

    return 0;
}
