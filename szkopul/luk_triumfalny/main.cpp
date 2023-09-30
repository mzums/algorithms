#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

constexpr int MAXN = 3e5+7;
vector <int> G[MAXN];
int dp[MAXN];
bool visited[MAXN];

void dfs(int v, int x) {
    visited[v] = true;
    dp[v] = 0;

    for (auto u : G[v]) {
        if (visited[u]) continue;
        dfs(u, x);
        dp[v] += dp[u] + 1;
    }
    dp[v] = max(dp[v] - x, 0);
    visited[v] = false;
}

int bs(int r) {
    int l = 0, mid;
    while (l < r) {
        mid = (l + r) / 2;
        dfs(1, mid);
        if (dp[1] == 0) r = mid;
        else l = mid + 1;
    }
    return l;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, a, b;
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    cout << bs(n);
}