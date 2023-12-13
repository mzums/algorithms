#include <iostream>
using namespace std;
typedef long long ll;

constexpr int BASE = 1 << 17;
int tree[BASE << 1];

void change(int a, int b) {
    a += BASE;
    tree[a] = b;
    a >>= 1;
    while (a > 0) {
        tree[a] = max(tree[2*a], tree[2*a+1]);
        a >>= 1;
    }
}

int query(int a, int b) {
    a += BASE;
    b += BASE;
    int res = tree[a];
    if (a != b) res = max(res, tree[b]);
    while((a>>1) != (b>>1)) {
        if (a % 2 == 0) {
            res = max(res, tree[a+1]);
            ++a;
        }
        if (b % 2 == 1) {
            res = max(res, tree[b-1]);
            --b;
        }
        a >>= 1;
        b >>= 1;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int q, op, a, b;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        cin >> op >> a >> b;
        if (op == 0) change(a, b);
        else cout << query(a, b) << "\n";
    }
}