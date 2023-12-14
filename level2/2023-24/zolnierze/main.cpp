#include <iostream>
#include <map>
using namespace std;

constexpr int MAXN = 1e5 + 7;
int strengths[MAXN], rep[MAXN];
map<int, map<int, int>> groups;

int Find(int a) {
    if (a != rep[a])
        rep[a] = Find(rep[a]);
    return rep[a];
}

void Union(int a, int b) {
    int x = Find(a);
    int y = Find(b);
    if (x == y) return;
    if (groups[x].size() < groups[y].size()) swap(x, y);

    for (const auto &entry : groups[y])
        groups[x][entry.first] += entry.second;

    groups[y].clear();
    rep[y] = x;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q, a, b;
    char op;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        rep[i] = i;
        cin >> strengths[i];
        groups[i][strengths[i]] = 1;
    }
    for (int i = 1; i <= q; ++i) {
        cin >> op;
        if (op == 'D') {
            cin >> a >> b;
            if (a != b) Union(a, b);
        }
        else if (op == 'Q') {
            cin >> a >> b;
            int x = Find(a);
            cout << (groups.count(x) ? groups[x][b] : 0) << "\n";
        }
    }
}
