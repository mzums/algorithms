#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAXN = 2e5+7;
const int INF = 1e9+7;
int dist[2*MAXN+7];
vector <pair<int, int>> G[2*MAXN+7];

void dijkstra(int n) {
    for (int i = 2; i <= 2*MAXN; i++) dist[i] = INF;
    priority_queue <pair<int, int>> q;
    q.push({1, 1});
    
    while (!q.empty()) {
        auto [d, v] = q.top();
        q.pop();
        for (auto [u, w] : G[v]) {
            if (dist[u] > dist[v] + w) {
                dist[u] = dist[v] + w;
                q.push({-dist[u], u});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 

    int n, m, a, b, c;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        if (c%2 == 0) {
            G[a].push_back({b, c});
            G[b].push_back({a, c});
            G[a+MAXN].push_back({b+MAXN, c});
            G[b+MAXN].push_back({a+MAXN, c});
        }
        else {
            G[a+MAXN].push_back({b, c});
            G[b].push_back({a+MAXN, c});
            G[a].push_back({b+MAXN, c});
            G[b+MAXN].push_back({a, c});
        }
    }
    dijkstra(n);
    cout << ((dist[MAXN+n] == INF) ? 0 : dist[MAXN+n]);
}