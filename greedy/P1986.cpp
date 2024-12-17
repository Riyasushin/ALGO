
/// 空间复杂度 O(n)
/// 时间复杂度 O(mn)

#include <algorithm>
#include <iostream>
using namespace std;

const int N = 3e4 + 4;
struct node
{
    int l, r, num;
    bool operator<(const node &b) const { return r < b.r || r == b.r && l < b.l; }
} arr[N] = {};
bool vis[N] = {};

int n, m;

int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        cin >> arr[i].l >> arr[i].r >> arr[i].num;
    }
    sort(arr, arr + m);

    int res = 0;
    for (int i = 0; i < m; ++i)
    {
        int cnt = 0;

        /// 怎么记忆话这里，减少回溯的重复搜索
        /// 维护线段树把区间查询降到logn
        for (int st = arr[i].l; st <= arr[i].r; ++st)
        {
            if (vis[st])
                cnt++;

            // cout << "a"; // debug
        }

        for (int st = arr[i].r; cnt < arr[i].num; --st)
        {
            if (vis[st] == false)
            {
                vis[st] = true;
                cnt++;
                res++;
            }

            // cout << "b"; // debug
        }
    }

    cout << res << endl;
    return 0;
}

///test