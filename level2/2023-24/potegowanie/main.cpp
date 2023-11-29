#include <iostream>
using namespace std;
typedef long long ll;

constexpr int MOD = 1e9+7;

int fast_expo(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b % 2 == 1) res = (res * a) % MOD;
        b >>= 1;
        a = (a * a) % MOD;
    }
    return res % MOD;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int q, a, b;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        cin >> a >> b;
        cout << fast_expo(a, b) << "\n";
    }
}