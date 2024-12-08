#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

int dp[50006], pointer[1000], notes[50006], n, m;
bool vis[50006];

int main() {

    cin >> n >> m;
    int cnt = 0;
    int s = sqrt(n) + 1;

    for (int i = 1, temp; i <= n; ++i) {
        cin >> temp;
        if (notes[cnt] != temp) {
            notes[++cnt] = temp;
        }
    }

    n = cnt;

    for (int i = 1; i <= n; ++i) {
        dp[i] = n; // 上界
    }

    //从1计数的
    pointer[1] = 0;

    /// 总多少种
    int l = 1;
    for (int i = 1; i <= n; ++i) {
        if (vis[notes[i]]) {
            /// 试着拼盘
            int t;
            for (int j = l; j >= 1; --j) {
                if (notes[pointer[j]] == notes[i]) {
                    t = j;
                    break;
                }
            }
            for (int j = t - 1; j >= 1; --j) {
                pointer[j + 1] = pointer[j];
            }
            pointer[1] = i - 1;
        } else {
            if (l == s) {
                vis[notes[pointer[l]]] = false;
            }

            l++;
            l = min(l, s);
            for (int j = l; j >= 2; --j) {
                pointer[j] = pointer[j - 1];
            }

            pointer[1] = i - 1;
        }

        vis[notes[i]] = true;
        for (int j = 1; j <= l; ++j) {
            dp[i] = min(dp[i], dp[pointer[j]] + j * j);
        }
    }
    cout << dp[n] << endl;
}