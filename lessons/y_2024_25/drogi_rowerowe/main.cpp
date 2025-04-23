#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_set>
using namespace std;

constexpr int MAXN = 1e5+7;
vector<int> G[MAXN], R[MAXN];
bool visited[MAXN];
int component[MAXN];
vector<int> order;

void dfs1(int u) {
    visited[u] = true;
    for (int v : G[u])
        if (!visited[v])
            dfs1(v);
    order.push_back(u);
}

void dfs2(int u, int label) {
    component[u] = label;
    for (int v : R[u])
        if (component[v] == -1)
            dfs2(v, label);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        R[b].push_back(a);
    }

    for (int i = 0; i <= n; ++i) visited[i] = 0;
    for (int i=1; i<=n; i++)
        if (!visited[i])
            dfs1(i);

    reverse(order.begin(), order.end());
    for (int i = 0; i <= n; ++i) component[i] = -1;
    int label = 0;
    for (int u : order)
        if (component[u] == -1)
            dfs2(u, label++);

    vector<int> size_comp(label, 0);
    for (int i=1; i<=n; i++)
        size_comp[component[i]]++;

    vector<unordered_set<int>> cond_G(label);
    for (int u=1; u<=n; u++) {
        for (int v : G[u]) {
            int cu = component[u], cv = component[v];
            if (cu != cv) {
                cond_G[cu].insert(cv);
            }
        }
    }

    vector<int> in_degree(label, 0);
    for (int cu = 0; cu < label; cu++) {
        for (int cv : cond_G[cu]) {
            in_degree[cv]++;
        }
    }

    queue<int> q;
    for (int cu = 0; cu < label; cu++) {
        if (in_degree[cu] == 0) {
            q.push(cu);
        }
    }

    vector<int> topo_order;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topo_order.push_back(u);
        for (int v : cond_G[u]) {
            in_degree[v]--;
            if (in_degree[v] == 0) {
                q.push(v);
            }
        }
    }

    reverse(topo_order.begin(), topo_order.end());

    vector<int> dp(label, 0);
    for (int cu : topo_order) {
        dp[cu] = size_comp[cu];
        for (int cv : cond_G[cu]) {
            dp[cu] += dp[cv];
        }
    }

    for (int i=1; i<=n; i++) {
        cout << dp[component[i]] - 1 << '\n';
    }
}