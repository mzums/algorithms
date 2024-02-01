#include <iostream>
#include <vector>
#include <algorithm>
#include "stu2lib.h"
using namespace std;

constexpr int BASE = 1 << 18, INF = 2e9+7;
int tree[2*BASE+1];
int n;

void inicjuj(vector<int> arr) {
    n = arr.size();
    for (int i = 1; i <= 2*BASE; ++i) tree[i] = INF;
    for (int i = BASE; i <= n + BASE; ++i)
        tree[i] = arr[i - BASE];
    for (int i = BASE - 1; i > 0; --i)
        tree[i] = min(tree[2 * i], tree[2 * i + 1]);
}

void change(int v) {
    while (v > 0) {
        v /= 2;
        tree[v] = min(tree[2*v], tree[2*v+1]);
    }
}

int query(int a, int b, int l, int r, int v) {
    if (r < a || b < l) return INF;
    if (a <= l && r <= b) return tree[v];
    int mid = (l + r) / 2;
    return min(query(a, b, l, mid, 2 * v), query(a, b, mid + 1, r, 2 * v + 1));
}

int odpowiedz(int a, int b) {
    return min(min(query(BASE, BASE+a-1, BASE, 2*BASE, 1), query(BASE+b+1, BASE+n, BASE, 2*BASE, 1)), n);
}

void zamien(int a, int b) {
    a += BASE - 1;
    b += BASE - 1;
    swap(tree[a], tree[b]);
    change(a);
    change(b);
}
