#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

constexpr int MAXN = 2e5+7;
ll v[MAXN], h[MAXN];

ll check(ll mid, int n) {
    ll res = 0, x = -1;
    for (int y = n; y >= 0; --y) {
        while (x < n && h[x+1]*v[y] < mid) ++x;
        res += n - x;
    }
    return res;
}

ll bs(ll k, int n) {
    ll l = h[0]*v[0], r = h[n]*v[n];
    while (l < r) {
        ll mid = (l+r+1) / 2;
        if (check(mid, n) < k) r = mid - 1;
        else l = mid;
    }
    return l;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll a, b, c, n, k, prev = 0;
    cin >> a >> b >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> c;
        h[i] = c - prev;
        prev = c;
    }
    h[n] = a - prev;
    prev = 0;
    for (int i = 0; i < n; ++i) {
        cin >> c;
        v[i] = c - prev;
        prev = c;
    }
    v[n] = b - prev;
    sort(h, h + n+1);
    sort(v, v + n+1);

    cout << bs(k, n);
}
