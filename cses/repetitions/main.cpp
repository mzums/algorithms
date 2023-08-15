#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string str;
    int maxx=0, act=1;
    cin >> str;
    for (int i = 1; i < str.length(); i++) {
        if (str[i] != str[i-1]) {
            maxx = max(act, maxx);
            act = 0;
        }
        act++;
    }
    maxx = max(act, maxx);
    cout << maxx;
}