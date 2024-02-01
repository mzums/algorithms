#include <iostream>
using namespace std;
typedef long long ll;

constexpr int MAXN = 2e5 + 7;
int arr[MAXN];

bool check(ll x, int n, int k) {
    int p = n;
    for (int i = 1; i <= k; ++i) {
        while (arr[p] > x) --p;
        x -= p;
    }
    return x <= 0;
}

ll bs(int n, int k) {
    ll l = 0, r = (ll)n*k+1;
    while (l < r) {
        ll mid = (l + r + 1) / 2;
        if (check(mid, n, k)) l = mid;
        else r = mid - 1;
    }
    return l + 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n, k;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 1; i <= n; ++i) cin >> arr[i];
        cout << bs(n, k) << "\n";
    }
}
