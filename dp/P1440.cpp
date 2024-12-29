#include <cstring>
#include <iostream>

using namespace std;

int n, k;
int const N = 2e6 + 20;
int arr[N] = {};
int st[N];

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    // min
    int head = 1;
    int tail = 0;
    cout << 0 << endl;
    for (int i = 0; i < n - 1; ++i) {
        /// 这里写错了， arr [ st[tail] ] 少了arr[ ]

        // int left = head, right = tail, res;
        // while (left <= right) {
        //     int mid = (left + right) / 2;
        //     if (arr[st[mid]] < arr[i]) {
        //         left = mid + 1;
        //         tail = mid;
        //     } else {
        //         right = mid - 1;
        //     }
        // }
        while (head <= tail && arr[st[tail]] >= arr[i]) {
            tail--;
        }
        st[++tail] = i;

        while (st[head] <= i - k) {
            head++;
        }

        cout << arr[st[head]] << endl;
    }

    return 0;
}

/// n <= 2e6 内存爆了
/// timeout???
/// 一点都没有改，AC了？？
/// 不要用cin会超时（除非你把std同步关掉）
