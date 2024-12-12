
#include <iostream>
#include <string>
using namespace std;

int main() {
  cin.tie(NULL);
  cin.sync_with_stdio(false);

  string line;
  int n;
  cin >> line >> n;
  // line = "0" + line;
  while (n--) {
    bool hasDel = false;
    string newS = "";
    for (int i = 0, len = line.size(); i < len; ++i) {
      if (i == len - 1) {
        if (hasDel == true) {
          newS += line[i];
        }
      } else {
        if (line[i] > line[i + 1] && hasDel == false) {
          hasDel = true;
        } else {
          newS += line[i];
        }
      }
    }
    line = newS;
  }

  /// 输出的是高精度

  bool lead = true;
  for (int i = 0, len = line.length(); i < len; ++i) {
    if (line[i] != '0') {
      lead = false;
      cout << line[i];
    } else if (line[i] == '0' && lead == false) {
      cout << line[i];
    }
  }
  if (lead == true) {
    cout << "0";
  }

  return 0;
}

/*

# 删数问题

## 题目描述

键盘输入一个高精度的正整数 $n$（不超过 $250$ 位），去掉其中任意 $k$
个数字后剩下的数字按原左右次序将组成一个新的非负整数。编程对给定的 $n$ 和
$k$，寻找一种方案使得剩下的数字组成的新数最小。

## 输入格式

输入两行正整数。

第一行输入一个高精度的正整数 $n$。

第二行输入一个正整数 $k$，表示需要删除的数字个数。

## 输出格式

输出一个整数，最后剩下的最小数。

## 样例 #1

### 样例输入 #1

```
175438
4
```

### 样例输出 #1

```
13
```

## 提示

用 $\operatorname{len}(n)$ 表示 $n$ 的**位数**，保证 $1 \leq k <
\operatorname{len}(n) \leq 250$。
*/