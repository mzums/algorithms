#include <iostream>
#include <set>
using namespace std;
typedef long long ll;

constexpr int MAXN = 1e5+7;
constexpr int P = 17;
constexpr int MOD = 1e9+7;
int H[MAXN], H2[MAXN], powP[MAXN];
string pat[MAXN];
set<int> s;

int get_hash1(int l, int r, int n) {
    int res = ((ll)H[r] - H[l-1] + MOD) % MOD;
    return ((ll)res * powP[n-l+1]) % MOD;
}

int get_hash2(int l, int r, int n) {
    int res = ((ll)H2[r] - H2[l-1] + MOD) % MOD;
    return ((ll)res * powP[n-l+1]) % MOD;
}

void solve(int k, int n) {
    for (int i = 0; i < k; ++i) {
        cin >> pat[i];
        pat[i] = ' ' + pat[i];
    }
    int m = pat[0].length();

    for (int i = m-1; i <= n; ++i) {
        s.insert(get_hash1(i-m+2, i, n));
    }
    for (int i = 0; i < k; ++i) {
        for (int j = 1; j < m; ++j) {
            H2[j] = ((ll)H2[j-1] + (ll)powP[j] * pat[i][j]) % MOD;
        }
        if (s.find(get_hash2(1, m-1, n)) != s.end()) cout << "OK\n";
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

    for (int i = 1; i <= n; ++i) {
        powP[i] = ((ll)powP[i-1] * P) % MOD;
        H[i] = ((ll)H[i-1] + (ll)powP[i] * str[i]) % MOD;
    }
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cin >> k;
        solve(k, n);
    }
}