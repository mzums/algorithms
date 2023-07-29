#include <iostream>
using namespace std;

const int MAXN = 1e6+7;
int arr[MAXN], dp[MAXN];
int n, k;
 
int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    for (int i = 1; i <= MAXN; i++) dp[i] = MAXN;
        
    for (int i = 0; i <= n; i++)
        for (int j = arr[i]; j <= k; j++)
            dp[j] = min(dp[j], dp[j-arr[i]]+1);

    if (dp[k] < MAXN) cout << dp[k]; 
    else cout << "NIE";
}