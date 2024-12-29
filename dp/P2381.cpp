/* ************************************************************************
 File Name:     st.cpp
 Author:        RiJoShin
 Created Time:  一 11/25 14:36:24 2024
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

const int N = 2e5 + 3;
int lengths[N] = {};
int n, x;
int len = 0;
int main2()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        lengths[i] = lengths[i - 1] + x;
        len += x;
    }
    for (int i = 1; i <= n; ++i) {
        lengths[i + n] = lengths[i] + len;
    }
    int maxll = 0, p = 1;
    for (; p <= n; ++p) {
        if (lengths[p] > len - lengths[p]) {
            maxll = max(min(lengths[p], len - lengths[p]), min(lengths[p - 1], len - lengths[p - 1]));
            break;
        }
    }
    for (int i = 1; i < n; ++i) {
        while (lengths[p] - lengths[i] < len - lengths[p] + lengths[i]) {
            p++;
        }
        maxll = max(maxll, max(min(lengths[p] - lengths[i], len - lengths[p] + lengths[i]), min(lengths[p - 1] - lengths[i], len - lengths[p - 1] + lengths[i])));
    }

    cout << maxll << endl;

    return 0;
}
