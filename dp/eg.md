[[POI2010] ANT-Antisymmetry - 洛谷](https://www.luogu.com.cn/problem/P3501)

#哈希函数 #string 
根本思路还是hash，理论在[[进制哈希]]

```cpp
#include "iostream"
#include "string"
#include "cctype"
#include "algorithm"

using namespace std;

#define ull unsigned long long

string s, t;
ull p = 131;
const int N = 500002;
ull pp[N];
ull ss[N];
ull tt[N];
int n;

long long bin_search(int x) {

    int l = 0, r = min(x + 1, n - x );
    while (l < r) {
        int mid = (l + r + 1) >> 1;
        ull h1 = ss[x] - ss[x - mid] * pp[ mid];
        ull h2 = tt[x + 1] - tt[x + 1 + mid] * pp[mid];
        if (h1 == h2) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }

    return l;
}

int main() {

    cin >> n;

    cin >> s;
    s = "0" + s;
    t = s;
    int i = 0;
    for ( i = 1; i <= n; ++i) {
        t[i] = (s[i] == '0' ? '1' : '0');
    }
    pp[0] = 1;
    for (i = 1; i <= n; i++) {
        pp[i] = pp[i - 1] * p;
    }
    for (i = 1; i <= n; ++i) {
        ss[i] = ss[i - 1] * p + s[i];/// 1 - n
    }
    for (i = n; i > 0; --i) {
        tt[i] = tt[i + 1] * p + t[i];/// 1 - n
    }

    long long res = 0;
    for (i = 1; i <= n - 1; ++i) {
        res += bin_search(i);
    }

    cout << res;
    return 0;
}

```


法二：KMP
```cpp
#include "iostream"
#include "string"
#include "cctype"
#include "algorithm"

using namespace std;

int Next[1000005] = {};

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

int main() {
    
    int n;
    cin >> n;
    string s;
    cin >> s;
    getNext(s, Next);
    cout << n - Next[n] << endl;
    
    
    return 0;
}


```