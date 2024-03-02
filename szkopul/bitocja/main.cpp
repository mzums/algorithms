#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct S {
    int a, w;
};

constexpr int MAXN = 107;
vector<S> G[MAXN];
priority_queue<pair<int, int>> q;
int dist[MAXN];
bool used[100007];

void dijkstra(int n) {
    q.push({0, 1});
    while (!q.empty()) {
        auto [d, v] = q.top();
        q.pop();
        if (-d >= dist[v]) continue;
        dist[v] = -d;
        for (int i = 0; i < G[v].size(); ++i) {
            int u = G[v][i].a;
            q.push({-(dist[v] + G[v][i].w), u});
        }
    }
}

int main() {
    int n, k, m, a, b, c;
    scanf("%d%d%d", &n, &k, &m);
    for (int i = 1; i <= k; ++i) {
        scanf("%d%d%d", &a, &b, &c);
        G[a].push_back({b, c});
        G[b].push_back({a, c});
    }
    for (int i = 1; i <= n; ++i) dist[i] = 1e9 + 7;
    dijkstra(n);
    for (int i = 1; i <= m; ++i) {
        scanf("%d%d%d", &a, &b, &c);
        int dist1 = dist[n];
        G[a].push_back({b, c});
        G[b].push_back({a, c});
        for (int j = 1; j <= n; ++j) dist[j] = 1e9+7;
        dijkstra(n);
        if (dist[n] >= dist1) {
            G[a].pop_back();
            G[b].pop_back();
        }
        else
            used[i] = 1;
    }
    for (int i = 1; i <= m; ++i) printf("%d\n", used[i]);
}
