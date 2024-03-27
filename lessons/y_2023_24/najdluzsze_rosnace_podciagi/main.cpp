#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

constexpr int MAXN = 5e5+7;
constexpr int INF = 2e9+7;
vector<pair<int, ll>> G[MAXN];
ll arr[MAXN], dp[MAXN];

int binsearch(int l, int r, int x, int pos) {
    while (l < r) {
        int mid = (l+r)/2;
        if (G[pos][mid].first >= x) l = mid+1;
        else r = mid;
    }
    return l;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> arr[i];

    G[0].push_back({0, 1});
    for (int i = 1; i <= n; ++i) {
        G[i].push_back({INF, 0});
        dp[i] = INF;
    }
    for (int i = 1; i <= n; ++i) {
        int pos = upper_bound(dp, dp+n+1, arr[i]-1) - dp;
        int pos2 = binsearch(0, G[pos-1].size(), arr[i], pos-1);
        dp[pos] = arr[i];
        G[pos].push_back({arr[i], 0});
        ll summ = G[pos-1].back().second;
        if (pos2 != 0) summ -= G[pos-1][pos2-1].second;
        if (G[pos].size() > 1) summ += G[pos][G[pos].size()-2].second;
        G[pos][G[pos].size()-1].second = (summ + 3*m) % m;
    }
    int i = 0;
    while (G[i].back().first != INF) i++;
    cout << G[i-1].back().second << "\n";
}