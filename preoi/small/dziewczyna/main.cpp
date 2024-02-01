#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

constexpr int MAXN = 1e6+7, P = 127, MOD = 1e9+7;
ll powP[MAXN], H1[MAXN], H2[MAXN];

void init(int n, string str, string str2) {
    powP[0] = 1;
    for (int i = 1; i <= n; ++i) powP[i] = (powP[i-1] * P) % MOD;
    for (int i = 1; i <= n; ++i) {
        H1[i] = (H1[i-1] + powP[i] * str[i]) % MOD;
        H2[i] = (H2[i-1] + powP[i] * str2[i]) % MOD;
    }
}

ll get_hash1 (int l, int r, int n) {
    ll res = (H1[r]-H1[l-1]+MOD) % MOD;
    return ((ll)res*powP[n-l+1]) % MOD;
}
ll get_hash2 (int l, int r, int n) {
    ll res = (H2[r]-H2[l-1]+MOD) % MOD;
    return ((ll)res*powP[n-l+1]) % MOD;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, res = 0;
    string str, str2;
    cin >> n >> str;
    str2 = str;
    reverse(str2.begin(), str2.end());
    str = ' ' + str;
    str2 = ' ' + str2;
    for (int i = 1; i <= n; ++i)
        if (str2[i] == '1') str2[i] = '0';
        else str2[i] = '1';
    init(n, str, str2);

    int k = n - 1;
    for (int i = 1; i < n; ++i) {
        int l = 0, r = min(i, k);
        while (l < r) {
            int j = (l+r)/2;
            if (get_hash1(i-j, i+j, n) == get_hash2(k-j, k+j, n)) l = j+1;
            else r = j;
        }
        res += l;
        --k;
    }
    cout << res;
}