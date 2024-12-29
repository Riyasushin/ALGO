#include <iostream>

using namespace std;

int n, k;
int const N = 1e6 + 20;
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
    for (int i = 0; i < n; ++i) {
        while (head <= tail && arr[st[tail]] >= arr[i]) {
            tail--;
        }
        st[++tail] = i;

        while (st[head] <= i - k) {
            head++;
        }
        if (i >= k - 1) {
            cout << (i == k - 1 ? "" : " ") << arr[st[head]];
        }
    }
    cout << endl;
    /// max
    head = 1;
    tail = 0;
    memset(st, 0, sizeof(st));
    for (int i = 0; i < n; ++i) {
        while (head <= tail && arr[st[tail]] <= arr[i]) {
            tail--;
        }
        st[++tail] = i;

        while (st[head] <= i - k) {
            head++;
        }
        if (i >= k - 1) {
            cout << (i == k - 1 ? "" : " ") << arr[st[head]];
        }
    }
    cout << endl;

    return 0;
}
