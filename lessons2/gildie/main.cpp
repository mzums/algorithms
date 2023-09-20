#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 2e5+5;
vector <int> G[MAXN];
int visited[MAXN], guild[MAXN];

void DFS(int v) {
    visited[v] = true;
    for (auto u : G[v])
        if (!visited[u]) {
            guild[u] = (guild[v] + 1) % 2;
            DFS(u);
        }
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
    for (int i = 1; i <= n; i++) {
        if (G[i].empty()) {
            cout << "NIE";
            return 0;
        }
        DFS(i);
    }
    cout << "TAK\n";
    for (int i = 1; i <= n; i++) {
        if (guild[i]) cout << "K\n";
        else cout << "S\n";
    }
}