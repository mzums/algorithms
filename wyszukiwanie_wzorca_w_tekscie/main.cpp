#include <iostream>
using namespace std;

typedef long long ll;
const int MAXN=2e6+7, P=199, MOD=1e9+7;
int powP[MAXN], H[MAXN];
int n, m, pattern, score;
string a, b;

int get_hash (int l, int r, int n) {
    ++l;
    ++r;
    int res = (H[r]-H[l-1]+MOD) % MOD;
    return ((ll)res*powP[n-l+1]) % MOD;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> a >> b;
    n = b.length();
    m = a.length();

    powP[0] = 1;
    for (int i = 1; i <= n; i++)
        powP[i] = ((ll)powP[i-1] * P) % MOD;

    int pattern = 0;
    for (int i = 0; i < m; i++)
        pattern = ((ll)pattern+(ll)powP[i]*a[i]) % MOD;
    pattern = ((ll)pattern * powP[n]) % MOD;

    H[0] = 0;
    for (int i = 0; i < n; i++)
        H[i+1] = ((ll)H[i] + (ll)powP[i]*b[i]) % MOD;

    for (int i = m-1; i < n; i++)
        if (get_hash(i-m+1, i, n) == pattern)
            score++;
    cout << score;
}