#include <iostream>
#include <vector>
#include <queue>
using namespace std;

constexpr int MAXN = 1e6+7;
bool visited[MAXN];
int component[MAXN], edges[MAXN], dp[MAXN], degree[MAXN];
vector<int> G[MAXN], R[MAXN], G2[MAXN];
vector<int> order, sorted;

void dfs(int v) {
    visited[v] = true;
    for (int u : G[v])
        if (!visited[u]) dfs(u);
    order.push_back(v);
}

void ssc(int v, int c) {
    visited[v] = true;
    component[v] = c;
    for (int u : R[v])
        if (!visited[u]) ssc(u, c);
}

void toposort(int c) {
    queue<int> q;
    for (int i = 1; i <= c; ++i)
        if (degree[i] == 0) q.push(i);

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        sorted.push_back(v);
        for (auto u : G2[v]) {
            --degree[u];
            if (degree[u] == 0) q.push(u);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, a, b;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        G[a].push_back(b);
        R[b].push_back(a);
    }
    for (int i = 1; i <= n; ++i)
        if (!visited[i]) dfs(i);
		
    for (int i = 1; i <= n; i++) visited[i] = 0;

    int c = 0;
    for (int i = n; i >= 1; i--)
        if (!visited[order[i]])
            ssc(order[i], ++c);

    for (int i = 1; i <= n; i++)
        for (int u : G[i])
            if (component[i] != component[u]) {
                G2[component[i]].push_back(component[u]);
                degree[component[u]]++;
            }
			else edges[component[i]]++;
    toposort(c);

    for (int i = sorted.size() - 1; i >= 0; i--) {
        dp[sorted[i]] = edges[sorted[i]];
        int maxx = -1;
        for (int u : G2[sorted[i]])
            maxx = max(maxx, dp[u]);
        if (maxx != -1)
            dp[sorted[i]] += maxx + 1;
    }
    for (int i = 1; i <= n; i++)
        cout << dp[component[i]] << "\n";
}