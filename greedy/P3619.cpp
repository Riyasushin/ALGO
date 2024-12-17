//
// Created by Yasushin Ri on 2024/12/17.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct node {
    long long times, b;
};
node a[100010], b[100010];

/// a: b_i > 0
/// b: b_i < 0

int n,  cnta = 0, cntb = 0;
/// @brief  用longlong 会爆int!!!!
long long t;

bool cmpa(const node &a, const node& b) {
    return a.times < b.times;
}

bool cmpb(const node &a, const node& b) {
    return a.times + a.b > b.times + b.b;
}

int main() {
    cin.tie(NULL);
    cin.sync_with_stdio(false);


    int trial, x, y;
    cin >> trial;
    while (trial--) {
        cin >> n >> t;
        cnta = 0, cntb = 0;
        for (int i = 0; i < n; ++i) {
            cin >> x >> y;
            if (y > 0) {
                a[cnta] = {x, y};
                cnta++;
            } else {
                b[cntb] = {x, y};
                cntb++;
            }
        }

        sort(a, a + cnta, cmpa);
        sort(b, b + cntb, cmpb);

        bool ok = true;
        for (int i = 0; i < cnta; ++i) {
            if (t <= a[i].times) {
                ok = false;
                break;
            } else {
                t += a[i].b;
            }
        }

        for (int i = 0; i < cntb; ++i) {
            if (t <= b[i].times) {
                ok = false;
                break;
            } else {
                t += b[i].b;
            }
        }

        /// 最后特判时间大于0 为什么，最后一次干道小于0后没有判断！！！
        
        if (t <= 0) {
            ok = false;
        }

        cout << (ok ? "+1s" : "-1s") << endl;
    }

    return 0;
}
