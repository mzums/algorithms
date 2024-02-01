#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef long long ll;

constexpr int MAXN=5e5+7;
constexpr ll INF=1e18+7;
vector<pair<int, int>> G[MAXN];
ll dist[MAXN];

void dijkstra(int v) {
    priority_queue<pair<int, int>> q;
    q.push({dist[v], v});
    while (!q.empty()) {
        v = q.top().second;
        q.pop();
        for (int i = 0; i < G[v].size(); ++i) {
            int u = G[v][i].first;
            if (dist[v]+G[v][i].second < dist[u]) {
                dist[u] = dist[v]+G[v][i].second;
                q.push({-dist[u], u});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, a, b, w;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> w;
        G[a].push_back({b, w});
        G[b].push_back({a, w});
    }
    for (int i = 2; i <= n; ++i) dist[i] = INF;
    dijkstra(1);
    for (int i = 1; i <= n; ++i) cout << ((dist[i]==INF) ? -1 : dist[i]) << "\n";
}