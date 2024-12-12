#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

const int N = 1e5 + 3;
struct Node
{
    int A, B;
    bool operator< (const Node& b) {
        return  A < b.A;
    }
}arr[N];

int n, m;

int main() {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i].A >> arr[i].B;
    }
    sort(arr, arr + n);

    int idx = 0, ans = 0;
    priority_queue<int> pp;
    for (int day = 0; day < m; ++day) {
        for (; arr[idx].A <= day + 1 && idx < n; idx++) {
            pp.push(arr[idx].B);
        }

        if (!pp.empty()) {
            ans += pp.top();
            pp.pop();
        }
    }

    cout << ans << endl;
    

    return 0;
}
