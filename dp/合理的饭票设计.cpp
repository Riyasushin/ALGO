/*
题目描述

以前大学食堂都使用餐票吃饭，每顿饭菜钱可以为1角，2角，...，最多为n角。如果规定每次吃饭最多只能使用k张餐票，是否可以设计m种不同面值的餐票，使得餐票从1开始可以连续覆盖的面值范围恰好为 1 - n（角）？满足上述条件的方案有多少？
假设 n 的值不超过500，饭菜钱单位为角。
例如，
m=3, k=2, n=8, 则，面值为：{1,3,4} 恰好覆盖 1,2,...,8，此时，1角只需要1张面值为1的即可，2角需要2张面值为1的，3角只需要1张面值为3的，4角只需要1张面值为4的，5角需要1张面值为1的再加上1张面值为4的，6角需要2张面值为3的，7角需要1张面值为3再加上1张面值为4的，8角需要2张面值为4的。即：只需要2张面值的饭票即可覆盖1-8的范围（注意：一定是连续覆盖）。除了这三种面值之外，再没有其他方案的面值。因此，这样的方案有1种。
若m=3, k=2, n=9, 则不存在面值组合，因此，为0种方案。
若m=3, k=2, n=6,则有 {1,2,3}，{1,2,4}和{1,3,5}共3种。
若m=3, k=2, n=5, 则不存在，因此，为0种。

关于输入

第1行输入正整数 P, 表示后面有 P行
后面的P行分别为 m,k，n,其间以空格间隔

关于输出

对应输出 P行，若不存在 m 种面值的饭票，则输出0，若有，则输出方案数。
*/
#include <iostream>
using namespace std;

#define MAX_N 1000

/// ac 用于记录达到i所需的最少餐票数ac[i]
/// p  用于存储当前正在尝试的餐票面值组合
int ac[MAX_N] = {0}, p[MAX_N] = {0};
int n = 0, m = 0, k = 0, ans = 0;

/// m  种不同面值的餐票
/// 最多只能使用k张餐票

/// x  当前正在确定第几种餐票的面值
/// mx 表示当前允许的最大餐票面值
void dfs(int x,int mx)
{
	if(mx < 0)
        return;
	if(x > m)
    {
		/// 如果 x > m，表示已经确定了 m 种餐票的面值
		/// 此时检查是否能恰好覆盖到 n
		if(mx == n)
			/// 说明找到了一种满足条件的方案
            ans++;
		return;
	}
    int *tmp = new int[MAX_N];
	for(int i = p[x - 1] + 1;i <= mx + 1; i++)
    {
		p[x] = i;
		/// r 卡最大的票的面值
		int r = min(i * k, n + 1), j = 0;
		for(j = i; j <= r; j++)
		{
			
			tmp[j] = ac[j];
			/// 计算出凑出数值 j 所需的最少餐票数
			ac[j] = min(ac[j], ac[j - i] + 1);
		}
		/// 现在凑出 n + 1 用的超过了 k 张票， 说明合法
		if(ac[n + 1] > k)
		{
			
			for(j = i; j <= r + 1; j++)
				if(ac[j] > k)
				{
					/// 
					dfs(x + 1, j - 1);
					break;
				}
		}
		/// back 找不到能符合条件的，回溯
		for(j = i; j <= r; j++)
            ac[j] = tmp[j];
	}
}

int main()
{
	int t = 0;
	cin >> t;
	while(t--)
    {
		cin >> m >> k >> n;
		/// 初始化，多组数据
		ans = 0;
		/// 最大值
		for(int i = 1; i <= n + 1; i++)
            ac[i] = n + n;
		/// 一块钱全用了
		for(int i = 0; i <= k; i++)
            ac[i]=i;
		/// 第一张票一定是1
		p[1] = 1;
		dfs(2, k);
		cout << ans << endl;
	}
	return 0;
}

