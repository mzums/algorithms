#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q, a, b;
    string str;
    char op;
    cin >> n >> q;
    cin >> str;
    for (int i = 0; i < q; ++i) {
        cin >> op >> a >> b;
        ll x = 0;
        if (op == '=') {
            str[a] = char(b + 48);
        }
        else {
            for (int j = a; j <= b; ++j) {
                x += (ll)(str[j] - 48) * (ll)pow(10, b-j);
            }
            cout << x % 11 << "\n";
        }
    }
}