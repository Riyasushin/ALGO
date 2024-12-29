/* ************************************************************************
> File Name:     st.cpp
> Author:        RiJoShin
> Created Time:  六 11/23 22:57:28 2024
> Description:   动态规划基础题，不说了
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

int n, m;
int cardbar[4] = {};
int num[4] = {};
size_t cnt = 0;
const int N = 41;
int dp[N][N][N][N] = {};
int values[352] = {};

int dis(int a, int b, int c, int d)
{

    return 1 + a * cardbar[0] + b * cardbar[1] + c * cardbar[2] + d * cardbar[3];
}

int dfs(int a, int b, int c, int d)
{

    if (dp[a][b][c][d] == 0) {
        int dist = dis(a, b, c, d);
        int res = values[dist];
        if (a > 0) {
            res = max(res, dfs(a - 1, b, c, d) + values[dist]);
        }
        if (b > 0) {

            res = max(res, dfs(a, b - 1, c, d) + values[dist]);
        }
        if (c > 0) {
            res = max(res, dfs(a, b, c - 1, d) + values[dist]);
        }
        if (d > 0) {
            res = max(res, dfs(a, b, c, d - 1) + values[dist]);
        }
        dp[a][b][c][d] = res;
    }

    return dp[a][b][c][d];
}

int main2()
{
    cin >> n >> m;
    for (size_t i = 1; i <= n; ++i) {
        cin >> values[i];
    }
    int x;
    size_t po;
    for (size_t i = 0; i < m; ++i) {
        cin >> x;
        for (po = 0; po < cnt; ++po) {
            if (cardbar[po] == x) {

                num[po]++;
                break;
            }
        }
        if (po == cnt) {
            cardbar[cnt] = x;
            cnt++;
            num[po]++;
        }
    }
    cout << dfs(num[0], num[1], num[2], num[3]) << endl;

    return 0;
}
