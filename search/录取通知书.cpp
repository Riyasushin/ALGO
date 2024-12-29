#include <algorithm>
#include <cctype>
#include <cstring>
#include <iostream>
#include <map>
#include <string>

using namespace std;

struct student {
    int id, totalscore, math, combine, chinese, english;
    int tar[3];
    int result;

} stus[1010];

bool cmp(student const &a, student const &b) {
    return a.totalscore > b.totalscore ||
           (a.totalscore == b.totalscore && a.math > b.math) ||
           (a.totalscore == b.totalscore && a.math == b.math &&
            a.combine > b.combine) ||
           (a.totalscore == b.totalscore && a.math == b.math &&
            a.combine == b.combine && a.chinese > b.chinese);
}

bool cmp2(student const &a, student const &b) {
    return a.id < b.id;
}

int n, m, k;
int positions[105] = {};
map<int, int> SchoolID;
map<int, int> stuID;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> k;

    int idS, mans;
    for (int i = 0; i < n; ++i) {
        cin >> idS >> mans;
        SchoolID[idS] = i;
        positions[i] = mans;
    }

    for (int i = 0; i < m; ++i) {
        int IDSTU;
        cin >> IDSTU >> stus[i].totalscore >> stus[i].math >> stus[i].combine >>
            stus[i].chinese >> stus[i].english;
        stus[i].id = i;
        stus[i].tar[0] = -1;
        stus[i].tar[1] = -1;
        stus[i].tar[2] = -1;
        stuID[IDSTU] = i;

        int b;
        for (int cnt = 0; cnt < 3; ++cnt) {
            cin >> b;
            stus[i].tar[cnt] = b;
        }
    }

    sort(stus, stus + m, cmp);
    for (int i = 0; i < m; ++i) {
        stus[i].result = -1;
        for (int x = 0; x < 3; ++x) {
            if (stus[i].tar[x] == -1) {
                break;
            }

            int idTrue = SchoolID[stus[i].tar[x]];

            if (positions[idTrue] > 0) {
                stus[i].result = stus[i].tar[x];
                positions[idTrue] = positions[idTrue] - 1;
                break;
            } else {
            }
        }
    }

    sort(stus, stus + m, cmp2);
    for (int i = 0; i < k; ++i) {
        int tt;
        cin >> tt;
        int id = stuID[tt];
        cout << (i == 0 ? "" : " ") << stus[id].result;
    }

    return 0;
}
