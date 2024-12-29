#include <cstdio>
// //
// // Created by Yasushin Ri on 2024/12/29.
// //
//
// #include <iostream>
//
// using namespace std;
// const int N = 1e5 + 6;
// double x0[N], x1[N], x2[N], x3[N], e[N];
//
// int main() {
//
//     int n;
//     cin >> n;
//     double pr;
//     cin >> pr;
//     e[1] = pr;
//     x0[1] = pr;
//     x1[1] = pr;
//     x2[1] = pr;
//     x3[1] = pr;
//     for (int i = 2; i <= n; ++i) {
//         cin >> pr;
//         x0[i] = pr + pr * x0[i - 1];
//         x1[i] = x0[i] + pr * x1[i - 1];
//         x2[i] = x0[i] + pr * x2[i - 1] + 2 * pr * x1[i - 1];
//         x3[i] = x0[i] + pr * x3[i - 1] + 3 * pr * x2[i - 1] + 3 * pr * x2[i - 1];
//
//         e[i] = (1 - pr) * e[i - 1] + x3[i];
//     }
//
//     cout << x3[n] << endl;
//
//
//     return 0;
// }
using namespace std;
double a[100005], b[100005], f[100005], p[100005];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lf", &p[i]);
        a[i] = (a[i - 1] + 1) * p[i];
        b[i] = (b[i - 1] + 2 * a[i - 1] + 1) * p[i];
        f[i] = f[i - 1] + (3 * b[i - 1] + 3 * a[i - 1] + 1) * p[i];
    }
    printf("%.1lf\n", f[n]);
    return 0;
}
