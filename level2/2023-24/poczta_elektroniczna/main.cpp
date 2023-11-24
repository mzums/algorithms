#include <iostream>
#include <algorithm>
using namespace std;

constexpr int MAXN = 207;
int dp[MAXN][MAXN], arr[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> arr[i];
    for (int i = n-1; i >= 0; --i)
        for (int j = i+1; j < n; ++j) {
            if (arr[i] == arr[j])
                dp[i][j] = max(dp[i][j], dp[i+1][j-1]+1);
            for (int k = i+1; k < j; ++k)
                dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j]);
        }
    cout << n - dp[0][n-1];
}