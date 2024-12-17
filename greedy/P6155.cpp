#include <iostream>
using namespace std;

int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    long long x, y;
    cin >> x >> y;
    long long t = x ^ y;
    while (t > 0) {
        t >>= 1, x |= t;
    }
    long long q = 0;
    while (x > 0) {
        x &= x - 1, q++;
    }
    long long r = 0;
    while (y > 0) {
        y &= y - 1, r++;
    }
    printf("%lld\n", max(q, r));
    return 0;
}

// test TODO