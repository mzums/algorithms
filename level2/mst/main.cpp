#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

constexpr int maxn = 1e6+7;
int ojc[maxn];

struct edge {
    int a;
    int b;
    int c;
    int number;
};

int Find(int v) {
    if (v == ojc[v])
        return v;
    else {
        ojc[v] = Find(ojc[v]);
        return ojc[v];
    }
}

void Union(int a, int b) {
    Find(a);
    Find(b);
    ojc[ojc[a]] = ojc[b];
}

bool Sort (const edge &e1, const edge &e2) {
    if (e1.c != e2.c) return e1.c > e2.c;
    return e1.number > e2.number;
}

int main() {
    int n, m, a, b, c;
    scanf("%d%d", &n, &m);
    vector<edge> v(4);
    for (int i = 1; i <= n; ++i) ojc[i] = i;
    for (int i = 1; i <= m; ++i) {
        scanf("%d%d%d", &a, &b, &c);
        v.push_back(edge{a, b, c+1000*1000*1000, i});
    }
    sort(v.begin(), v.end(), Sort);

    int i = v.size();
    while (i > 0) {
        edge x = v.back();
        v.pop_back();
        if (Find(x.a) != Find(x.b)) {
            cout << x.number << "\n";
            Union(x.a, x.b);
        }
        i--;
    }
}