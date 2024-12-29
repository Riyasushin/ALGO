#pragma GCC optimize(2)
#include <iostream>
#include <algorithm>
using namespace std;

int arr[505] = {};
bool vis[505] = {};
int n;
int res = 0;
int main() {

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        res = max(res, arr[i]);
    }

   

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            res = max(res, (arr[i] | arr[j]));
            for (int k = j + 1; k < n; ++k) {
                int a = arr[i], b = arr[j], c = arr[k], maxx = max(a, max(b, c));
                
                res = max(res, ((a | b) | c));
            }
        }
    }

    cout << res << endl;

}