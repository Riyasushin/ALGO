#string #最长回文子串


重点是利用回文数的特征进行去重，减少重复计算
$$
TODO：理解其复杂度如何保持O(n)
$$

```cpp

string change(const string s) {
    string token = "";
    token += "$";
    for (size_t i = 0, len = s.size(); i < len; i++) {
        token += "*";
        token += s[i];
    }
    token += "*$";
    
    return token;
    
}
```

```cpp

void manacher(const string s) {
    size_t R = 0, C = 0;
    for (size_t i = 1, len = s.size(); i < len; ++i) {
        if (i < R) {
            dp[i] = min(dp[2 * C - i], int(C + dp[C] - i) ); /// 没事，C没有定义，但是可以用
        } else {
            dp[i] = 1;
            
        }
        while(dp[i] < int(i) && s[i + dp[i]] == s[i - dp[i]])
            dp[i]++;
        
        if (i + dp[i] > R) {
            R = i + dp[i];
            C = i;
        }
    }
}

```

