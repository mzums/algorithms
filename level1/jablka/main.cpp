#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 1e6+7;
int d1[MAXN], d2[MAXN];
vector <int> G[MAXN];

void bfs(int v, int d[]) {
    queue <int> q;
    q.push(v);
    d[v] = 0;

    while (!q.empty()) {
        v = q.front();
        q.pop();
        for (auto u : G[v])
            if (d[u] == -1) {
                d[u] = d[v]+1;
                q.push(u);
            }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, a, b, u, ans=0;
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    fill(d1, d1+n+1, -1);
    bfs(1, d1);
    u = max_element(d1+1, d1+n+1)-d1;
    fill(d2, d2+n+1, -1);
    bfs(u, d2);
    for (int i = 1; i <= n; i++) ans = max(ans, max(d1[i], d2[i]));
    cout << ans << endl;
}