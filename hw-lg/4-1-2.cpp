//
// Created by Yasushin Ri on 2024/12/19.
//

#include <iostream>

using namespace std;


bool isSHAngsheng = true;
long long res = 0;
int tempSum = 0;
int height = 1;
int lastShangsheng = 0;

/// test
int A, B;

int main() {
    int n;
    cin >> A;
    res = 0;
    tempSum = 1;
    lastShangsheng = 0;
    for (int i = 1; i < n; ++i) {
        cin >> B;

        if (A < B) {
            height++;
            tempSum += height;
            lastShangsheng = i;
        } else if (A == B) {
            tempSum += height;
        }



        A = B;
    }
    return 0;
}
