//
// Created by Yasushin Ri on 2024/12/29.
//
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int N = 1e5 + 1;
int a[N], b[N];
priority_queue<int> rr;

int main() {
    int n;
    cin >> n;
    int k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    /// 及时止损
    /// 这里溢出了，？？？？？？
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n && (i + 1) * (j + 1) <= n; ++j) {
            rr.push(-a[i] - b[j]);
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << (i == 0 ? "" : " ") << -rr.top();
        rr.pop();
    }

    return 0;
}
