#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;

const int MAXN = 5e5+7;
const ll INF = 1e15+7;;
vector <pair<int, int>> G[MAXN];
ll dist[2*MAXN];
priority_queue <pair<ll, int>> q;

void dijkstra(int v) {
    int u;
    q.push({dist[1], 1});
    while(!q.empty()) {
        v = (q.top()).second;
        q.pop();
        for (int i = 0; i < (int)G[v].size(); i++) {
            u = G[v][i].first;
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

    int n, m, a, b, w, v;
    vector <int> score;
    for (int i = 2; i < MAXN; i++) dist[i] = INF;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> w;
        G[a].push_back({b, w});
        G[b].push_back({a, w});
    }
    dijkstra(1);
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INF) cout << "-1\n";
        else cout << dist[i] << "\n";
    }
}