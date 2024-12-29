/* ************************************************************************
 File Name:     st.cpp
 Author:        RiJoShin
 Created Time:  Fri Nov 29 09:38:56 2024
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

int res = 0, n;
const int N = 262147;
int dp[61][262147];

int main()
{
    cin >> n;
    vector<int> arr(n + 2);
    for (size_t i = 1; i <= n; ++i) {
        cin >> arr[i];
        dp[arr[i]][i] = i + 1;
    }

    for (int i = 2; i <= 58; ++i)
        for (int j = 1; j <= n; ++j) {
            if (!dp[i][j])
                dp[i][j] = dp[i - 1][dp[i - 1][j]];
            if (dp[i][j])
                res = i;
        }

    cout << res;

    return 0;
}
