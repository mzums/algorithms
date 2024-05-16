#include <iostream>
#include <algorithm>
using namespace std;

constexpr int MAXN = 1e6+7;
int rep[MAXN], min_iq[MAXN], max_iq[MAXN], mass[MAXN];

int Find(int x) {
    if (rep[x] == x) return x;
    rep[x] = Find(rep[x]);
    return rep[x];
}

void Union(int x, int y) {
    x = Find(x);
    y = Find(y);
    if (x != y) {
        rep[x] = rep[y];
        min_iq[y] = min(min_iq[y], min_iq[x]);
        max_iq[y] = max(max_iq[y], max_iq[x]);
        mass[y] += mass[x];
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, a, b;
    string op;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a >> b;
        min_iq[i] = max_iq[i] = a;
        mass[i] = b;
    }
    for (int i = 1; i <= n; ++i) rep[i] = i;
    while (cin >> op) {
        if (op == "JOIN") {
            cin >> a >> b;
            Union(a, b);
        }
        else {
            cin >> a;
            if (op == "IQ_MIN")
                cout << min_iq[Find(a)] << '\n';
            else if (op == "IQ_MAX")
                cout << max_iq[Find(a)] << '\n';
            else
                cout << mass[Find(a)] << '\n';
        }
    }
}