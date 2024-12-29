/* ************************************************************************
 File Name:     Desktop/luogu/st.cpp
 Author:        RiJoShin
 Created Time:  一 11/25 12:36:48 2024
 Description:   DP,开启新的一周
 ************************************************************************/

#include "cctype"
#include "string"
#include <algorithm>
#include <cstring>
#include <iostream>
#include <stack>
#include <stdio.h>
#include <vector>
using namespace std;

const int N = 52;
int n, m, t;

int f[N][N * N] = {};
int g[N][N][N] = {};
char grid[N][N];
int diff[N][N] = {}; /// 第i行前j个多少1
int main2()
{
    cin >> n >> m >> t;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> grid[i][j];
            diff[i][j] = diff[i][j - 1] + (grid[i][j] == '1' ? 1 : 0);
        }
    }
    // cout << "input" << endl;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            for (int k = j; k <= m; ++k) {
                /// 第i行进行j次粉刷到第k个数最大能刷正确多少
                for (int temp = j - 1; temp < k; ++temp) {

                    g[i][j][k] = max(g[i][j][k], g[i][j - 1][temp] + max(diff[i][k] - diff[i][temp], k - temp - diff[i][k] + diff[i][temp]));
                }
                // cout << g[i][j][k] << ' ';
            }
            // cout << endl;
        }
    }
    // cout << "g[][][]" << endl;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= t; ++j) {
            for (int k = 0; k <= m; ++k) {
                if (j - k < 0)
                    continue;
                f[i][j] = max(f[i - 1][j - k] + g[i][k][m], f[i][j]);
            }
        }
    }

    cout << f[n][t] << endl;
    return 0;
}
