#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

constexpr int MAXN = 5e5+7;
struct S {
    int a, b, c;
};
pair<int, pair<int, int>> arr[MAXN];
int rep[MAXN], a[MAXN], b[MAXN];

int Find(int a) {
    if (rep[a] == a) return a;
    rep[a] = Find(rep[a]);
    return rep[a];
}

void Union(int x, int y) {
    x = Find(x);
    y = Find(y);
    if (x != y) {
        a[y] += a[x];
        b[y] += b[x];
        rep[x] = y;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k, x, y, z;
    ll res = 0;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> x >> y >> z;
        arr[i] = {z, {x, y}};
    }
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> x;
        ++a[x];
    }
    for (int i = 0; i < k; i++) {
        cin >> x;
        ++b[x];
    }
    for (int i = 1; i <= n; i++) rep[i] = i;
    sort(arr, arr+m);
    for (int i = 0; i < m; i++) {
        auto [c, p] = arr[i];
	    auto [x, y] = p;
	    x = Find(x);
	    y = Find(y);
	    if (Find(p.first) != Find(p.second)) {
	        res += (ll)(min(a[x]+a[y], b[x]+b[y]) - min(a[x], b[x]) - min(a[y], b[y])) * c;
            Union(p.first, p.second);
        }
    }
    cout << res << '\n';
}
