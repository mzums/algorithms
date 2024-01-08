#include <iostream>
using namespace std;

constexpr int MAXN = 1e6+7;
int arr[MAXN], dp[MAXN], first[MAXN], last[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
        if (first[arr[i]] == 0) first[arr[i]] = i;
        last[arr[i]] = i;
    }
    for (int i = 1; i <= n; ++i)
        if (last[arr[i]] == i)
            dp[i] = max(dp[first[arr[i]]-1]+1, dp[i-1]);
        else dp[i] = dp[i-1];
        
    cout << dp[n];
}