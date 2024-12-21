#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

const int N = 2e6 + 5;
int dp[N] = {};


int main() {


    string s;
    cin >> s;

    string S = ")";
    for (int i = 0, len = s.length(); i < len; ++i) {
        
        S += "*";
        S += s[i];
    }
    S += "*(";

    int res = 1;
    int R = 0, center = 0;
    for (int i = 1, len = S.length(); i < len; ++i) {

        if (R <= i) {
            dp[i] = 1;
        } else {
            dp[i] = min(dp[center] + center - i, dp[2 * center - i]);
        }

        while (S[i + dp[i]] == S[i - dp[i]]) {
            dp[i]++;
        }
        if (dp[i] + i > R) {
            R = dp[i] + i;
            center = i;
        }
        res = max(res, dp[i] - 1);

    }

    cout << res << endl;
    

    return 0;

}
