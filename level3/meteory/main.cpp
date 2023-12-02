#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

struct Interval {
    int l, r, mid;
};
struct Rain {
    int l, r, x;
};

constexpr int MAXN = 3e5+7, BASE = 1 << 20; 
vector <int> countries[MAXN], mid[MAXN];
ll req[MAXN], tree[BASE<<1];
Interval bin[MAXN];
Rain rain[MAXN];

void add(int a, int b, int x) {
    a += BASE - 1;
    b += BASE + 1;
    while (b - a > 1) {
        if (!(a & 1)) tree[a+1] += x;
        if (b & 1) tree[b-1] += x;
        a >>= 1;
        b >>= 1;
    }
}

ll query(int v) {
    ll res = 0;
    v += BASE;
    while (v) {
        res += tree[v];
        v >>= 1;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, a, k;
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> a;
        countries[a].push_back(i);
    }
    for (int i = 1; i <= n; ++i) cin >> req[i];
    cin >> k;
    for (int i = 1; i <= k; ++i) cin >> rain[i].l >> rain[i].r >> rain[i].x;
    for (int i = 1; i <= n; ++i) {
        bin[i] = {1, k+1, (k+2)/2};
        mid[bin[i].mid].push_back(i);
    }
    int to_answer = n;
    while (to_answer) {
        for (int i = 1; i <= k; ++i) {
            if (rain[i].l <= rain[i].r) add(rain[i].l, rain[i].r, rain[i].x);
            else {
                add(rain[i].l, m, rain[i].x);
                add(1, rain[i].r, rain[i].x);
            }
            for (auto country : mid[i]) {
                ll total_rain = 0;
                for (auto station : countries[country]) {
                    total_rain += query(station);
                    if (total_rain >= req[country]) break;
                }
                if (total_rain >= req[country]) bin[country].r = i;
                else bin[country].l = i + 1;
                bin[country].mid = (bin[country].l + bin[country].r) / 2;
                if (bin[country].l == bin[country].r) --to_answer;
                else mid[bin[country].mid].push_back(country);
            }
            mid[i].clear();
        }
        for (int i = 0; i < (BASE<<1); ++i) tree[i] = 0;
    }
    for (int i = 1; i <= n; ++i)
        if (bin[i].l == k+1) cout << "NIE\n";
        else cout << bin[i].l << "\n";
}