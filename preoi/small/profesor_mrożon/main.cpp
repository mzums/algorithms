#include <iostream>
#include <vector>
using namespace std;

constexpr int MAXN = 2e5 + 7;
vector<pair<int, bool>> G[MAXN];
int state[MAXN];
bool visited[MAXN];
bool bad;

void dfs(int v, int p) {
    visited[v] = true;
    for (auto [u, op] : G[v]) {
        if (u == p) continue;
        if (visited[u] && (state[u] != (state[v] ^ op)))
            bad = 1;
        state[u] = state[v] ^ op;
        if (!visited[u]) dfs(u, v);
    }
}

void solve() {
    int n, m, a, b;
    char op;
    bad = 0;

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        visited[i] = false;
        state[i] = 0;
        G[i].clear();
    }
    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> op;
        bool opp = (op == 'B');
        G[a].push_back({b, opp});
        G[b].push_back({a, opp});
    }
    for (int i = 1; i <= n; ++i)
        if (!visited[i]) 
            dfs(i, 0);
    
    if (bad) cout << "NIE\n";
    else cout << "TAK\n";
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
