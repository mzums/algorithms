#include <iostream>
#include <vector>
using namespace std;

constexpr int MAXN = 3e4+7, LOG = 20;

struct S {
    vector<int> edges;
    int anc[LOG];
    int d, pre, post;
};
S G[MAXN];
int arr[MAXN];
int c;

void dfs(int v, int p) {
    G[v].pre = ++c;
    G[v].anc[0] = p;

    for (int i = 1; i < LOG; ++i)
        G[v].anc[i] = G[G[v].anc[i-1]].anc[i-1];
    
    for (auto u : G[v].edges)
        if (u != p) {
            G[u].d = G[v].d + 1;
            dfs(u, v);
        }
    G[v].post = ++c;
}

bool subtree_check(int a, int b) {
    return (G[a].pre <= G[b].pre && G[b].post <= G[a].post);
}

int lca(int a, int b) {
    if (subtree_check(a, b)) return a;
    if (subtree_check(b, a)) return b;

    for (int i = LOG-1; i >= 0; --i)
        if (!subtree_check(G[b].anc[i], a))
            b = G[b].anc[i];

    return G[b].anc[0];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, a, b, res = 0;
    cin >> n;
    for (int i = 1; i < n; ++i) {
        cin >> a >> b;
        G[a].edges.push_back(b);
        G[b].edges.push_back(a);
    }
    dfs(1, 1);
    arr[0] = 1;
    cin >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> arr[i];
        res += G[arr[i]].d + G[arr[i-1]].d - 2*G[lca(arr[i], arr[i-1])].d;
    }
    cout << res << "\n";
}