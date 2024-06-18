#include <iostream>
#include <algorithm>
using namespace std;

constexpr int MAXN = 5e5+7;
int arr[MAXN];
int dp[MAXN][2];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    sort(arr+1, arr+n+1);
    for (int i = 1; i <= n; i++) {
        // 0
        if ((dp[i-1][0] < arr[i] && dp[i-1][1] < arr[i]))
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]) + 1;
        else if (dp[i-1][0] < arr[i] || arr[i] == arr[i-1])
            dp[i][0] = dp[i-1][0] + 1;
        else if (dp[i-1][1] < arr[i])
            dp[i][0] = dp[i-1][1] + 1;
        else
            dp[i][0] = arr[i];

        // 1
        dp[i][1] = max(dp[i-1][0], dp[i-1][1]);
    }
    cout << max(dp[n][0], dp[n][1]) << "\n";
}