#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

constexpr int MAXN = 1507;
int arr[MAXN];
ll dp[MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    ll ans = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }
    sort(arr+1, arr+n+1);
    arr[n+1] = 100;
    arr[n+2] = 100;
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i) { // x
        for (int j = 0; j < i; ++j) { // y
            ll res = 0;
            int k = 0;
            for (int k = 0; k <= arr[i]-arr[j]; ++k) { // z
                res += dp[arr[j]][k];
            }
            dp[arr[i]][arr[j]] = res;
        }
    }
    for (int i = 0; i <= m; ++i)
        for (int j = 0; j <= m; ++j)
            ans += dp[i][j];
    cout << ans - 1 << '\n';
}