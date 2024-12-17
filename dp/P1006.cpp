#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=100;
/// TODO 为什么 开到100才不会RE？？
int matrix[maxn][maxn];
int F[2*maxn][maxn][maxn];
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int m,n;
    cin >> m >> n;
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++)
            cin >> matrix[i][j];
    memset(F,-1,sizeof(F));//赋初值为-1 (原因在后面）

    F[2][1][1]=0;

    for(int k = 3; k < m + n; k++)
        for(int i = 1; i < n; i++)
            for(int j = i + 1; j <= n; j++)
            {
                int s=F[k][i][j];
                if(F[k-1][i][j]>s)
                    s = F[k-1][i][j];
                if(F[k-1][i-1][j] > s)
                    s = F[k-1][i-1][j];
                if(F[k-1][i][j-1] > s)
                    s = F[k-1][i][j-1];
                if(F[k-1][i-1][j-1] > s)
                    s = F[k-1][i-1][j-1];
                if( s== -1)continue;
                F[k][i][j] = s + matrix[k-i][i] + matrix[k-j][j];
            }
    cout << F[m + n - 1][n - 1][n] << endl;

    return 0;
}