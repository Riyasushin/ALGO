#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100003;
int dp[N] = {};
int a[N]; /// 位置
int b[N]; /// 威力

int findLast(const int X) {
    int l = 0, r = X - 1, res = 0;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (a[mid] + b[X] < a[X]) {
            res = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    return res;

}

int main() {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> b[i];
    }

    int maxSaved = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
        int lastCanSace = findLast(i);
        dp[i] = 1 + dp[lastCanSace];
        maxSaved = max(maxSaved, dp[i]);
    }

    cout << n - maxSaved << endl;

    return 0;
}