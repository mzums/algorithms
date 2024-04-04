#include <iostream>
#include <vector>
#include <queue>
using namespace std;

constexpr int MAXN = 5007;
vector<pair<int, int>> G[2*MAXN];
int dist[2*MAXN];

void dijkstra(int v) {
    priority_queue<pair<int, int>> pq;
    pq.push({0, v});
    while (!pq.empty()) {
        auto [d, v] = pq.top();
        pq.pop();
        for (auto [u, d] : G[v])
            if (dist[u] > dist[v] + d) {
                dist[u] = dist[v] + d;
                pq.push({-dist[u], u});
            }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, a, b, c;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a;
        G[i].push_back({i+MAXN, a/2});
    }
    cin >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> a >> b >> c;
        G[a].push_back({b, c});
        G[a+MAXN].push_back({b+MAXN, c});
    }
    for (int i = 2; i <= n+MAXN; ++i)
        dist[i] = 1e9;
    dijkstra(1);
    cout << dist[1+MAXN];
}