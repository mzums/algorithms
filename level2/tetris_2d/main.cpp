#include <iostream>
using namespace std;

const int base = 1 << 20;
int tree[2*base+7];
int tree2[2*base+7];

void push (int v) {
    if (tree2[v] == 0) return;
    tree[2*v] = tree2[v];
    tree2[2*v] = tree2[v];
    tree[2*v+1] = tree2[v];
    tree2[2*v+1] = tree2[v];
    tree2[v] = 0;
}

void add (int a, int b, int l, int r, int v, int x) {
    if (r<a || b<l) return;
    if (a <= l && r <= b) {
        tree[v] = x;
        tree2[v] = x;
    }
    else {
        push(v);
        add(a, b, l, (l+r)/2, 2*v, x);
        add(a, b, (l+r)/2+1, r, 2*v+1, x);
        tree[v] = max(tree[2*v], tree[2*v+1]);
    }
}

int query (int a, int b, int l, int r, int v) {
    if (r<a || b<l) return 0;
    if (a<=l && r<=b) return tree[v];
    push(v);
    return max(query(a, b, l, (l+r)/2, 2*v), query(a, b, (l+r)/2+1, r, 2*v+1));
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int d, n, l, x;
    cin >> d >> n;
    for (int i = 0; i < n; i++) {
        cin >> l >> x;
        add(base+x, base+x+l-1, base, 2*base-1, 1, query(base+x, base+x+l-1, base, 2*base-1, 1)+1);
    }
    cout << query(base, 2*base-1, base, 2*base-1, 1);

    return 0;
}