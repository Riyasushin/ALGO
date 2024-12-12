//
// Created by Yasushin Ri on 2024/12/12.
//

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <sstream>
#include <iomanip>

using namespace std;

double res;
bool minu;
bool minuTime;
bool hasTime;
bool visDot;
double num;
int times;
int countDot;
string line;

int main() {
    while (cin >> line) {
        if (line[0] == 'q')
            break;

        num = 0.0;
        times = 0;
        hasTime = false;
        minu = false;
        minuTime = false;
        visDot = false;
        countDot = 0;

        for (int i = 0, len = line.length(); i < len; i++) {
            if (line[i] == '+') {

            }
            else if (line[i] == '-' && hasTime == false) {
                minu = true;
            } else if (line[i] == '-' && hasTime == true) {
                minuTime = true;
            } else if (line[i] == '.') {
                visDot = true;
            } else {
                if (line[i] >= '0' && line[i] <= '9') {
                    if (hasTime) {

                        times = times * 10 + (line[i] - '0');
                    } else {
                        num = num * 10 + (line[i] - '0');
                        if (visDot) {
                            countDot++;
                        }
                    }
                } else {
                    hasTime = true;
                }
            }
        }

        if (minu) {
            num = 0 - num;
        }
        if (minuTime) {
            times = 0 - times;
        }
        times -= countDot;

        if (times > 0) {
            for (int i = 0; i < times; ++i) {
                num *= 10;
            }
        } else {
            times = 0 - times;
             for (int i = 0; i < times; ++i) {
                num /= 10;
            }
        }

        cout << fixed << setprecision(6) << num << endl;;
    }
    return 0;
}
