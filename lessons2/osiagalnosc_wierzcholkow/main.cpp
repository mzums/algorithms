#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 1e6+7;
bool visited[MAXN];
vector<int> G[MAXN];

void dfs(int v) {
    visited[v] = true;
    for (auto u : G[v])
        if(!visited[u])
            dfs(u);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m, a, b;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(1);
    for (int i = 1; i <= n; i++)
        if (visited[i]) cout << "TAK\n";
        else cout << "NIE\n";
}