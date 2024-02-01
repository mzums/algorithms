#include <iostream>
using namespace std;
typedef long long ll;

const int BASE = 1048576;
ll tree[2*BASE+1];

void upd(int a, int b, int c) {
    a += BASE - 1;
    b += BASE + 1;
    while (a/2 != b/2) {
        if (a%2 == 0) tree[a+1] += c;
        if (b%2 == 1) tree[b-1] += c;
        a /= 2;
        b /= 2;        
    }
}

ll query(int v) {
    ll res = 0;
    v += BASE;
    while (v > 0) {
        res += tree[v];
        v /= 2;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m, a, b, c;
    char op;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> op;
        if (op == '+') {
            cin >> a >> b >> c;
            upd(a, b, c);
        }
        else {
            cin >> a;
            cout << query(a) << "\n";
        }
    }
}