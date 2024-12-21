//
// Created by Yasushin Ri on 2024/12/19.
//
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

int w, h;
int bestLne = 0xee0000;
int edX, edY;
char matrix[80][80];
int const moves[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
bool vis[80][80] = {};

void dfs(int nowX, int nowY, int direct, int lenNow) {
    if (lenNow >= bestLne) {
        return;
    }
    if (nowX == edX && nowY == edY) {
        bestLne = min(bestLne, lenNow);
        return;
    }

    for (int i = 0; i < 4; ++i) {
        int nx = nowX + moves[i][0], ny = nowY + moves[i][1]; /// !

        if (nx >= 0 && nx <= w + 1 && ny >= 0 && ny <= h + 1 &&
            ((matrix[nx][ny] == ' ' && vis[nx][ny] == false) ||
             (nx == edX && ny == edY))) {
            vis[nx][ny] = true;

            int ad = (i == direct ? 0 : 1);

            dfs(nx, ny, i, lenNow + ad);

            vis[nx][ny] = false;
        }
    }
}

int main() {
    int id = 0;
    while (scanf("%d%d", &h, &w)) {
        getchar();
        if (w == 0 && h == 0) {
            break;
        }

        id++;
        string line;

        for (int i = 0; i <= w + 1; ++i) {
            for (int j = 0; j <= h + 1; ++j) {
                if (i == 0 || j == 0 || j == h + 1 || i == w + 1) {
                    matrix[i][j] = ' ';
                } else {
                    scanf("%c", &matrix[i][j]);
                }

            }
            if (i >= 1 && i <= w) {
                getchar();
            }
        }

        cout << "Board #" << id << ':' << endl;
        int Pair = 0, x1, y1;
        while (scanf("%d%d%d%d",&y1,&x1,&edY,&edX)) {
            if (x1 == 0 && y1 == 0) {
                break;
            }

            bestLne = 0xee0000;
            memset(vis, 0, sizeof(vis) );

            dfs(x1, y1, -1, 0);

            Pair++;
            if (bestLne != 0xee0000) {
                cout << "Pair " << Pair << ": " << bestLne << " segments."
                     << endl;
            } else {
                cout << "Pair " << Pair << ": impossible." << endl;
                ;
            }
        }
        cout << endl;
    }

    return 0;
}
