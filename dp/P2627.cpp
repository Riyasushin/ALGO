//
// Created by Yasushin Ri on 2024/12/11.
// 单调队列优化？？
// 简单DP 90分，爆掉#9
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

const int N = 1e5 + 3;
int n, k;
long long sum[N] = {}, dp[N][2] = {};

int main() {
    cin.tie(0);
    cin.sync_with_stdio(false);

    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> sum[i];
        sum[i] += sum[i - 1];
    }


    /// pq怎么写
    priority_queue<pair< long long, int> > pq;
    pq.push(make_pair(0,0));
    for (int i = 1; i <= k; ++i) {
        dp[i][0] = sum[i - 1];
        dp[i][1] = sum[i];
        pq.push(make_pair(dp[i][0] - sum[i], i ));
    }

    for (int i = k + 1; i <= n; ++i) {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);

       while(pq.top().second< i - k) {
			pq.pop();
		}
        /// C++11不能用auto
        long long  score = pq.top().first;

        dp[i][1] = max(score + sum[i], dp[i][1]);
        pq.push(make_pair(dp[i][0] - sum[i], i ));
        // for (int tt = 1; tt <= k; ++tt) {
        //     dp[i][1] = max(dp[i][1], dp[i - tt][0] + sum[i] - sum[i - tt]);
        // }
    }

    cout << max(dp[n][0], dp[n][1]);
    return 0;
}
