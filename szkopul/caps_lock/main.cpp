#include <iostream>
using namespace std;
typedef long long ll;

const int MOD = 1e9+7;
const int MAXN = 1e6+7;
const int P = 199;
int pow_P[MAXN], H[MAXN];
string text, pattern, ans;
int patternH;

void init(int n, int m) {
    pow_P[0] = 1;
    for (int i = 1; i <= n; i++)
        pow_P[i] = ((ll)pow_P[i-1] * P) % MOD;

    for (int i = 0; i < m; i++)
        patternH = ((ll)patternH + (ll)pattern[i] * pow_P[i]) % MOD;
    patternH = ((ll)patternH * pow_P[n]) % MOD;

    for (int i = 0; i <= n; i++)
        H[i+1] = ((ll)H[i] + (ll)text[i] * (ll)pow_P[i]) % MOD;
}

int get_hash(int l, int r, int n) {
    ++l; ++r;
    int res = (H[r] - H[l-1] + MOD) % MOD;
    return ((ll)res * pow_P[n-l+1]) % MOD;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> text >> pattern;
    ans = text;
    int n = text.length();
    int m = pattern.length();
    init(n, m);

    for (int i = m-1; i < n; i++)
        if (get_hash(i-m+1, i, n) == patternH)
            for (int j = 0; j < m; j++) {
                if (ans[i-j] <= 'Z') break;
                ans[i-j] -= 32;
            }
    cout << ans;
}