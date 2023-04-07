#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

const int MAXN = 1e6+7;
vector <int> G[MAXN];
ll dp[MAXN];

void dfs(int v, int p) {
    ll maxx = 0;
    for (auto u : G[v])
        if (u != p) {
            dfs(u, v);
            maxx = max(maxx, dp[u]);
        }
    dp[v] += maxx;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, a, b;
    ll score=0;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> dp[i];
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(1, 0);
    cout << dp[1];
}
