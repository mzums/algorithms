#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

constexpr int MAXN = 2e5+7;
vector<int> G[MAXN];
int subtree_sizes[MAXN], min_dist[MAXN];
bool centroid_removed[MAXN];
vector<pair<int, int>> ancestors[MAXN];

void dfs(int v, int p) {
    subtree_sizes[v] = 1;
    for (auto u : G[v]) {
        if (u == p || centroid_removed[u]) continue;
        dfs(u, v);
        subtree_sizes[v] += subtree_sizes[u];
    }
}

int find_centroid(int v, int p, int n) {
    for (int u : G[v]) {
        if (u == p || centroid_removed[u]) continue;
        if (subtree_sizes[u] > n/2) return find_centroid(u, v, n);
    }
    return v;
}

void get_dists(int v, int c, int p, int d) {
    for (int u : G[v]) {
        if (u == p || centroid_removed[u]) continue;
        ++d;
        get_dists(u, c, v, d);
        --d;
    }
    ancestors[v].push_back({c, d});
}

int decompose(int v) {
    dfs(v, -1);
    int centroid = find_centroid(v, -1, subtree_sizes[v]);
    centroid_removed[centroid] = true;

    for (int u : G[centroid])
        if (!centroid_removed[u])
            get_dists(u, centroid, centroid, 1);

    for (int u : G[centroid])
        if (!centroid_removed[u])
            int sub_cent = decompose(u);

    return centroid;
}

void update(int v) {
    for (auto [anc, d] : ancestors[v])
        min_dist[anc] = min(min_dist[anc], d);
    min_dist[v] = 0;
}

int query(int v) {
    int ans = min_dist[v];
    for (auto [anc, d] : ancestors[v])
        if (d) ans = min(ans, d + min_dist[anc]);
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, a, b;
    cin >> n >> m;
    for (int i = 1; i < n; ++i) {
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for (int i = 0; i <= n; ++i) min_dist[i] = 1e9+7;
    decompose(1);
    update(1);
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        if (a == 1) update(b);
        else cout << query(b) << '\n';
    }
}