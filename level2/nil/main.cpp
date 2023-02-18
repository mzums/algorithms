#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
const int MAXN = 1e6+7;
ll dp[MAXN];
int n, u, v;
vector<int> G[MAXN];

void dfs (int v, int p) {
    ll maximum = 0;
    for (auto u : G[v])
        if (u != p) {
            dfs(u, v);
            maximum = max(maximum, dp[u]);
        }
    dp[v] += maximum;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> dp[i];

    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1, 0);
    cout << dp[1];
}