#include <iostream>
#include <vector>
using namespace std;

constexpr int MAXN = 2e5+7;
vector<int>G[MAXN];
bool visited[MAXN], visited2[MAXN];
int colors[MAXN];

void dfs(int v, int n, int x) {
    visited[v] = 1;
    colors[v] = x;
    for (auto u : G[v])
        if (!visited[u]) dfs(u, n, x);
}

bool check(int n) {
    for (int i = 1; i <= n; ++i)
        if (colors[i] == colors[i+n] && colors[i] != 0)
            return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n, m, x, y;
    char op;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 1; i <= 2*n; ++i) {
            visited[i] = 0;
            colors[i] = 0;
        }
        for (auto& v : G) v.clear();

        for (int i = 0; i < m; ++i) {
            cin >> x >> y >> op;
            if (op == 'A') {
                G[x].push_back(y);
                G[y].push_back(x);
                G[x+n].push_back(y+n);
                G[y+n].push_back(x+n);
            }
            else {
                G[x].push_back(y+n);
                G[x+n].push_back(y);
                G[y].push_back(x+n);
                G[y+n].push_back(x);
            }
        }
        for (int i = 2; i <= n; ++i)
            if (!visited[i]) dfs(i, n, i);

        if (check(n)) cout << "TAK\n";
        else cout << "NIE\n";
    }
}