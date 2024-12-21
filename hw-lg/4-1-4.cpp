//
// Created by Yasushin Ri on 2024/12/19.
//
#include <iostream>

using namespace std;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(false);




    return 0;
}
//
//
//#include <iostream>
//using namespace std;
//
//#define MAX_N 1000
//
///// ac 用于记录达到i所需的最少餐票数ac[i]
///// p  用于存储当前正在尝试的餐票面值组合
//int ac[MAX_N] = {0}, p[MAX_N] = {0};
//int n = 0, m = 0, k = 0, ans = 0;
//
///// m  种不同面值的餐票
///// 最多只能使用k张餐票
//
///// x  当前正在确定第几种餐票的面值
///// mx 表示当前允许的最大餐票面值
//void dfs(int x,int mx)
//{
//    if(mx < 0)
//        return;
//    if(x > m)
//    {
//        /// 如果 x > m，表示已经确定了 m 种餐票的面值
//        /// 此时检查是否能恰好覆盖到 n
//        if(mx == n)
//            /// 说明找到了一种满足条件的方案
//                ans++;
//        return;
//    }
//    int *tmp = new int[MAX_N];
//    for(int i = p[x - 1] + 1;i <= mx + 1; i++)
//    {
//        p[x] = i;
//        /// r 卡最大的票的面值
//        int r = min(i * k, n + 1), j = 0;
//        for(j = i; j <= r; j++)
//        {
//
//            tmp[j] = ac[j];
//            /// 计算出凑出数值 j 所需的最少餐票数
//            ac[j] = min(ac[j], ac[j - i] + 1);
//        }
//        /// 现在凑出 n + 1 用的超过了 k 张票， 说明合法
//        if(ac[n + 1] > k)
//        {
//
//            for(j = i; j <= r + 1; j++)
//                if(ac[j] > k)
//                {
//                    ///
//                    dfs(x + 1, j - 1);
//                    break;
//                }
//        }
//        /// back 找不到能符合条件的，回溯
//        for(j = i; j <= r; j++)
//            ac[j] = tmp[j];
//    }
//}
//
//int main()
//{
//    int t = 0;
//    cin >> t;
//    while(t--)
//    {
//        cin >> m >> k >> n;
//        /// 初始化，多组数据
//        ans = 0;
//        /// 最大值
//        for(int i = 1; i <= n + 1; i++)
//            ac[i] = n + n;
//        /// 一块钱全用了
//        for(int i = 0; i <= k; i++)
//            ac[i]=i;
//        /// 第一张票一定是1
//        p[1] = 1;
//        dfs(2, k);
//        cout << ans << endl;
//    }
//    return 0;
//}
