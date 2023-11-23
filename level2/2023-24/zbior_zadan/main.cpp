#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

constexpr int INF = 1e9+7;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, res=0, a;
    cin >> n;
    vector<int> dp(n+1, INF);
    dp[0] = -INF;

    for (int i = 0; i < n; ++i) {
        cin >> a;
        int l = upper_bound(dp.begin(), dp.end(), a) - dp.begin(); // longest ending at arr[i]
        if (dp[l-1] < a && a < dp[l]) dp[l] = a;
    }
    for (int i = 0; i <= n; ++i)
        if (dp[i] < INF) res = i;
    cout << res;
}