//
// Created by Yasushin Ri on 2024/12/12.
//
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <string>

using namespace std;

int vv[11][5] = {
    {4, 6, -1},
    {6, 8, -1},
    {7, 9, -1},
    {4, 9, -1},
    {3, 9, 0},
    {-1, -1, -1},
    {1, 7, 0},
    {2, 6, -1},
    {1, 3, -1},
    {2, 4, -1}
};

int n;

int dp[22][10];
int dfs(int layer, int st) {
    if (layer == 0) {
        return 1;
    }
    if (dp[layer][st] == 0) {
        for (int id = 0; id < 3; ++id) {
            int x = vv[st][id];


            if (x == -1)
                break;
            dp[layer][st] += dfs(layer - 1, x);
        }
    }
    return dp[layer][st];

}

int main() {

    cin >> n;
    int cnt = 0;
    for (int i = 0; i <= 9; ++i) {
        cnt+= dfs(n - 1, i);
    }

    cout << cnt << endl;
    return 0;
}
