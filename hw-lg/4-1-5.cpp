//
// Created by Yasushin Ri on 2024/12/19.
//
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

char matrix[53][53];
int n;
bool vis[53][53];
const int ope[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void identify() {
    int id = 0;
    memset(vis, 0, sizeof(vis));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!vis[i][j]) {
                queue<pair<int, int> > q;
                q.push(make_pair(i, j) );
                vis[i][j] = true;
                while (!q.empty()) {
                    auto [x, y] = q.front();
                    q.pop();
                    for (int k = 0; k < 4; ++k) {
                        int nx = x + ope[k][0], ny = y + ope[k][1];
                        if (nx >= 0 && nx < n && ny >= 0 && ny < n && matrix[nx][ny] == matrix[i][j] && !vis[nx][ny]) {
                            vis[nx][ny] = true;
                            q.push(make_pair(nx, ny));
                        }
                    }
                }
                id++;
            }
        }
    }

    cout << id << endl;
}


int main() {
    cin.tie(0);
    cin.sync_with_stdio(false);

    int N;
    cin >> N;
    while (N--) {
        cin >> n;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> matrix[i][j];
            }
        }

        identify();
    }



    return 0;
}
