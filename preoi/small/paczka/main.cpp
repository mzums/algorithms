#include <iostream>
#include <algorithm>
using namespace std;

constexpr int MAXN = 2e5+7, INF = -2e9;
int arr[MAXN];
pair<int, int> dp[MAXN];

void solve() {
    int n;
    cin >> n;
    int maxx = INF;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
        if ((arr[i]+MAXN) % 2 == (arr[i-1]+MAXN) % 2)
            dp[i].first = arr[i];
        else
            dp[i].first = max(dp[i-1].first, dp[i-1].second) + arr[i];
        dp[i].second = arr[i];
        maxx = max(maxx, dp[i].first);
        maxx = max(maxx, dp[i].second);
    }
    cout << maxx << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; 
    cin >> t;
    while (t--) {
        solve();
    }
}