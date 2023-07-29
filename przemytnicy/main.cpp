#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

const int MAXN=1e5+7, INF=2e9+7;
vector <pair<int, int>> G[MAXN];
int prices[MAXN], dist[MAXN][2];

void dijkstra(int n) {
    for (int i = 1; i <= n; i++)
        dist[i][0] = dist[i][1] = INF;

    priority_queue<tuple<int, int, bool>> Q;
    Q.push({0, 1, 0});
    while(Q.size()) {
        auto[d, v, layer] = Q.top();
        Q.pop();

        if (dist[v][layer] <= -d) continue;
        dist[v][layer] = -d;

        if (layer == 0)
            Q.push({-(dist[v][0] + prices[v] / 2), v, 1});

        for (auto [u, w] : G[v])
            if (dist[u][layer] > dist[v][layer] + w)
                Q.push({-(dist[v][layer] + w), u, layer});
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m, a, b, c;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> prices[i];
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        G[a].push_back({b, c});
    }
    dijkstra(n);
    cout << dist[1][1] << " ";
}