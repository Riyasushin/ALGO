#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int vis[10];
int dpRreach[1000];
int n, m;
int maxSum = 0;

int getMax(const int depth) {

    memset(dpRreach, 127, sizeof(dpRreach));
    dpRreach[0] = 0;

    for (int i = 1; i < 1000; ++i) {

        for (int k = 0; k <= depth; ++k) {

            if (i - vis[k] >= 0) {

                dpRreach[i] = min(dpRreach[i], dpRreach[i - vis[k] ] + 1);
            }
        }

        if (dpRreach[i] > m) {
            return i - 1;
        }
    }
}

void dfs(const int depth, const int maxHasReached) {
    if (depth == n) {
        maxSum = max(maxSum, maxHasReached);
    } else {

        for(int i = vis[depth] + 1; i <= maxHasReached + 1; ++i) {
            vis[depth + 1] = i;
            dfs(depth + 1, getMax(depth + 1));
            vis[depth + 1] = 0;
        }
    }
}

int main() {


    while(cin >> n >> m) {
        if (n == 0)break;
        maxSum = 0;
        memset(vis, 0, sizeof(vis));
        vis[0] = 1;
        dfs(0, m);

        cout << maxSum << endl;

    }

    return 0;
}

