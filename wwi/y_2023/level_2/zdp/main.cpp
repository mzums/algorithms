#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;

const int MAXN = 5e5+7;
const ll INF = 1e15+7;
vector <pair<int, int>> G[MAXN];
ll dist[MAXN];
priority_queue <pair<ll, int>> q;

void dijkstra(int n) {
    for (int i = 2; i <= n; i++) dist[i] = INF;
    q.push({dist[1], 1});
    while (!q.empty()) {
        int v = (q.top()).second;
        q.pop();
        for (int i = 0; i < (int)G[v].size(); i++) {
            int u = G[v][i].first;
            if (dist[u] > dist[v] + G[v][i].second) {
                dist[u] = min(dist[u], dist[v] + G[v][i].second);
                q.push({-dist[u], u});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m, a, b, c;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        G[a].push_back({b, c});
        G[b].push_back({a, c});
    }
    dijkstra(n);
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INF) cout << "-1\n";
        else cout << dist[i] << "\n";
    }
}