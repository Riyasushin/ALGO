/* ************************************************************************
 File Name:     st.cpp
 Author:        RiJoShin
 Created Time:  Mon Dec  2 08:57:26 2024
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

const int N = 400;
const int M = 400 * 1000;
int dp[M * 2];
int iq[N], eq[N];
int n;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> iq[i] >> eq[i];
    }

    memset(dp, -0x33333, sizeof(dp));
    dp[M] = 0;
    for (int i = 1; i <= n; ++i) {

        if (iq[i] >= 0) {
            for (int j = 800000; j >= iq[i]; --j) {
                dp[j] = max(dp[j], dp[j - iq[i]] + eq[i]);
            }
        } else {
            for (int j = 0; j <= 2 * M + iq[i]; ++j) {
                dp[j] = max(dp[j], dp[j - iq[i]] + eq[i]);
            }
        }
    }

    int ans = 0;
    for (int i = M; i <= M * 2; ++i) {
        if (dp[i] > 0) {
            ans = max(max, dp[i] + i - M);
        }
    }
    cout << ans << endl;

    return 0;
}
