#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
using namespace std;

struct Edge {
    double dist;
    int a, b;
};
constexpr int MAXN = 2007;
pair<int, int> arr[MAXN];
int rep[MAXN];
vector<Edge> v;

bool Sort(Edge x, Edge y) {
    return x.dist > y.dist;
}

int Find(int v) {
    if (v == rep[v]) return v;
    rep[v] = Find(rep[v]);
    return rep[v];
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

    int n;
    double a, b, res = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a >> b;
        rep[i] = i;
        arr[i] = {a, b};
    }
    rep[0] = 0;
    arr[0] = {0, 0};
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= n; ++j) {
            if (i == j) continue;
            a = abs(arr[i].first - arr[j].first);
            b = abs(arr[i].second - arr[j].second);
            v.push_back({sqrt(a*a + b*b), i, j});
        }
    sort(v.begin(), v.end(), Sort);
    while (!v.empty()) {
        auto [d, x, y] = v.back();
        v.pop_back();
        if (Find(x) != Find(y)) {
            res = max(res, d);
            Union(x, y);
        }
    }
    cout << fixed << setprecision(5) << res << "\n";
}