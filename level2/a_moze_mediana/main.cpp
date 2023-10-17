#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 1007;
int arr[MAXN][MAXN], dp[MAXN][MAXN];

bool check (int number, int n) {
    for (int y = 1; y <= n; ++y)
        for (int x = 1; x <= n; ++x)
            dp[y][x] = max(dp[y][x-1], dp[y-1][x]) + (arr[y][x] >= number);
    return dp[n][n] >= n;
}

int bs (int n, int l=1, int r=1e9) {
    while (l < r) {
        int mid = (l+r) / 2;
        if (check(mid, n)) l = mid+1;
        else r = mid;
    }
    return l - 1;
}

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie (0);

    int n, x, y, l=1, r=1e9, mid;
    cin >> n;
    for (y = 1; y <= n; ++y)
        for (x = 1; x <= n; ++x) cin >> arr[y][x];

    cout << bs(n);
}