#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int LOG = 20;
const int MAXN = 5e5+7;

struct Info {
    vector<int> kra;
    int order;
    int maxOrder;
    int prz[LOG+1];
    long long h;
};

Info graf[MAXN];
int maxx[MAXN], minn[MAXN];
int t = 0;

void dfs(int v, int p) {
    graf[v].order = ++t;
    graf[v].prz[0] = p;
    for (int k = 1; k <= LOG; k++)
        graf[v].prz[k] = graf[graf[v].prz[k - 1]].prz[k - 1];

    for (int u : graf[v].kra)
        if (u != p) {
            maxx[u] = max(maxx[v], (int)graf[u].kra.size()+1);
            minn[u] = min(minn[v], (int)graf[u].kra.size()+1);
            graf[u].h = graf[v].h + 1;
            dfs(u, v);
        }
    graf[v].maxOrder = t;
}

bool czy_poddrzewo(int a, int b) {
    return (graf[a].order <= graf[b].order) && (graf[b].maxOrder <= graf[a].maxOrder);
}

int lca(int a, int b) {
    if (czy_poddrzewo(b, a)) return b;
    
    for (int k = LOG; k >= 0; k--)
        if (!czy_poddrzewo(graf[b].prz[k], a))
            b = graf[b].prz[k];

    return graf[b].prz[0];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, a, b;
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> a;
        graf[a].kra.push_back(i);
    }
    minn[0] = graf[0].kra.size()+1;
    maxx[0] = graf[0].kra.size()+1;
    dfs(0, 0);

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        int c = lca(graf[a].prz[0], graf[b].prz[0]);
        cout << minn[c] << " " << maxx[c] << "\n";
    }
}
