# 鹰蛋 - 动态规划的优化
## 题目描述
有一个教授有一批一模一样的鹰蛋。有一天他来到了一栋楼的脚下，他突然想知道自己的鹰蛋从这栋楼的多少层扔下时恰好不碎。
一颗鹰蛋如果从i层摔下没有碎，那么从小于j层摔下也不会碎，如果从j层摔下碎了，从大于j层摔下也会摔碎。如果恰好存在一层n，从n层摔下鹰蛋未碎，而从n+1层摔下碎了，那么这批鹰蛋恰好从n层摔下未碎。如果从第一层摔下碎了，那么称恰好从0层摔下未碎；另一方面，如果从最高层（N层）摔下未碎，那么称恰好从N层摔下未碎
这个教授想知道从第多少层恰好摔下不碎，但是这个教授想使用最少的试验次数来得到这个值。
现已知鹰蛋的个数M和楼层高度N，试问在最坏情况下，这个教授最少需要试验多少次来得到他想要的结果？
比如：M为1，N为3。那么这个教授为了得到结果，就必须从一层一层测试，在最坏情况下，最少需要3次试验。但是如果M=2,N=3，那么他就可以第一次从二层扔下，不管碎了还是没碎，他都只需再扔一次即可得到结果，即需要做2次试验即可。

## 关于输入
有多组输入，每一组输入单独一行。
分别为两个如题所述的正整数N（大于0小于400001），M （大于0小于N+1）中间用空格隔开。
如果得到的N和M都为0，表示输入结束。

## 关于输出
每组输出单独一行，输出需要试验的次数K。

# 题解

## 开始：
一眼区间

n层k次 = max(t层k - 1次， n - t层k次）+ 1的最小值

然后time out 

数据范围！！！！ 40w，需要一个严格O(n)的算法，而上面的算法O(n^2)

40w 二分的化很好处理，蛋最多用19个
但是还不够，还是平方级别

## 观察

max(dp\[t - 1]\[k - 1], dp\[n - t]\[k])中 固定k dp\[x]\[k]单调增加

所以，左边的单调增，右边的单调减，最好的结果应该取在中间某个位置让结果最小

于是进行二分查找

复杂度降到 O（ 20NlogN ）

理论上可以过了

## 蛋是！！！

dp\[h - 1]\[k] <= dp\[h]\[k] <= dp\[h - 1]\[k] + 1

dp[h][k]一定是两者之一！！！

类似
dp\[h - x]\[k] <= dp\[h]\[k] <= dp\[h - x]\[k] + 1

一定有某个x，使得要么dp\[h]\[k](h为变量)在一段上全相等，在个别点+1

于是维护这个x

什么时候不+1?
max(dp\[pre\]\[k\], dp\[h - pre - 1\]\[k - 1\]) + 1 == dp\[h - 1]\[k]时
这里结合dp\[n - 1] <= dp\[n] <= dp\[n - 1] + 1 取等条件理解就可以
加上 dp\[n - 1]\[k] = max(dp\[pre]\[k], dp\[n - 1 - pre -1]) + 1

所以
不等时就是变化的点： pre` = n - 1
dp\[n] = dp\[pre`] + 1

```

#pragma GCC optimize(2)
#include <algorithm>
#include <iostream>

using namespace std;

int dp[400006][21] = {};

int main() {
    cin.tie(0);
    cin.sync_with_stdio(false);

    for (int i = 0; i <= 400001; ++i) {
        dp[i][1] = i;
    }

    for (int i = 2; i <= 20; ++i) {
        int pre = 0;
        dp[1][i] = 1;
        for (int st = 2; st <= 400001; ++st) {
            if (max(dp[pre][i], dp[st - pre - 1][i - 1]) + 1 == dp[st - 1][i]) {
                dp[st][i] = dp[st - 1][i];
            } else {
                dp[st][i] = dp[st - 1][i] + 1;
                pre = st - 1;
            }
        }
    }

    int n, m;

    while (cin >> n >> m) {
        if (n == 0) {
            break;
        }

        if (m > 20) {
            m = 20;
        }
        cout << dp[n][m] << endl;
    }
}

```



