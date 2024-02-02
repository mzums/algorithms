#include <iostream>
#include <algorithm> 
using namespace std;
typedef long long ll;

constexpr int MAXN = 2e5+7, MOD = 1e9+7;
int arr[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, res=0, one = 0, two = 0, onee = 0, twoo = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> arr[i];
    if (n <= 2000) {
        for (int i = 1; i <= n; ++i) {
            int maxx=0, g=arr[i];
            for (int j = i; j <= n; ++j) {
                maxx = max(maxx, arr[j]);
                g = __gcd(g, arr[j]);
                res = (res + ((ll)g * (ll)maxx)) % MOD;
            }
        }
    }
    else {
        for (int i = 1; i <= n; ++i) {
            if (arr[i] == 1) {
                ++one;
                if (arr[i-1] == 2) {
                    if (two == 1) twoo = (twoo + two) % MOD;
                    else twoo = (twoo + (two * (two+1)) / 2) % MOD;
                }
                two = 0;
            }
            else {
                ++two;
                if (arr[i-1] == 1) {
                    if (one == 1) onee = (onee + one) % MOD;
                    else onee = (onee + (one * (one+1)) / 2) % MOD;
                }
                one = 0;
            }
        }
        if (arr[n] == 2) {
            if (two == 1) twoo = (twoo + two) % MOD;
            else twoo = (twoo + (two * (two+1)) / 2) % MOD;
        }
        if (arr[n] == 1) {
            if (one == 1) onee = (onee + one) % MOD;
            else onee = (onee + (one * (one+1)) / 2) % MOD;
        }
        res = (onee + twoo * 4 + (n*(n+1)/2 - onee - twoo) * 2) % MOD;
    }
    cout << res;
}