
#string #单模匹配
# 问题
在长度为n的文本S中，找某个长度为m的关键词P，P可能多次出现，都必须找到

# kmp
[[#避免回溯]]
[[#最长公共前后缀]] next[ ] 数组
## 避免回溯
为什么会回溯，一次匹配失败后，下一个从0开始进行匹配
极端情况，最后一个不同其余全相同，效率近乎nm

如果在失信点之前p的字符均不相同，没有必要从i+1进行判断，因为s\[i+1 ] 和 必然与s \[i] 不同，为什么
如果有部分相同，跳到后缀与前缀相同的部分进行处理就行，
所以需要最长公共前后缀

## 最长公共前后缀
$$
下面有一个O（m）级别的求法
$$

动态规划的求法
1.  P\[i] = P\[next\[ i ]] -> next\[i + 1] = next\[i] + 1
2.  P\[i] ≠ P\[next\[ i ]] -> 算吧

```cpp
void getNext(string& p, int* next) {
    next[0] = 0;
    next[1] = 0;
    for (size_t i = 1, len = p.length(); i < len; ++i) {
        int j = next[i];
        while (j && p[i] != p[j]) {
            j = next[j]; //////
        }
        if (p[i] == p[j])
            next[i + 1] = j + 1;
        else
            next[i + 1] = 0;
    }
}
```

为了理解next可以考虑下题
[最短循环节](https://www.luogu.com.cn/record/189020442)
[[eg]]这是题解


# 打个板子
[# P4824 [USACO15FEB] Censoring S](https://www.luogu.com.cn/problem/P4824)
考验的是对i、j指针变化的理解
怎么避免回溯，怎么跳跃指针
其实和dp的思路有异曲同工之处

上代码，重点是kmp函数的j == lent 时候都处理，其他和板子都是大差不差

```cpp
#include "iostream"
#include "string"
#include "cctype"
#include "algorithm"

using namespace std;

const int N = 1e6 + 2;
int cnt = 0;
int st[N];
string s, t;
int Next[N], ss[N];

void getNext(int* next) {
    size_t len = t.length();
    next[0] = 0;
    next[1] = 0;
    for (size_t i = 1; i < len; ++i) {
        int j = next[i];
        while (j && t[j] != t[i]) {
            j = next[j];
        }
        if (t[i] == t[j]) {
            next[i + 1] = j + 1;
        } else {
            next[i + 1] = 0;
        }
    }
}

void kmp() {
    getNext(Next);
    size_t j = 0;
    size_t lent = t.length();
    for (size_t i = 0, len = s.size(); i < len; ++i) {
        st[cnt++] = int(i);
        while (j && s[i] != t[j]) {
            /// 思考这一步
            /// 假设前面是重复的，也就是t[0] ~ t[j - 1] 是匹配成功的 / j = 0 完全不匹配很舒服
            /// 相当于去重，不是从头开始
            ///  原来重复的后缀取最大重复，当成前缀继续用
            ///  j = 0 <=> 完全没有重复的子列
            ///  j ≠ = && s[i] == t[j] <=> 发现了一段重复
            j = Next[j];
        }
        ss[i] = int(j);
        if ( t[j] == s[i] )
            j++;
        if (j == lent) {
            cnt -= lent;
            if (cnt > 0) {
                j = ss[st[cnt-1]] + 1;
            } else {
                j = 0;
            }
        }
    }
}


int main() {
    
    cin >> s >> t;
    kmp();
   
    for (int i = 0; i < cnt; ++i) {
        cout << s[st[i]];
    }
    
    return 0;
}

```