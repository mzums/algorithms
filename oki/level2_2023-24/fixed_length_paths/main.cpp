#include <iostream>
#include <vector>
using namespace std;

constexpr int MAXN = 2e5+7;
vector<int> G[MAXN];
int subtree_sizes[MAXN], cnt[MAXN];
bool centroid_removed[MAXN];
int max_depth, k;
long long ans;

int dfs(int v, int p) {
    subtree_sizes[v] = 1;
    for (int u : G[v]) {
        if (u == p || centroid_removed[u]) continue;
        subtree_sizes[v] += dfs(u, v);
    }
    return subtree_sizes[v];
}

int get_centroid(int v, int p, int n) {
    for (int u : G[v])
        if (!centroid_removed[u] && u != p && subtree_sizes[u] > n/2)
            return get_centroid(u, v, n);
    return v;
}

void get_cnt(int v, int p, bool filling, int d) {
    if (d > k) return;
    max_depth = max(max_depth, d);
    if (filling) ++cnt[d];
    else ans += cnt[k-d];
    for (int u : G[v])
        if (!centroid_removed[u] && u != p)
            get_cnt(u, v, filling, d+1);
}

void decompose(int v) {
    int centroid = get_centroid(v, 0, dfs(v, 0));
    centroid_removed[centroid] = true;
    max_depth = 0;

    for (int u : G[centroid])
        if (!centroid_removed[u]) {
            get_cnt(u, centroid, false, 1);
            get_cnt(u, centroid, true, 1);
        }
    fill(cnt + 1, cnt + max_depth + 1, 0);
    for (int u : G[centroid])
        if (!centroid_removed[u])
            decompose(u);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, a, b;
    cin >> n >> k;
    for (int i = 1; i < n; ++i) {
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    cnt[0] = 1;
    decompose(1);
    cout << ans << '\n';
}