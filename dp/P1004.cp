/* 
 File Name:     main.cpp
 Author:        RiJoShin
 Created Time:  2024/11/30 9:05:46
 Description:   这是一个新的模板描述
 */

#include <iostream>
#include <stdio.h>
using namespace std;

int grid[10][10] = {};
int dp[10][10][20] = {};
int n;

int Max(int a1, int a2, int a3, int a4) {
    return max(a1, max(a2, max(a3, a4)));
}

int dfs(int i, int j, int x) {
    if (x >= n || i + j - x < 0 || i + j - x >= n)
        return 0;
    if (i < 0 || j < 0 || j >= n || i >= n )
        return 0;

    if (dp[i][j][x] == -1) {
        int a1 = dfs(i - 1, j, x);
        int a2 = dfs(i - 1, j, x - 1);
        int a3 = dfs(i, j - 1, x);
        int a4 = dfs(i, j - 1, x - 1);

        if (i == x) {
            dp[i][j][x] = Max(a1, a2, a3, a4) + grid[i][j];
        } else {
            dp[i][j][x] = Max(a1, a2, a3, a4) + grid[i][j] + grid[x][i + j - x];
        }
    }
    return dp[i][j][x];

}


int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int x = 0; x <= i + j; ++x) {
                dp[i][j][x] = -1;
            }
        }
    }

    int a, b, c;
    while(true) {
        cin >> a >> b >> c;
        if (c == 0) {
            break;
        }
        grid[a - 1][b - 1] = c;
    }


    cout << dfs(n - 1, n - 1, n - 1);
    return 0;
}
