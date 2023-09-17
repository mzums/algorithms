#include <iostream>
using namespace std;

constexpr int MAXN = 1007;
int dp[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k, price, tasty;
    cin >> n >> k;   
    for (int i = 0; i < n; i++) {
        cin >> price >> tasty;
        for (int j = k; j >= price; j--)
            dp[j] = max(dp[j], dp[j-price] + tasty);
    }
    cout << dp[k];
}