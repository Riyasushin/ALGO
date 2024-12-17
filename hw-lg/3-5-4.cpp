//
// Created by Yasushin Ri on 2024/12/12.
//

#include <iostream>

#include <iomanip>
#include <string>

#define int128 __int128


using namespace std;



__int128 dp[105];
__int128 dfs(int n) {
    if (n == 0)
        return 1;
    /// 少一个base case 导致无限循环导致溢出
    if (n == 1)
        return 2;

    if (dp[n] == 0) {

        dp[n] = dfs(n / 2) * dfs(n - n / 2);
    }
    return dp[n];
}


void print128(__int128 num) {
    if (num < 0) {
        std::cout << "-";
        num = -num;
    }
    if (num == 0) {
        std::cout << "0";
        return;
    }
    int128 temp = num;
    std::string str;
    while (temp > 0) {
        str += (temp % 10) + '0';
        temp /= 10;
    }
    for (int i = str.size() - 1; i >= 0; --i) {
        std::cout << str[i];
    }
}


int main() {
    int n;
    cin >> n;
    __int128 res = dfs(n);

    print128(res);

    return 0;
}
