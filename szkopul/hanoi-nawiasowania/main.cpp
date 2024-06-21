#include <iostream>
#include <stack>
using namespace std;

stack<int> one, two, three;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string str, res;
    cin >> str;
    int n = str.size();
    int curr = 0, cnt = 0;
    for (int i = n-1; i >= 0; --i) {
        if (str[i] == '(') one.push(1);
        else one.push(-1);
    }
    while (three.size() != n || curr != 0) {
        if ((one.empty() && two.empty()) || (one.empty() && two.top() + curr > 0)) {
            cout << "NIE\n";
            return 0;
        }
        if (!one.empty() && one.top() + curr <= 0) {
            res += "1 3\n";
            curr += one.top();
            three.push(one.top());
            one.pop();
        }
        else if (!two.empty() && two.top() + curr <= 0) {
            res += "2 3\n";
            curr += two.top();
            three.push(two.top());
            two.pop();
        }
        else if (!one.empty()) {
            res += "1 2\n";
            two.push(one.top());
            one.pop();
        }
        ++cnt;
    }
    cout << cnt << "\n" << res;
}