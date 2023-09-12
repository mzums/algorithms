#include <iostream>
using namespace std;

const int MAXN = 1007;
const int MOD = 1e6;
long long arr[MAXN][MAXN], dp[MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    dp[1][1] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 0)
                dp[i][j] += (dp[i-1][j]+dp[i][j-1])%MOD;
        }
    cout << dp[n][n] << endl;
}