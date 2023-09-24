#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

constexpr int MAXN = 2e5+7;
vector <int> G[MAXN];
int dp[MAXN];
int ans;

void dfs(int v, int p) {
    int prv = 0;
    for (auto u : G[v]) {
        if (u == p) continue;
        dfs(u, v);
        dp[v] = max(dp[v], dp[u] + (int)G[v].size() - 2);
        
        ans = max({ans,
            prv + dp[u] + (int)G[v].size() - 2,
            dp[u] + (int)G[v].size() - 1,
        });
        prv = max(prv, dp[u]);
    }
    dp[v] = max(dp[v], (int)G[v].size() - 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, a, b;
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(1, 0);
    cout << ans;
}