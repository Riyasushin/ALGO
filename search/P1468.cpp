//
// Created by Yasushin Ri on 2024/12/29.
//
#include <iostream>
#include <set>

using namespace std;


/// 6 1 2 3 4 5
const int Table[8][6] =  {
    {1,1,1,1,1,1},// 0
    {0,0,0,0,0,0},//1
    {0,1,0,1,0,1},//2
    {1,0,1,0,1,0},//3
    {1,0,1,1,0,1},//4
    {0,1,0,0,1,0},//1,4
    {0,0,0,1,1,1},//2,4
    {1,1,1,0,0,0},//3,4
};

int main() {

    int n, c;
    cin >> n >> c;

    int line[7] = {-1,-1,-1,-1,-1,-1};

    bool ok = true;
    int k;
    while (cin >> k) {
        if (k == -1) {
            break;
        } else {
            if (line[k % 6] == -1) {
                line[k % 6] = 1;
            } else {
                if (line[k % 6] == 0) {
                    ok = false;
                }
            }
        }
    }
    while (cin >> k) {
        if (k == -1) {
            break;
        } else {
            if (line[k % 6] == -1) {
                line[k % 6] = 0;
            } else {
                if (line[k % 6] == 1) {
                    ok = false;
                }
            }
        }
    }
    if (ok == false) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    set<string> res;
    for (int i = 0; i < 8; ++i) {
        if (c == 0 && i > 0) {
            break;
        }
        if (i > 4 && c == 1)
            break;
        bool canUse = true;
        for (int x = 0; x < 6; ++x) {
            if (line[x] == -1 ) {
                continue;
            }
            if (line[x] != Table[i][x]) {
                canUse = false;
                break;
            }
        }
        if (canUse) {
            string a = "";
            for (int x = 1; x <= 6; ++x) {
                a += char(Table[i][x % 6] + '0');
            }
            res.insert(a);
        }
    }

    if (res.empty()) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        for (auto li : res) {
            for (int i = 0; i < n; ++i) {
                cout << li[i%6];
            }
            cout << endl;
        }
    }
    return 0;
}


/// 打表，极大的失败
/// 改动，应当是平移而不是交换
/// 特殊情况，思考时考虑了，code时候没有考虑