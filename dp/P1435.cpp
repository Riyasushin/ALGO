/* ************************************************************************
 File NAme:     st.cpp
 Author:        RiJoShin
 Created Time:  Mon Dec  2 14:23:19 2024
 Description:   这是一个新的模板描述
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

string A, B;
int dp[1002][1002] = {};
int dfs(int a, int b)
{
    if (a == 0)
        return 0;
    if (b == 0)
        return 0;

    if (dp[a][b] == -1) {
        dp[a][b] = 0;
        if (A[a - 1] == B[b - 1]) {
            dp[a][b] = dfs(a - 1, b - 1) + 1;
        } else {

            dp[a][b] = dfs(a - 1, b - 1);
        }
        dp[a][b] = max(dp[a][b], dfs(a, b - 1));
        dp[a][b] = max(dp[a][b], dfs(a - 1, b)); //// 注意这一怒的对偶，探索全面！！
    }
    return dp[a][b];
}

int main2()
{
    cin >> A;
    B = A;
    int len = A.length();
    for (int i = 0; i <= len; ++i) {
        for (int j = 0; j <= len; ++j) {
            dp[i][j] = -1;
        }
    }
    reverse(A.begin(), A.end());

    cout << len - dfs(len, len);

    return 0;
}
