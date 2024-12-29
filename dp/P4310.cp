/* 
 File Name:     main.cpp
 Author:        RiJoShin
 Created Time:  2024/11/30 9:53:57
 Description:   这是一个新的模板描述
 */

#include <iostream>
#include <stdio.h>
using namespace std;

const int N = 1e6 + 2;
int n, temp;
int dp[N], ans = 0, maxBit = 0;
int bits[N] = {};


int main()
{
    cin >>n;
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        dp[i] = 1;
        for (int x = 0; (1 << x) <= temp; ++x) {

            if ((1 << x) & temp) {
                bits[x]++;
                dp[i] = max(dp[i], bits[x]);
            }
        }
        for (int x = 0; (1 << x) <= temp; ++x) {

            if ((1 << x) & temp) {
                bits[x] = dp[i];
            }
        }
        maxBit = max(dp[i], maxBit);
    }

    cout << maxBit <<endl;
    return 0;
}
