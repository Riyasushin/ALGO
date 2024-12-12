#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> qq;
    for (int i = 0, temp; i < n; ++i)  
    {
        cin >> temp;
        qq.push(temp);
    }
    int cost = 0;
    while (qq.size() > 1) {
        int a = qq.top();
        qq.pop();
        int b = qq.top();
        qq.pop();
        qq.push(a + b);
        cost += a + b;
    }
    cout << cost << endl;
        
}