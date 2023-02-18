#include <iostream>
using namespace std;

const int MAXN = 1e6+7;
long long arr[MAXN], dp[MAXN], pref1[MAXN], pref2[MAXN], maxx1[MAXN], maxx2[MAXN];
long long n, max1=-1e18, max2=-1e18;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        dp[i] = max(dp[i-1]+arr[i], arr[i]);
        pref1[i] = pref1[i-1] + arr[i];
        maxx1[i] = max(maxx1[i-1], pref1[i]);
        max1 = max(max1, dp[i]);
    }
    for (int i = n; i >= 1; i--) {
        pref2[i] = pref2[i+1] + arr[i];
        maxx2[i] = max(maxx2[i+1], pref2[i]);
    }
    for (int i = 1; i <= n; i++)
        max2 = max(max2, maxx1[i]+maxx2[i+1]);

    if (max(max1, max2) > 0)  cout << max(max1, max2);
    else {
        for (int i = 1; i <= n; i++)
            max1 = max(arr[i], max1);
        cout << max1;
    }
}
