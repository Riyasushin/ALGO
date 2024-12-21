//
// Created by Yasushin Ri on 2024/12/19.
//
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int w, h;
char matrix[80][80];
const int moves[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

bool vis[80][80] = {};

void dfs(int nowX, int nowY, int direct, bool& hasreached, int& bestLne, int lenNow, const int edX, const int edY) {

    if (lenNow >= bestLne)
        return;
    if(nowX == edX && nowY == edY) {
        bestLne = min(bestLne,lenNow);
        hasreached = true;
        return;
    }

    for (int i = 0; i < 4; ++i) {
        int dir = (direct + i) % 4;
        int nx = nowX + moves[dir][0], ny = nowY + moves[i][1];

        if( nx >= 0 && nx <= w + 1 && ny >= 0 && ny <= h + 1 && ( (matrix[nx][ny] == ' ' && vis[nx][ny] == 0) || ( nx == edX && ny == edY))) {
            vis[nx][ny] = true;

            int ad = (i == 0 ? 0 : 1);
            dfs(nx, ny, dir, hasreached, bestLne, lenNow + ad, edX, edY);

            vis[nx][ny] = false;
        }


    }

}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(false);

    int id = 0;
    while (cin >> w >> h) {
        if (w == 0 && h == 0) {
            break;
        }

        id++;
        string line;
        cin.ignore(); // 读入数，\n
        for (int i = 1; i <= h; ++i) {
            getline(cin, line);
            for (int j = 1; j <= w; ++j) {
                 matrix[j][i] = line[j];/// (w, h)
            }
        }

        cout << "Board #" << id << ':' << endl;
        int Pair = 0, x1, y1, x2, y2;
        while (cin >> x1 >> y1 >> x2 >> y2) {
            if (x1 == 0 && y1 == 0 && x2 == 0 && y2 == 0) {
                break;
            }

            memset(vis, 0, sizeof(vis));

            bool find = false;
            int CNT = 0xee0000;

            for (int i = 0; i < 4; ++i) {
                int nx = x1 + moves[i][0];
                int ny = y1 + moves[i][1];
                if( nx >= 0 && nx <= w + 1 && ny >= 0 && ny <= h + 1 && ( (matrix[nx][ny]== ' ' && vis[nx][ny] == 0) )) {
                    vis[nx][ny] = true;

                    int ad = (i == 0 ? 0 : 1);
                    dfs(nx, ny, i, find, CNT, 1, x2, y2);

                    vis[nx][ny] = false;
                }
            }

            Pair++;
            if (find) {
                cout << "Pair " << Pair << ": " << CNT << " segments." << endl;
            } else {
                cout << "Pair " << Pair << ": impossible." << endl;;
            }
        }
        cout << endl;


    }


    return 0;
}
