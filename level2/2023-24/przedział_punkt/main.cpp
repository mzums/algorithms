#include <iostream>
using namespace std;
typedef long long ll;

constexpr int BASE = 1 << 17, MOD = 1e9 + 7;
int tree[(BASE << 1) + 2];

void upd(int a, int b, int l, int r, int v, int x) {
    if (r < a || b < l) return;
    if (a <= l && r <= b)
        tree[v] = ((ll)tree[v] * (ll)x) % MOD;
    else {
        int mid = (l + r) / 2;
        upd(a, b, l, mid, 2 * v, x);
        upd(a, b, mid + 1, r, 2 * v + 1, x);
    }
}

int query(int v) {
    ll res = 1;
    v += BASE;
    while (v > 0) {
        res = (res * tree[v]) % MOD;
        v >>= 1;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 1; i < 2 * BASE + 2; ++i) tree[i] = 1;
    int q, op, a, b, c;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        cin >> op;
        if (op == 0) {
            cin >> a >> b >> c;
            upd(a, b, 0, BASE-1, 1, c);
        }
        else {
            cin >> a;
            cout << query(a) << "\n";
        }
    }
}
