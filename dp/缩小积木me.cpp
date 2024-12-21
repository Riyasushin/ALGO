#include <iostream>

using namespace std;

const int N = 1e6 + 5;
int ups[N];
int downs[N];
int arr[N];
int main() {

    int n;
    cin >> n;
    for (size_t i = 0; i < n; i++) {
        cin >> arr[i];
    }

    ups[0] = 1;
    downs[0] = 1;
    for (size_t i = 1; i < n; i++) {
        if (arr[i] > arr[i - 1]) {
            ups[i] = ups[i - 1] + 1;
        } else if (arr[i] < arr[i - 1]) {
            ups[i] = 1;
        } else {
            ups[i] = ups[i - 1];
        }
    }
    downs[n - 1] = 1;
    for (int i = n - 2; i >= 0; --i) {
        if (arr[i] > arr[i + 1]) {
            downs[i] = downs[i + 1] + 1;
        } else if (arr[i] < arr[i + 1]) {
            downs[i] = 1;
        } else {
            downs[i] = downs[i + 1];
        }
    }
    long long res = 0;
    for (size_t i = 0; i < n; i++) {
        res += max(ups[i], downs[i]);
    }

    cout << res;

    return 0;
}
