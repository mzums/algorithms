#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 1e5+7;
int height[MAXN], visited[MAXN];
vector <int> G[MAXN];

bool dfs(int v, int x, int n) {
    visited[v] = true;
    if (v == n) return true;

    for (auto u : G[v])
        if (!visited[u] && height[u] <= x)
            if (dfs(u, x, n)) return true;

    return false;
}


int bin(int l, int r, int n){
    int mid;

    while(l + 1 < r){
        for (int i = 0; i <= n; i++) visited[i] = false;
        mid = (l + r)/2;
        if (dfs(1, mid, n)) r = mid;
        else l = mid;
    }
    return r;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m, a, b;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> height[i];
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    cout << bin(1, 1e9, n);
}