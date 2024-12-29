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

int n;
const int N = 3e6 + 1;
int dp[N] = {};

struct node {
    int l, r, value;
    bool operator<(const node& b) const
    {
        return r < b.r || (r == b.r && l < b.l);
    }
};

int main2()
{
    int a, b;
    cin >> n;
    vector<node> arr(n);
    for (size_t i = 0; i < n; ++i) {

        cin >> a >> b;
        arr[i] = { a, b, b - a + 1 };
    }
    sort(arr.begin(), arr.end());
    for (size_t i = 0; i < arr[0].r; ++i) {
        dp[i] = 0;
    }
    dp[arr[0].r] = arr[0].value;
    for (size_t i = 1; i < n; ++i) {
        for (size_t op = arr[i - 1].r + 1; op < arr[i].r; ++op) {

            dp[op] = dp[arr[i - 1].r];
        }
        dp[arr[i].r] = max(dp[arr[i].l - 1] + arr[i].value, dp[arr[i - 1].r]);
    }

    //    for (size_t i = 0; i < arr[n - 1].r + 1; ++i) {
    //        cout << i << ' ' << dp[i] << endl;
    //    }
    cout << dp[arr[n - 1].r] << endl;
    return 0;
}
