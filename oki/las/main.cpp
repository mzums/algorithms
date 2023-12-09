#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

constexpr int MAXN = 1007;
vector<pair<int, int>> G[MAXN][MAXN];
int arr[MAXN][MAXN];
bool ok[MAXN][MAXN], visited[MAXN][MAXN];
int cnt;

void dfs(int v1, int v2) {
    visited[v1][v2] = 1;
    ++cnt;
    for (auto [u1, u2] : G[v1][v2])
        if (!visited[u1][u2] && ok[u1][u2]) {
            dfs(u1, u2);
        }
}

bool check(int n, int x, int k) {
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            visited[i][j] = 0;
            if (arr[i][j] <= x) ok[i][j] = 1;
            else ok[i][j] = 0;
        }
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            cnt = 0;
            if (!visited[i][j] && ok[i][j])
                dfs(i, j);
            if (cnt >= k) return true;
        }
    return false;
}

int bs(int n, int k) {
    int l = 0, r = 1e9;
    while (l < r) {
        int mid = (l + r) / 2;
        if (check(n, mid, k)) 
            r = mid;
        else 
            l = mid + 1;
    }
    return l;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k, maxx;
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> arr[i][j];

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            if (i != 0) G[i][j].push_back({i-1, j});
            if (j != 0) G[i][j].push_back({i, j-1});
            if (i != n-1) G[i][j].push_back({i+1, j});
            if (j != n-1) G[i][j].push_back({i, j+1});
        }
    cout << bs(n, k);
}