#include <iostream>
using namespace std;

constexpr int BASE = 1<<17, INF = 1<<30;
int tree[BASE << 1], tree2[BASE << 1], arr[BASE];

void push(int v) {
	tree[2*v] += tree2[v];
	tree[2*v+1] += tree2[v];
	tree2[2*v] += tree2[v];
	tree2[2*v+1] += tree2[v];
	tree2[v] = 0;
}

void upd(int a, int b, int l, int r, int v, int x) {
    if (r < a || b < l) return;
    if (a <= l && r <= b) {
        tree[v] += x;
        tree2[v] += x;
    }
    else {
        push(v);
        upd(a, b, l, (l+r)/2, 2*v, x);
        upd(a, b, (l+r)/2+1, r, 2*v+1, x);
        tree[v] = min(tree[2*v], tree[2*v+1]);
    }
}

int query(int a, int b, int l, int r, int v) {
    if (r < a || b < l) return INF;
    if (a <= l && r <= b) return tree[v];
    push(v);
    return min(query(a, b, l, (l+r)/2, 2*v), query(a, b, (l+r)/2+1, r, 2*v+1));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, a, score=0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        score += arr[i];
        tree[i+BASE] = score;
    }
    for (int i = BASE - 1; i >= 1; i--)
		tree[i] = min(tree[2 * i], tree[2 * i + 1]);

	while (1) {
        cin >> a;
        if (a == -1) break;
	    if (a == 0) {
	        if (query(BASE, 2*BASE-1, BASE, 2*BASE-1, 1) == 0 && score == 0) cout << "TAK\n";
	        else cout << "NIE\n";
	    }
	    else {
	        a--;
	        upd(BASE+a, 2*BASE-1, BASE, 2*BASE-1, 1, -2*arr[a]);
            score += -2 * arr[a];
	        arr[a] *= -1;
	    }
	}
}