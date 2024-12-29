/* ************************************************************************
 File Name:     st.cpp
 Author:        RiJoShin
 Created Time:  一 11/25 13:27:51 2024
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

#define ll long long

int f[10] = {}, tot = 0;
string num;

ll comp(int n, int m)
{
    if (n == 0)
        return 1;
    if (m == 0)
        return 1;
    else if (m == n) {
        return 1;
    } else {
        if (n < m * 2) {
            m = n - m;
        }

        ll a = 1, b = 1;
        for (int i = 1; i <= m; ++i) {
            a *= (n - i + 1);
            b *= i;
        }
        return a / b;
    }
}

ll C()
{

    int tot = 0;
    for (int i = 0; i < 10; ++i) {
        tot += f[i];
    }
    ll res = 1;
    for (int i = 0; i < 10; ++i) {
        res *= comp(tot, f[i]);
        tot -= f[i];
    }
    return res;
}

ll dfs(bool hasLimit, int layer)
{

    if (layer == num.length())
        return 0;
    else {

        ll res = 0;
        if (hasLimit) {
            /// 受限了
            for (int i = 0; i < (num[layer] - '0'); ++i) {
                if (f[i] > 0) {
                    f[i]--;
                    res += C();
                    f[i]++;
                }
            }
            if (f[num[layer] - '0'] > 0) {

                f[num[layer] - '0']--;
                res += dfs(true, layer + 1);
                f[num[layer] - '0']++;
            }

            return res;
        } else {
            return C();
        }
    }
}

int main2()
{
    cin >> num;
    for (int i = 0, len = num.length(); i < len; ++i) {

        f[num[i] - '0']++;
    }

    tot = num.length();
    ll res = dfs(true, 0);

    cout << res << endl;
    return 0;
}
