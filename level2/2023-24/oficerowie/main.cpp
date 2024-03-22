#include <iostream>
#include <vector>
using namespace std;

constexpr int MAXN = 1e5+7;
vector<int> G[MAXN];
int subtree_size[MAXN], depth[MAXN];
bool centroid_removed[MAXN];

void dfs(int v, int p) {
    subtree_size[v] = 1;
    for (int u : G[v]) {
        if (u == p || centroid_removed[u]) continue;
        dfs(u, v);
        subtree_size[v] += subtree_size[u];
    }
}

int find_centroid(int v, int p, int n) {
    for (int u : G[v]) {
        if (u == p || centroid_removed[u]) continue;
        if (subtree_size[u] * 2 > n) return find_centroid(u, v, n);
    }
    return v;
}

void decompose(int v, int degree) {
    dfs(v, -1);
    int centroid = find_centroid(v, -1, subtree_size[v]);
    depth[centroid] = degree;
    centroid_removed[centroid] = true;

    for (int u : G[centroid])
        if (!centroid_removed[u])
            decompose(u, degree + 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, a, b;
    cin >> n;
    for (int i = 0; i < n-1; ++i) {
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(1, -1);
    decompose(1, 0);
    for (int i = 1; i <= n; ++i)
        cout << char('A' + depth[i]) << ' ';
}
