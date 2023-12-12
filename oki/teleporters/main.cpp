#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

constexpr int MAXN = 2e5+7;
pair<int, int> arr[MAXN];
ll pref[MAXN];

int bs(int n, int m, int i) {
    int l = 0, r = n;
    while (l < r) {
        int mid = l + r + 1 >> 1;
        ll t = pref[mid] + arr[i].second;
        if (i <= mid) t -= arr[i].first;
        if (t <= m) l = mid;
        else r = mid - 1;
    }
    return l + (l < i);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n, m, x;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            cin >> x;
            arr[i] = {x + min(i, n + 1 - i), x + i};
        }
        sort(arr + 1, arr + n + 1);
        for (int i = 1; i <= n; i++)
            pref[i] = pref[i - 1] + arr[i].first;

        int res = 0;
        for (int i = 1; i <= n; i++)
            if (arr[i].second <= m)
                res = max(res, bs(n, m, i));

        cout << res << "\n";
    }
}