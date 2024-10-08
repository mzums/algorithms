#include <iostream>
#include <algorithm>
using namespace std;

constexpr int MAXN = 507, MAXL = 2e4+7, INF = 1e9+7;
string arr[MAXN];
int dp[MAXN][MAXL];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, l;
    cin >> n >> l;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    for (int i = 0; i < n-1; ++i) {
        dp[i][l] = INF;
        for (int j = l-1; j >= 0; --j) {
            if (arr[i][j] > arr[i+1][j]) {
                dp[i][j] = INF;
            }
            else if (arr[i][j] == arr[i+1][j]) {
                dp[i][j] = dp[i][j+1] + 1;
            }
            else {
                dp[i][j] = 1;
            }
        }
    }
    int res = INF, res2 = 0;
    for (int i = 0; i < l; ++i) {
        int minn = 0;
        for (int j = 0; j < n-1; ++j) {
            minn = max(minn, dp[j][i]);
        }
        if (minn < res) {
            res = minn;
            res2 = i;
        }
    }
    cout << res2+1 << " " << res+res2 << "\n";
}