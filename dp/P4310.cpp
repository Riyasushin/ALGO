//
// Created by 15439 on 2024/12/11.
//
/*
# 绝世好题
## 题目描述
给定一个长度为 $n$ 的数列 $a_i$，求 $a_i$ 的子序列 $b_i$ 的最长长度 $k$，满足 $b_i \& b_{i-1} \ne 0 $，其中 $2\leq i\leq k$， $\&$ 表示位运算取与。
## 输入格式
输入文件共 2 行。
第一行包括一个整数 $n$。
第二行包括 $n$ 个整数，第 $i$ 个整数表示 $a_i$。
## 输出格式
输出文件共一行。
包括一个整数，表示子序列 $b_i$ 的最长长度。
## 提示
对于100%的数据，$1\leq n\leq 100000$，$a_i\leq 10^9$。
 */

#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5 + 5;
int bits[20] = {};
int dp[N] = {};
int n, maxx = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    dp[1] = 1;
    int temp;
    for (int i = 1; i <= n; ++i) {
        cin >> temp;
        int tt = 0;
        while ((1 << tt) <= temp) {
            if ((1 << tt) & temp) {
                dp[i] = max(dp[i], dp[bits[tt]] + 1);
                bits[tt] = i;
            }
            tt++;
        }
        maxx = max(maxx, dp[i]);
    }

    cout << maxx << endl;
    return 0;
}
