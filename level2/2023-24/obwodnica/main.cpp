#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

constexpr int BASE = 1<<19;
constexpr ll INF = 1e18+7;
ll tree[2*BASE], tree2[2*BASE];

void push(int v) {
    if (tree2[v] == 0) return;
    tree[2*v] += tree2[v];
    tree2[2*v] += tree2[v];
    tree[2*v+1] += tree2[v];
    tree2[2*v+1] += tree2[v];
    tree2[v] = 0;
}

void add(int a, int b, int l, int r, int v, int x) {
    if (r < a || b < l) return;
    if (a <= l && r <= b) {
        tree[v] += x;
        tree2[v] += x;
    }
    else {
        push(v);
        add(a, b, l, (l+r)/2, 2*v, x);
        add(a, b, (l+r)/2+1, r, 2*v+1, x);
        tree[v] = min(tree[2*v], tree[2*v+1]);
    }
}

ll query(int a, int b, int l, int r, int v) {
    if (r < a || b < l) return INF;
    if (a <= l && r <= b) return tree[v];
    push(v);
    return min(query(a, b, l, (l+r)/2, 2*v), query(a, b, (l+r)/2+1, r, 2*v+1));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, a, b, c;
    string op;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> op;
        cin >> a >> b;
        --a;
        --b;
        if (op == "budowa") {
            cin >> c;
            if (a <= b)
                add(BASE+a, BASE+b, BASE, 2*BASE-1, 1, c);
            else {
                add(BASE+a, 2*BASE-1, BASE, 2*BASE-1, 1, c);
                add(BASE, BASE+b, BASE, 2*BASE-1, 1, c);
            }
        }
        else {
            if (a <= b)
                cout << query(BASE+a, BASE+b, BASE, 2*BASE-1, 1) << "\n";
            else
                cout << min(query(BASE+a, 2*BASE-1, BASE, 2*BASE-1, 1), query(BASE, BASE+b, BASE, 2*BASE-1, 1)) << "\n";
        }
    }
}