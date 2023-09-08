#include <iostream> 
#include <algorithm>
using namespace std;

const int BASE = 1 << 19;
int tree[2*BASE+7];

void init() {
    for (int i = BASE-1; i >= 1; i--)
        tree[i] = tree[2*i] ^ tree[2*i+1];
}


int query(int a, int b) {
    int result = 0;
    a += BASE - 1;
    b += BASE - 1;
    while (a <= b) {
        if (a % 2 == 1) {
            result ^= tree[a];
            ++a;
        }
        if (b % 2 == 0) {
            result ^= tree[b];
            --b;
        }
        a >>= 1;
        b >>= 1;
    }
    return result;
}

void upd(int x) {
    while (x > 0) {
        tree[x] = tree[2*x] ^ tree[2*x+1];
        x /= 2;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string op;
    int n, q, a, b;
    cin >> n >> q;
    for (int i = 0; i < n; i++) cin >> tree[BASE+i];
    init();
    for (int i = 0; i < q; i++) {
        cin >> op >> a >> b;
        if (op == "czytaj") cout << query(a, b) << "\n";
        else {
            a += BASE - 1;
            b += BASE - 1;
            swap(tree[a], tree[b]);
            upd(a/2);
            upd(b/2);
        }
    }
}