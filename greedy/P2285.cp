#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>

using namespace std;

const int M = 1e4 + 3;
int n,m;
struct node {
    int x, y;
    int time;
    
}nn[M];
int dp[M] = {};
bool comp(const node& a, const node& b) {
    return a.time < b.time || (a.time == b.time && a.x < b.x);
}

int main() {

    cin >> n >> m;
    for (int i = 0; i < m; ++i) {

        cin >> nn[i].time >> nn[i].x >> nn[i].y;
    }
    sort(nn, nn + m, comp);
    int maxx = 0;
    for (int i = 0; i < m; ++i) {
        dp[i] = 1;
        for (int j = 0; j < i; ++j) {
            if (nn[i].time - nn[j].time >= abs(nn[i].x - nn[j].x) + abs(nn[i].y - nn[j].y))
            dp[i] = max(dp[i], dp[j] + 1);
        }
        maxx = max(maxx, dp[i]);
    }
    cout << maxx << endl;

    return 0;
}