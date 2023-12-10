#include <iostream>
#include <vector>
#include <queue>
using namespace std;

constexpr int MAXN = 2007, INF = 1e9+7;
char mat[MAXN][MAXN];
int dist[MAXN][MAXN];

void bfs(int n, int m, int r, int c) {
    dist[r][c] = 0;
    deque<pair<int, pair<int, int>>> dq;
    dq.push_front({0, {r, c}});

    while (!dq.empty()) {
        int w = dq.front().first;
        int u = dq.front().second.first;
        int v = dq.front().second.second;
        dq.pop_front();

        if (w > dist[u][v]) continue;
        if (v > 1 && mat[u][v - 1] != '*' && dist[u][v - 1] > dist[u][v] + 1) {
            dist[u][v - 1] = dist[u][v] + 1;
            dq.push_back({dist[u][v - 1], {u, v - 1}});
        }
        if (v < m && mat[u][v + 1] != '*' && dist[u][v + 1] > dist[u][v]) {
            dist[u][v + 1] = dist[u][v];
            dq.push_back({dist[u][v + 1], {u, v + 1}});
        }
        if (u > 1 && mat[u - 1][v] != '*' && dist[u - 1][v] > dist[u][v]) {
            dist[u - 1][v] = dist[u][v];
            dq.push_front({dist[u - 1][v], {u - 1, v}});
        }
        if (u < n && mat[u + 1][v] != '*' && dist[u + 1][v] > dist[u][v]) {
            dist[u + 1][v] = dist[u][v];
            dq.push_front({dist[u + 1][v], {u + 1, v}});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, r, c, x, y, cnt=0;
    cin >> n >> m >> r >> c >> x >> y;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            dist[i][j] = INF;
            cin >> mat[i][j];
        }
    bfs(n, m, r, c);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if(mat[i][j] != '*') {
                int l_d = dist[i][j], r_d = l_d+j-c;
                if(l_d <= x && r_d <= y) cnt++;
            }
    cout << cnt;
}
