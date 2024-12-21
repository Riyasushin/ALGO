//
// Created by Yasushin Ri on 2024/12/19.
//
#include <iostream>

using namespace std;


int schools[550];
int res = 214746356;
int diff[550] = {};
int n, m;

void dfs(int theSchoolToBUild, int lastSchoolPosition) {
    if (theSchoolToBUild == m + 1) {

       // cout << "b";
        int tempRes = 0;
        for (int i = 1; i < schools[1]; ++i) {
            tempRes += diff[schools[1] - 1] - diff[i - 1];
        }
        for (int id = 1; id < m; ++id) {
            for (int i = schools[id] + 1; i < schools[id + 1]; ++i) {
                tempRes += min(diff[schools[id + 1] - 1] - diff[i - 1],
                               diff[i - 1] - diff[schools[id] - 1] );
            }
        }
        for (int i = schools[m] + 1; i <= n; ++i) {
            tempRes += diff[i - 1] - diff[schools[m] - 1];
        }

        res = min(res, tempRes);
    } else {
      //  cout << "a";
        for (int i = lastSchoolPosition + 1; i  <= n; ++i) {
            schools[theSchoolToBUild] = i;
            dfs(theSchoolToBUild + 1, i);
        }
    }
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(false);

    diff[0] = 0;
    cin >> n >> m;
    for (int i = 1; i < n; ++i) {
        cin >> diff[i];
        diff[i] += diff[i - 1];
    }

    dfs(1, 0);

    cout << res << endl;


    return 0;
}
