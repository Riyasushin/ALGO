#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string add(const string& num1, const string& num2) {
    string result;
    int i = num1.size() - 1, j = num2.size() - 1;
    int carry = 0;  // 进位
    while (i >= 0 || j >= 0 || carry!= 0) {
        int sum = carry;
        if (i >= 0) sum += num1[i--] - '0';
        if (j >= 0) sum += num2[j--] - '0';
        result.push_back(sum % 10 + '0');
        carry = sum / 10;
    }
    reverse(result.begin(), result.end());
    return result;
}

int main() {
    int n;
    cin >> n;
    string res, stemp;
    cin >> res;
    for (int i = 1; i < n; i++) {
        cin >> stemp;
        res = add(res, stemp);
    }

    cout << res << endl;
    return 0;
}