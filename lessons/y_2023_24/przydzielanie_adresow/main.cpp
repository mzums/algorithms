#include <iostream>
#include <set>
using namespace std;
typedef long long ll;

constexpr int MAXN = 1e5+7;
constexpr int P = 2141, P2 = 1523;
constexpr int MOD = 1e9+7;
int H[MAXN], H2[MAXN], H3[MAXN], H4[MAXN], powP[MAXN], powP2[MAXN];
string pat[MAXN];
set<int> s, s2;

int get_hash(int l, int r, int n, int* Hx, int* powPx) {
    int res = ((ll)Hx[r] - Hx[l-1] + MOD) % MOD;
    return ((ll)res * powPx[n-l+1]) % MOD;
}

void solve(int k, int n) {
    for (int i = 0; i < k; ++i) {
        cin >> pat[i];
        pat[i] = ' ' + pat[i];
    }
    int m = pat[0].length();

    for (int i = m-1; i <= n; ++i) {
        s.insert(get_hash(i-m+2, i, n, H, powP));
        s2.insert(get_hash(i-m+2, i, n, H3, powP2));
    }
    for (int i = 0; i < k; ++i) {
        for (int j = 1; j < m; ++j) {
            H2[j] = ((ll)H2[j-1] + (ll)powP[j] * pat[i][j]) % MOD;
            H4[j] = ((ll)H4[j-1] + (ll)powP2[j] * pat[i][j]) % MOD;
        }
        if (s.find(get_hash(1, m-1, n, H2, powP)) != s.end()
        && s2.find(get_hash(1, m-1, n, H4, powP2)) != s2.end()) cout << "OK\n";
        else cout << "NIE\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string str;
    int n, t, k;
    cin >> str;

    str = ' ' + str;
    n = str.length() - 1;
    powP[0] = 1;
    powP2[0] = 1;

    for (int i = 1; i <= n; ++i) {
        powP[i] = ((ll)powP[i-1] * P) % MOD;
        powP2[i] = ((ll)powP2[i-1] * P2) % MOD;
        H[i] = ((ll)H[i-1] + (ll)powP[i] * str[i]) % MOD;
        H3[i] = ((ll)H3[i-1] + (ll)powP2[i] * str[i]) % MOD;
    }
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cin >> k;
        solve(k, n);
    }
}
