#include <iostream>
#include <algorithm>
using namespace std;

struct Edge {
    int a, b, c, no;
};
constexpr int MAXN = 1e6+7;
int rep[MAXN];
Edge arr[MAXN];

bool Sort(Edge x, Edge y) {
    return x.c < y.c;
}

int Find(int a) {
    if (a == rep[a]) return a;
    rep[a] = Find(rep[a]);
    return rep[a];
}

void Union(int a, int b) {
    int x = Find(a);
    int y = Find(b);
    if (x == y) return;
    rep[x] = rep[y];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, a, b, c;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i) {
        scanf("%d%d%d", &a, &b, &c);
        arr[i] = {a, b, c, i};
    }
    for (int i = 1; i <= n; ++i)
        rep[i] = i;

    sort(arr+1, arr+m+1, Sort);
    for (int i = 1; i <= m; ++i) {
        Edge x = arr[i];
        if (Find(x.a) != Find(x.b)) {
            printf("%d\n", x.no);
            Union(x.a, x.b);
        }
    }
}
