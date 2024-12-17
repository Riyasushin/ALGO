#include <iostream>
#include <queue>
#include <algorithm>
#include <cctype>
#include <cstring>
using namespace std;

/// 基础DP
/// dp[i] = max(val[i] + dp[i - k]) k = L, ... R
/// 单调队列优化

const int N = 2e5 + 2;
int dp[N];
int value[N];
int n, l, r;

int que[N], head = 1, tail = 1;
void insert(const int i) {
    for ( ; dp[i] >= dp[que[tail]] && tail >= head; ) {
        tail--;
    }
    que[++tail] = i;
}
int query(int x) {
    for (; que[head] + r < x; ) {
        head++;
    }
    return que[head];
}


int main() {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin >> n >> l >> r;
    for (int i = 0; i <= n; ++i)
    {
        cin >> value[i];

    }

    /// 初始化成极小值
    memset(dp, 128, sizeof(dp));
    dp[0] = 0;
    int ans = -0xee0000;
    for (int i = l; i <= n; ++i) {

        insert(i - l);
        
        int from = query(i);
        dp[i] = value[i] + dp[from];
        if (i + r > n) {
            ans = max(ans, dp[i]);
        }

    }
    // for (int i = 0; i <= n; ++i)
    // {
    //     cout << dp[i] << endl;

    // } 
    cout << ans << endl;
    
    return 0;
}