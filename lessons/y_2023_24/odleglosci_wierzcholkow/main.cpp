#include <iostream>
#include <queue>
#include <vector>
using namespace std;

constexpr int MAXN = 1e6+7;
vector <int> G[MAXN];
int dist[MAXN];

void BFS(int v) {
    queue <int> Q;
    Q.push(v);

    while (!Q.empty()) {
        int v = Q.front();
        Q.pop();
        for (auto u : G[v])
            if (dist[u] == -1) {
                dist[u] = dist[v]+1;
                Q.push(u);
            }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, a, b;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for (int i = 2; i <= n; i++) dist[i] = -1;
    BFS(1);

    for (int i = 1; i <= n; i++)
        cout << dist[i] << "\n";
}