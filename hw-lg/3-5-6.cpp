//
// Created by Yasushin Ri on 2024/12/12.
//
#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int cost;
    int level;
    bool operator<(const Node& other) const {
        return level > other.level;
    }
}arr[105];

int n, m;

int main() {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i].cost >> arr[i].level;
    }
    sort(arr, arr + n);

    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (m - arr[i].cost >=0) {
            cnt++;
            m -= arr[i].cost;
        } else {
            break;
        }
    }
    cout << cnt << endl;

    return 0;
}
