#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 1e5+7;
const int BASE = 64*1024;
int heights[MAXN];
int tree[2*BASE];

void init(int n) {
    for (int i = 1; i <= n; i++) tree[BASE+i] = heights[i];
    for (int i = BASE-1; i >= 1; i--)
        tree[i] = max(tree[2*i], tree[2*i+1]);
}

int query(int a, int b, int v, int l, int r) {
    if (b < l || r < a) return 0;
    if (a <= l && r <= b) return tree[v];

    int mid = (l+r) / 2;
    int res_l = query(a, b, 2*v, l, mid);
    int res_r = query(a, b, 2*v+1, mid+1, r);
    return max(res_l, res_r);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m, a, b, maxx, res=0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> heights[i];
    init(n);

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        maxx = query(a+1, b-1, 1, 0, BASE-1);
        if (maxx <= heights[a]) res++;
    }
    cout << res;
}