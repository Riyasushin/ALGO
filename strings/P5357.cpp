// Created by 15439 on 2024/12/15.

#include <iostream>

using namespace std;

const int MAXN = 2e5 + 1; // 目标字符串的数量
const int MAXS = 2e5 + 1; // 所有目标字符总字符数量

/// 结尾节点的编号
int Ends[MAXN] = {};

int tree[MAXS][26] = {};
int fail[MAXS] = {};

int cnt = 0;

///
int times[MAXS] = {};
int box[MAXS] = {};

/// 链式前向星
int head[MAXS] = {};
int Next[MAXS] = {};
int to[MAXS] = {};
int edge = 0;

void addEdge(int u, int v) {
    Next[++edge] = head[u];
    head[u] = edge;
    to[edge] = v;
}
bool visited[MAXS] = {};
void f2(int u) {

    int r = 0;
    box[r++] = u;

    int cur;
    while (r > 0) {
        cur = box[r - 1];
        if (!visited[cur]) {
            visited[cur] = true;
            for (int i = head[cur]; i > 0; i = Next[i]) {
                box[r++] = to[i];
            }
        } else {
            r--;
            for (int i = head[cur]; i > 0; i = Next[i]) {
                times[cur] += times[to[i]];
            }
        }
    }


}


/// ac 插入目标串
void insert(const int i, string str) {
    int u = 0;
    for (int j = 0, len = str.length(); j < len; ++j) {
        int c = str[j] - 'a';
        if (tree[u][c] == 0) {
            tree[u][c] = ++cnt;
        }
        u = tree[u][c];
    }

    Ends[i] = u;
}

//

void setFail() {
    int l = 0, r = 0;
    for (int i = 0; i <= 25; ++i) {
        if (tree[0][i] > 0) {
            box[r++] = tree[0][i];
        }
    }
    while (l < r) {
        int u = box[l++];
        for (int i = 0; i <= 25; ++i) {
            if (tree[u][i] == 0) {
                tree[u][i] = tree[fail[u]][i];
            } else {
                fail[tree[u][i]] = tree[fail[u]][i];
                box[r++] = tree[u][i]; /// ??
            }
        }
    }
}



int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    string s;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> s;
        insert(i, s);
    }
    setFail();

    cin >> s;
    for (int u = 0, i = 0, len = s.length(); i < len; ++i) {
        u = tree[u][s[i] - 'a'];

        times[u]++;
    }

    for (int i = 1; i <= cnt; ++i) {
        addEdge(fail[i], i);
    }

    f2(0);

    for (int i = 1; i <= n; ++i) {
        cout << times[Ends[i]] << endl;
    }


    return 0;
}
