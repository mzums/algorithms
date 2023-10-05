#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;

const int MAXN = 1e5+7;
const ll INF = 1e15+7;
int arr[MAXN];
ll dist[2*MAXN];
vector <pair<int, int>> G[2*MAXN];
priority_queue <pair<ll, int>> q;

void dijkstra(int start, int n) {
    for (int i = 1; i <= MAXN+n; i++) dist[i] = INF;
    dist[start] = 0;
    q.push({0, start});
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

    int n, m, x, y, a, b, c;
    cin >> n >> m >> x >> y;
    if (x == y) {
        cout << 0;
        return 0;
    }
    for (int i = 1; i <= n; i++) cin >> arr[i];
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        G[a].push_back({b, c+arr[a]});
        G[b].push_back({a, c+arr[b]});
        G[a].push_back({b+MAXN, c});
        G[b].push_back({a+MAXN, c});
        G[a+MAXN].push_back({b+MAXN, c+arr[a]});
        G[b+MAXN].push_back({a+MAXN, c+arr[b]});
    }
    dijkstra(x, n);
    if (dist[y+MAXN] != INF) cout << dist[y+MAXN];
    else cout << "NIE";
}