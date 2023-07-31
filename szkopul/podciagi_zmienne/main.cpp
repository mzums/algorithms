#include <iostream>
using namespace std;

const int MAXN = 5e5+7, MOD = 1e9+7;
int sum_dp[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, summ=0, a, add;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        add = (summ - sum_dp[a] + MOD + 1) % MOD;
        summ = (summ + add) % MOD;
        sum_dp[a] = (sum_dp[a] + add) % MOD;
    }
    cout << summ;
}