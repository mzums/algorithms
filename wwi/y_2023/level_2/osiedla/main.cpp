#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

constexpr int MAXN = 1e6+7;
vector<pair<int, int>> G[MAXN];
vector <int> G2[MAXN], R2[MAXN];
bool visited[MAXN], visited2[MAXN];
vector<int> order;
pair<int, int> arr[MAXN], arr2[MAXN];

void dfs(int v, int p, int w2) {
    if (visited2[w2]) return;
    visited2[w2] = true;
    for (auto [u, w] : G[v]) {
        if (visited2[w]) continue;
        if (w < MAXN) arr2[w] = {v, u};
        G2[v].push_back(u);
        R2[u].push_back(v);
        dfs(u, v, w);
    }
}

void dfs2(int v) {
    visited[v] = 1;
    for (auto u : G2[v])
        if (!visited[u]) dfs2(u);
    order.push_back(v);
}

void dfs3(int v) {
    visited[v] = 1;
    for (auto u : R2[v])
        if (!visited[u]) dfs3(u);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, a, b, res=0;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        arr[i] = {a, b};
        G[a].push_back({b, i});
        G[b].push_back({a, i});
    }
    for (int i = 1; i <= n; ++i)
        if (!visited[i]) dfs(i, 0, i+1000000);

    for (int i = 1; i <= n; ++i) visited[i] = 0;
    for (int i = 1; i <= n; ++i)
        if (!visited[i]) dfs2(i);

    for (int i = 1; i <= n; ++i) visited[i] = 0;
    reverse(order.begin(), order.end());
    
    for (int v : order)
        if (!visited[v]) {
            ++res;
            dfs3(v);
        }
    cout << res << "\n";
    for (int i = 0; i < m; ++i) {
        if (arr[i].first == arr2[i].first && arr[i].second == arr2[i].second) cout << '>';
        else cout << '<';
    }
}