#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

constexpr int MAXN = 1007;
ll dp[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, a;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            cin >> a;
            if (i == 1) dp[j] = dp[j-1];
            else if (j != 1) dp[j] = max(dp[j], dp[j-1]);
            dp[j] += a;
        }
    cout << dp[m];
}