#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

vector<ll> divisors(ll d) {
    vector<ll> divs;
    for (ll i = 1; i * i <= d; ++i) {
        if (d % i == 0) {
            divs.push_back(i);
            if (i != d / i)
                divs.push_back(d / i);
        }
    }
    sort(divs.begin(), divs.end());
    return divs;
}

ll gcd(ll a, ll b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll a, b;
    cin >> a >> b;

    ll d = gcd(a, b);
    vector<ll> common_divisors = divisors(d);

    int n;
    cin >> n;

    while (n--) {
        ll l, r;
        cin >> l >> r;

        auto it = upper_bound(common_divisors.begin(), common_divisors.end(), r);
        if (it == common_divisors.begin()) {
            cout << -1 << "\n";
            continue;
        }
        --it;
        if (*it < l) {
            cout << -1 << "\n";
        } else {
            cout << *it << "\n";
        }
    }
}
