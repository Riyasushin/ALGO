#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

const int N = 1e5 + 2;
int n, temp;
int mapp[N];
int newArr[N];

int main() {

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        mapp[temp] = i;
    }
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        newArr[i] = mapp[temp];
    }

    int cnt = 0;
    vector<int> st(n + 1);
    st[cnt] = newArr[0];
    for(int i = 1;i < n; ++i)
    {

        if (newArr[i] < st[cnt]) {
            st[++cnt] = newArr[i];
        } else {
            for (int x = 0;x <= cnt; ++x) {
                if (st[x] > newArr[i]) {
                    st[x] = newArr[i];
                    break;
                }
            }
        }

    }
    cout << cnt + 1 << endl;

    return 0;
}
