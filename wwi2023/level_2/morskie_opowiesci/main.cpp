#include <iostream> 
#include <vector>
#include <queue>
using namespace std;

struct Trip {
    int dest, dist, no;
};

int dist[10003];
int ans[1000003];
vector <int> G[10003];
vector <Trip> trips[5003];

void BFS(int start, int n) {
    for (int i = 1; i <= 2*n; i++) dist[i] = -1;
    dist[start] = 0;
    queue <int> q;
    q.push(start);

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto u : G[v])
            if (dist[u] == -1) {
                dist[u] = dist[v] + 1;
                q.push(u);
            }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k, a, b, c;
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        G[a+n].push_back(b);
        G[a].push_back(b+n);
        G[b+n].push_back(a);
        G[b].push_back(a+n);
    }
    for (int i = 1; i <= k; i++) {
        cin >> a >> b >> c;
        trips[a].push_back({b, c, i});
    }
    for (int i = 1; i <= n; i++)
        if ((int)trips[i].size() > 0 && (int)G[i].size() > 0) {
            BFS(i, n);
            for (auto trip : trips[i])
                if (dist[trip.dest + ((trip.dist%2==0) ? 0 : 1) *n] != -1)
                    if (dist[trip.dest + ((trip.dist%2==0) ? 0 : 1) *n] <= trip.dist)
                        ans[trip.no] = true;
        }
    for (int i = 1; i <= k; i++)
        cout << (ans[i] ? "TAK\n" : "NIE\n");
}
