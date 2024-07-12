#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    string str, res;
    bool used = false;
    cin >> n >> str;
    str += 'ż';
    for (int i = 0; i < n; ++i) {
        if (int(str[i]) > int(str[i + 1]) && !used) {
            used = 1;
            continue;
        }
        res += str[i];
    }
    cout << res;
}