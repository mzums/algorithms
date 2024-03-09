#include <iostream>
#include <unordered_map>
#include <cmath>
using namespace std;
typedef long long ll;

ll discreteLogarithm(ll a, ll c, ll p) {
    ll n = sqrt(p) + 1;
    ll an = 1;
    for (ll i = 0; i < n; ++i) {
        an = (an * a) % p;
    }
    unordered_map<ll, ll> values;
    ll curr = an;
    for (ll i = 1; i <= n; ++i) {
        if (!values[curr])
            values[curr] = i;
        curr = (curr * an) % p;
    }
    curr = c;
    ll res = 1e9+7;
    for (ll i = 0; i <= n; ++i) {
        if (values[curr]) {
            ll ans = values[curr] * n - i;
            if (ans < p)
                res = min(res, ans);
        }
        curr = (curr * a) % p;
    }
    if (res != 1e9+7) return res;
    return -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll a, c, p;
    while (cin >> a >> c >> p) {
        cout << discreteLogarithm(a, c, p) << "\n";
    }
}