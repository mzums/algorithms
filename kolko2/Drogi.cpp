#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 1e4+7;
vector <int> G[MAXN], R[MAXN], g[MAXN], order;
bool visited[MAXN];
int sp[MAXN];
int n, m, a, b, color;

void DFS(int x) {
    visited[x] = true;
    for (auto u : G[x])
        if (!visited[u])
            DFS(u);
    order.push_back(x);
}

void SCC(int v, int col) {
    sp[v] = col;
    for (auto u : R[v])
        if(sp[u] == 0)
            SCC(u, col);
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        G[a].push_back(b);
        R[b].push_back(a);
    }
    for (int i = 1; i <= n; i++)
        if (!visited[a])
            DFS(i);

    for (int i = order.size()-1; i >= 0; i--)
        if (sp[order[i]] == 0)
            SCC(order[i], ++color);

    cout << color << "\n";
    for (int i = 1; i <= n; i++)
        cout << sp[i] << " ";
    cout << "\n";

    for (int i = 1; i <= n; i++)
        for (auto u : G[i])
            if(sp[u] != sp[i]) {
                cout << sp[i] << " " << sp[u] << "\n";
                g[sp[i]].push_back(sp[u]);
            }
}