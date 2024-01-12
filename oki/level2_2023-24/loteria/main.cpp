#include <iostream>
using namespace std;

constexpr int MAXN = 2e5+7, MOD = 1e9+9;
int arr[MAXN], dp[MAXN], summ[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> arr[i];
    for (int i = 1; i <= n; ++i) {
        if (arr[i] == 1) dp[i] = 1;
        else dp[i] = summ[arr[i]-1];
        summ[arr[i]] = (summ[arr[i]] + dp[i]) % MOD;
    }
    cout << summ[k];
}