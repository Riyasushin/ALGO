/* ************************************************************************
 File Name:     st.cpp
 Author:        RiJoShin
 Created Time:  日 11/24 09:53:01 2024
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

const int N = 1e6 + 2;

/// 0, 1, 2    0, 1, -1
/// dp[i][k]
int dp[N][3];
int n, x;

int main2()
{
    cin >> n;
    for (size_t i = 0; i < n; ++i) {
        cin >> x;
        if (i == 0) {
            dp[i][(x + 3) % 3] = 0;
            dp[i][(x + 1) % 3] = -1;
            dp[i][(x + 2) % 3] = -1;

        } else {
            dp[i][0] = dp[i][1] = dp[i][2] = -1;

            if (x == -1) {
                dp[i][0] = -1;
                dp[i][2] = (dp[i - 1][2] == -1 ? -1 : dp[i - 1][2]);
                dp[i][1] = (dp[i - 1][1] == -1 ? -1 : dp[i - 1][1] + 2);
            } else if (x == 0) {

                dp[i][0] = (dp[i - 1][0] == -1 ? -1 : dp[i - 1][0]);
                if (dp[i - 1][2] != -1) {
                    dp[i][0] = (dp[i][0] == -1 ? dp[i - 1][2] : min(dp[i - 1][2], dp[i][0]));
                }

                dp[i][1] = (dp[i - 1][1] == -1 ? -1 : dp[i - 1][1] + 1);

                dp[i][2] = (dp[i - 1][2] == -1 ? -1 : dp[i - 1][2] + 1);
            } else {

                dp[i][2] = (dp[i - 1][2] == -1 ? -1 : dp[i - 1][2] + 2);
                dp[i][0] = (dp[i - 1][2] == -1 ? -1 : dp[i - 1][2] + 1);
                dp[i][1] = (dp[i - 1][1] == -1 ? -1 : dp[i - 1][1]);
                if (dp[i - 1][2] != -1) {
                    dp[i][1] = (dp[i][1] == -1 ? dp[i - 1][2] : min(dp[i - 1][2], dp[i][1]));
                }
                if (dp[i - 1][0] != -1) {
                    dp[i][1] = (dp[i][1] == -1 ? dp[i - 1][0] : min(dp[i - 1][0], dp[i][1]));
                }
            }
        }

        if (dp[i][0] == -1 && dp[i][1] == -1 && dp[i][2] == -1) {

            cout << "BRAK" << endl;
            return 0; //// 不好，还是这么写了
        }
    }

    int res = 0x3fffffff; /// 初始化为一个大值
    res = (dp[n - 1][0] == -1 ? res : min(res, dp[n - 1][0]));
    res = (dp[n - 1][1] == -1 ? res : min(res, dp[n - 1][1]));
    res = (dp[n - 1][2] == -1 ? res : min(res, dp[n - 1][2]));
    cout << res << endl;
    return 0;
}
