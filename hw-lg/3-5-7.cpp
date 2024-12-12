#include <iostream>


using namespace std;

const int INF = 0x0fffffff;
const int N = 105;
int diff[N] = {}; ///////////// !!!
int dp[N][N];

int main() {

    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> diff[i];
        diff[i] += diff[i - 1];
    }

   


   
    for (int len = 2; len <= n; ++len) {
        for (int i = 1; i + len - 1 <= n; ++i) {
            int j = i + len - 1;
            dp[i][j] = INF;
            for (int k = i; k < j; ++k) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + diff[j] - diff[i - 1]);
            }
        }
    }

    cout << dp[1][n];
    


    return 0;
}
