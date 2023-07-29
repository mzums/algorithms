#include <iostream>
using namespace std;

const int MAXN = 1e3+7;
int dp[MAXN];
int n, k, price, tasty;

int main()
{ 
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> price >> tasty;
        for (int j = k; j >= price; --j)
            dp[j] = max(dp[j], dp[j-price]+tasty);
    }
    cout << dp[k];
}