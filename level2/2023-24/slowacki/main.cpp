#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

constexpr int MAXN = 5e5+7, LOG = 19;
struct S {
    vector<pair<int, int>> edges;
    int anc[LOG+1];
    int pre, post;
    ll d;
};
S G[MAXN];
int c;

void dfs(int v, int p) {
    G[v].anc[0] = p;
    G[v].pre = ++c;

    for (int i = 1; i <= LOG; ++i)
        G[v].anc[i] = G[G[v].anc[i - 1]].anc[i - 1];

    for (auto u : G[v].edges)
        if (u.first != p) {
            G[u.first].d = G[v].d + u.second;
            dfs(u.first, v);
        }
    G[v].post = ++c;
}

bool subtree_check(int a, int b) {
    return (G[a].pre <= G[b].pre) && (G[b].post <=G[a].post);
}

int lca(int a, int b) {
    if (subtree_check(a, b)) return a;
    if (subtree_check(b, a)) return b;
    
    for (int i = LOG; i >= 0; --i)
        if (!subtree_check(G[b].anc[i], a))
            b = G[b].anc[i];

    return G[b].anc[0];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, a, b, c;
    cin >> n;
    for (int i = 1; i < n; ++i) {
        cin >> a >> b >> c;
        G[a].edges.push_back({b, c});
        G[b].edges.push_back({a, c});
    }
    dfs(1, 1);
    cin >> a;
    while (a != -1) {
        cin >> b;
        cout << G[a].d + G[b].d - (2 * G[lca(a, b)].d) << "\n";
        cin >> a;
    }
}
