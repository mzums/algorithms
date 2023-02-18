#include <iostream>
using namespace std;

typedef long long ll;
ll p, c, res;
char op;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> p;
    while (cin >> op) {
        cin >> c;
        if (op == '+') res += c;
        else if (op == '*') res *= c;
        else if (op == '-') res -= c;
        else if (op == '/') res /= c;
        if (res < 0) res = res % p + p;
        else res %= p;
    }
    cout << res;
}