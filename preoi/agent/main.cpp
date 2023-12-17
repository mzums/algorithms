#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef unsigned long long ull;

constexpr int MAXN = 20, INF = -2e9;
ull arr[MAXN][MAXN], dp[MAXN][MAXN];
ull path, cnt, k;

void findPaths(int i, int j, int n, int m) {
    if (i == n && j == m) {
        path ^= arr[i][j];
        if (path == k) ++cnt;
        path ^= arr[i][j];
        return;
    }
    if (i <= 0 || i > n || j <= 0 || j > m) return;
    path ^= arr[i][j];
    if (j + 1 <= m)
        findPaths(i, j + 1, n, m);
    if (i + 1 <= n)
        findPaths(i + 1, j, n, m);
 
    path ^= arr[i][j];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> arr[i][j];
    findPaths(1, 1, n, m);
    cout << cnt;
}