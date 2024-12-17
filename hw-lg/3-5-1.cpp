//
// Created by Yasushin Ri on 2024/12/12.
//

#include <iostream>
#include <algorithm>

using namespace std;
string line[4];
size_t len = 0xee0000;

int main() {
    for (int i = 0; i < 4; ++i) {
        getline(cin, line[i]);
        len = len > line[i].size() ? line[i].size() : len;
    }

    for (size_t i = 0; i < len; ++i) {
        char c = line[0][i];
        bool found = true;
        for (int j = 1; j < 4; ++j) {
            if (c != line[j][i]) {
                found = false;
            }
        }
        if (found) {
            cout << c;
        } else {
            break;
        }
    }

    return 0;
}
