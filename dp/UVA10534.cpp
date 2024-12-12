//
// Created by 15439 on 2024/12/12.
//

/// 最长递增子序列 LIS
/// 二分搜索
/// O(nlogn)
/// if a[i] > a[i - 1],  a[i] 入栈
/// if not 二分查找 s中大于等于 a[i]的最小的数,替换掉它
/// 下面 m 维护的就是贪心找到的最长递增子序列


#include <iostream>
#include <cstring>
#include <string.h>

using namespace std;

const int N = 1e4 + 3;
int arr[N], m[N], pre[N], suf[N];

int main() {

    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n;
    while (cin >> n) {
        memset(pre, 0, sizeof(pre));
        memset(m, 0, sizeof(m));
        memset(suf, 0, sizeof(suf));
        for (int i = 1; i <= n; ++i) {

            cin >> arr[i];
        }

        int cnt = 0;
        for (int i = 1; i <= n; ++i) {
            if (arr[i] > m[cnt]) {
                m[++cnt] = arr[i];
                pre[i] = cnt - 1;
            } else {
                m[lower_bound(m +1, m + 1 + cnt, arr[i]) - m] = arr[i];
                pre[i] = lower_bound(m +1, m + 1 + cnt, arr[i]) - m - 1;
            }
        }

        cnt = 0;
        memset(m, 0, sizeof(m));

        for (int i = n; i >= 1; --i) {
            if(arr[i]>m[cnt]){
                m[++cnt]=arr[i];
                suf[i]=cnt-1;
            }
            else{
                m[lower_bound(m + 1,m + cnt + 1, arr[i]) - m] = arr[i];
                suf[i]=lower_bound(m + 1, m + cnt + 1, arr[i]) - m - 1;
            }
        }
        int ans = 1;
        for (int i = 1; i <= n; ++i) {
            ans = max(ans, min(suf[i], pre[i]) * 2 + 1);
        }

        cout << ans << endl;
    }

    return 0;
}