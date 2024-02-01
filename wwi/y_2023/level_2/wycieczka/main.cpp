#include <iostream>
using namespace std;
typedef long long ll;

const int MAXN = 1e5+7;
int arr[MAXN];

bool check(ll x, int k, int n) {
    int how_much = 0;
    for (int i = 1; i < n;) {
        ll curr = 0;
        if (x < arr[i]) return 0;
        while (i < n && curr + arr[i] <= x) {
            curr += arr[i];
            i++;
        }
        how_much++;
    }
    return how_much <= k;
}


ll bs(ll l, ll r, int k, int n) {
    ll mid;

    while (l + 1 < r) {
        mid = (l + r) / 2;
        if (check(mid, k, n)) r = mid;
        else l = mid;
    }
    return r;
}



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    for (int i = 1; i < n; i++) cin >> arr[i];
    cout << bs(1, 1e18, k, n);
}