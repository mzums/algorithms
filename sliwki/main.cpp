#include <iostream>
using namespace std;

const int base = 8;
long long tree[2*base+7][7], tree2[2*base+7];
long long n, q, p, c, l, r, k, res, v1;
string op;

void upd(int v, int wart) {
    v += base;
    tree2[v] += wart;
    for (int i = 1; i <= 6; i++) {
        if (tree2[v] % i == 0)
            tree[v][i] = 1;
        else tree[v][i] = 0;
    }
    v /= 2;
    v1 = v;
    for (int i = 1; i <= 6; i++) {
        v = v1;
        while (v > 0) {
            tree[v][i] = tree[2*v][i] + tree[2*v+1][i];
            v /= 2;
        }
    }
}

int query(int a, int b, int x) {
    res = 0;
    a += (base-1);
    b += (base+1);

    while (a/2 != b/2) {
        if (a%2==0) res += tree[a+1][x];
        if (b%2==1) res += tree[b-1][x];
        a /= 2;
        b /= 2;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> q;
    for (int i = 2*base; i > base; i--)
        for (int j = 1; j <= 6; j++) {
            if (tree2[i] % j == 0)
                tree[i][j] = 1;
            else tree[i][j] = 0;
        }

    for (int v = 2*base; v > base; v--) {
        for (int i = 1; i <= 6; i++) {
            v = v1;
            while (v > 0) {
                tree[v][i] = tree[2*v][i] + tree[2*v+1][i];
                v /= 2;
            }
        }
    }
    for (int i = base+1; i <= 2*base; i++) cout << tree[i][2] << " ";
    cout << "\n";
    
    for (int i = 0; i < q; i++) {
        cin >> op;
        if (op == "DODAJ") {
            cin >> p >> c;
            upd(p, c);
        }
        else {
            cin >> l >> r >> k;
            cout << query(l, r, k) << "\n";
        }
    }
}