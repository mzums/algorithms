#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

constexpr int MAXN = 1e3+7;
pair <int, int> arr[MAXN];
vector <int> G[MAXN];
bool visited[MAXN];

void dfs(int v) {
    visited[v] = 1;
    for (auto u : G[v])
        if (!visited[u]) dfs(u);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, s, res=0;
    cin >> n >> s;
    for (int i = 0; i < n; ++i) cin >> arr[i].first >> arr[i].second;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            if (j == i) continue;
            double dist = sqrt(pow(abs(arr[i].first - arr[j].first), 2) + pow(abs(arr[i].second - arr[j].second), 2));
            if (dist <= s) G[i].push_back(j);
        }
    dfs(0);
    for (int i = 0; i < n; ++i) if (visited[i]) ++res;
    cout << res;
}
