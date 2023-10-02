#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

vector <ll> prime_factors;

void factorize(ll n) {
    for (ll d = 2; d * d <= n; ++d) {
        if (n % d == 0)
            prime_factors.push_back(d);
        while (n % d == 0) n /= d;
    }
    if (n > 1) prime_factors.push_back(n);
}

ll num_from_mask(ll mask) {
    ll res = 1;
    for (size_t i = 0; i < prime_factors.size(); ++i)
        if ((mask >> i) & 1)
            res *= prime_factors[i];
    return res;
}

ll cnt_primes(ll limit) {
    ll other = 0;
    for (ll mask = 1; mask < (1 << prime_factors.size()); ++mask)
        if (__builtin_popcount(mask) & 1)
            other += limit / num_from_mask(mask);
        else
            other -= limit / num_from_mask(mask);
    return limit - other;
}

ll bs(ll l, ll r, ll k) {
    while (l <= r) {
        ll mid = (l + r) / 2;
        if (cnt_primes(mid) >= k) r = mid - 1;
        else l = mid + 1;
    }
    return l;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, k, c, cnt=0;
    cin >> n >> k >> c;

    factorize(n);
    ll curr = bs(1, 1e18, k);
    while (cnt < c) {
        if (__gcd(n, curr) == 1) {
            cout << curr << ' ';
            ++cnt;
        }
        ++curr;
    }
}