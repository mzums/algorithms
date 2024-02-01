#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int LOG = 20;
const int MAXN = 1e6+7;

struct Point {
    vector <int> edges;
    int order, maxOrder;
    int anc[LOG+1];
};
Point G[MAXN];
int c;

void dfs(int v, int p) {
    G[v].order = ++c;
    G[v].anc[0] = p;
    for (int i = 1; i <= LOG; i++)
        G[v].anc[i] = G[G[v].anc[i-1]].anc[i-1];
    
    for (int u : G[v].edges)
        if (u != p) dfs(u, v);

    G[v].maxOrder = c;
}

bool subtree(int a, int b) {
    return (G[a].order <= G[b].order) && (G[b].maxOrder <= G[a].maxOrder);
}

int lca(int a, int b) {
    if (subtree(b, a)) return b;
    
    for (int i = LOG; i >= 0; i--)
        if (!subtree(G[b].anc[i], a))
            b = G[b].anc[i];

    return G[b].anc[0];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, a, b;
    cin >> n >> m;
    for (int i = 2; i <= n; i++) {
        cin >> a;
        G[a].edges.push_back(i);
    }
    dfs(1, 1);

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        cout << lca(a, b) << "\n";
    }
}