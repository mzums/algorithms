#include <iostream>
#include <set>
using namespace std;
typedef long long ll;

const int MAXN=1e6+7, P=199, MOD0=1e9+7, MOD1=1e9+9;
int arr[MAXN], h[MAXN][2], r[MAXN][2], powP[P][2];

void init(int n) {
    powP[0][0] = 1; powP[0][1] = 1;
    for (int i = 1; i <= n; i++) {
        powP[i][0] = ((ll)powP[i-1][0] * P) % MOD0;
        powP[i][1] = ((ll)powP[i-1][1] * P) % MOD1;
    }
    for (int i = 1; i <= n; i++) {
        h[i][0] = ((ll)h[i-1][0] + (ll)arr[i] * powP[i][0]) % MOD0;
        h[i][1] = ((ll)h[i-1][1] + (ll)arr[i] * powP[i][1]) % MOD1;
    }
    for (int i = n; i > 0; --i) {
        r[i][0] = ((ll)r[i+1][0] + (ll)arr[i] * powP[i][0]) % MOD0;
        r[i][1] = ((ll)r[i+1][1] + (ll)arr[i] * powP[i][1]) % MOD1;
    }
    /*for (int i = 1; i <= n; i++) cout << powP[i] << " ";
    cout << "\n";
    for (int i = 1; i <= n; i++) cout << h[i] << " ";
    cout << "\n";
    for (int i = 1; i <= n; i++) cout << r[i] << " ";
    cout << "\n";*/
}

pair<int, int> get_hash(int l, int r, int n) {
    pair<int, int> res = { (h[r][0] - h[l-1][0] + MOD0) % MOD0, 
            (h[r][1] - h[l-1][1] + MOD1) % MOD1 };
    return { ((ll)res.first * powP[n-l+1][0]) % MOD0,
            ((ll)res.second * powP[n-l+1][1]) % MOD1 };
}
// zwraca hash odwróconego słowa arr[l...r]
pair<int, int> get_hasr(int l, int r, int n) {
    pair<int, int> res = { (r[l][0] - r[r+1][0] + MOD0) % MOD0,
            (r[l][1] - r[r+1][1] + MOD1) % MOD1 };
    return { ((ll)res.first * powP[r][0]) % MOD0,
            ((ll)res.second * powP[r][1]) % MOD1 };
}

int solve(int k, int n) {
    set<pair<int, int>> s;
    int res = 0;
    for (int i = 1; (i+k-1) <= n; i+=k) {
        pair<int, int> h_res = get_hash(i, i+k-1, n);
        pair<int, int> r_res = get_hasr(i, i+k-1, n);
        if (s.find(h_res) == s.end() && prv_h.find(r_res) == s.end())
            ++res;
        s.insert(h_res);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    init(n);
    for (int i = 1; i <= n; i++) {
        set<int> s;
        for (int j = i; j <= n; j += i) {
            //get_hash(j, j-i);
        }
    }
}