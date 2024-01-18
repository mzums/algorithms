#include <iostream>
#include <vector>
using namespace std;

struct Edge {
    int a, b, no;
};
constexpr int MAXN = 3e5+7;
bool taken[MAXN];
int rep[MAXN];
vector<Edge> G[MAXN];

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
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> c;
        G[c].push_back({a, b, i});
    }
    for (int i = 1; i <= n; ++i) rep[i] = i;
    for (int i = 1; i <= 1e5; ++i) {
        for (auto [a, b, no] : G[i])
            if (Find(a) != Find(b)) taken[no] = 1;

        for (auto [a, b, no] : G[i])
            if (Find(a) != Find(b)) Union(a, b);
    }
    for (int i = 0; i < m; ++i)
        (taken[i] == 1) ? cout << "TAK\n" : cout << "NIE\n";
}