#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct edge {
    int a, b, c, number;
};

const int MAXN = 1e6+7;
edge G[MAXN];
int anc[MAXN];
int n, m, a, b, c;

bool Sort (const edge &e1, const edge &e2) {
    if (e1.c != e2.c) return e1.c < e2.c;
    return e1.number < e2.number;
}

int Find(int v) {
    if (v == anc[v]) return v;
    else {
        anc[v] = Find(anc[v]);
        return anc[v];
    }
}

void Union(int a, int b) {
    Find(a);
    Find(b);
    anc[anc[a]] = anc[b];
}

int main() {
    int n, m, a, b, c;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) anc[i] = i;
    for (int i = 1; i <= m; ++i) {
        scanf("%d%d%d", &a, &b, &c);
        G[i] = edge{a, b, c+1000*1000*1000, i};
    }
    sort(G+1, G+m+1, Sort);

    int i = 1;
    while (i <= m) {
        edge x = G[i];
        if (Find(x.a) != Find(x.b)) {
            printf("%d\n", x.number);
            Union(x.a, x.b);
        }
        i++;
    }
}