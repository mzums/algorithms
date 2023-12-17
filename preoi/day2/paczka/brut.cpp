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
    for (int i = 1; i <= n; ++i) cin >> arr[i];

    for (int i = 1; i <= n; ++i) {
        int res = 0;
        for (int j = i; j <= n; ++j) {
            if ((arr[j]+MAXN) % 2 == (arr[j-1]+MAXN) % 2) res = arr[j];
            else res += arr[j];
            maxx = max(maxx, res);
        }
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