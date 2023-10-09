#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

constexpr int MAXN = 1e6+7;
vector <int> G[MAXN];
priority_queue <int> Q;
int dp[MAXN];
pair<int, int> root = {0, 0};

void find_root(int v, int p, int d=0) {
    root = max(root, {d, v});
    for (auto u : G[v])
        if (u != p) find_root(u, v, d+1);
}

void dfs(int v, int p) {
    dp[v] = 1;
    int maxu = 0;
    for (auto u : G[v]) {
        if (u == p) continue;
        dfs(u, v);
        if (dp[u] > dp[maxu]) maxu = u;
    }
    for (auto u : G[v]) {
        if (u == p || u == maxu) continue;
        Q.push(dp[u]);
    }
    dp[v] += dp[maxu];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, l, a, b, res;
    cin >> n >> l;
    for (int i = 1; i < n; ++i) {
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    if (l == 0) {
        cout << 0;
        return 0;
    }
    find_root(1, 0);
    dfs(root.second, root.second);
    res = dp[root.second];
    --l;
    while (l > 0 && !Q.empty()) {
        res += Q.top();
        Q.pop();
        if (!Q.empty()) {
            res += Q.top();
            Q.pop();
            --l;
        }
    }
    cout << res;
}