#include <iostream>
#include <vector>
#include <queue>
using namespace std;

constexpr int MAXN = 1e6+7;
int rep[MAXN];
priority_queue<pair<pair<int, int>, pair<int, int>>> q;

int Find(int x) {
    if (x == rep[x]) return x;
    rep[x] = Find(rep[x]);
    return rep[x];
}

void Union(int x, int y) {
    x = Find(x);
    y = Find(y);
    if (x == y) return;
    rep[x] = y;
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, a, b, c;
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> a >> b >> c;
        q.push({{-c, i}, {a, b}});
    }
    for (int i = 1; i <= n; ++i) rep[i] = i;
    while (!q.empty()) {
        auto [x, y] = q.top();
        auto [w, no] = x;
        auto [a, b] = y;
        q.pop();
        if (Find(a) == Find(b)) continue;
        Union(a, b);
        cout << no << '\n';
    }
}