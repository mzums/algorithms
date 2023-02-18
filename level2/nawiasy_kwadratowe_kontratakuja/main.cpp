#include <iostream>
#include <climits>
using namespace std;

const int base = 1 << 17;
const int INF = INT_MAX;
int tree[2 * base];
int tree2[2 * base];
int arr[base];

void push(int v, int n) {
	tree[2*v] += tree2[v];
	tree2[2*v] += tree2[v];
	tree[2*v+1] += tree2[v];
	tree2[2*v+1] += tree2[v];
	tree2[v] = 0;
}

void add(int a, int b, int l, int r, int v, int x) {
	if (r<a || b<l) return;
	if (a <= l && r <= b) {
		tree[v] += x;
		tree2[v] += x;
	}
	else {
		push(v, r-l+1);
		add(a, b, l, (l+r)/2, 2*v, x);
		add(a, b, (l+r)/2+1, r, 2*v+1, x);
		tree[v] = min(tree[2*v], tree[2*v+1]);
	}
}

int query(int a, int b, int l, int r, int v) {
	if (r<a || b<l) return INF;
	if (a<=l && r<=b) return tree[v];
	push(v, r-l+1);
	return min(query(a, b, l, (l+r)/2, 2*v), query(a, b, (l+r)/2+1, r, 2*v+1));
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, a, suma=0;
	cin >> n;

	for (int i = 0; i < n; i++) {
	    cin >> arr[i];
	    suma += arr[i];
	    tree[base+i] = suma;
	}
	for (int i = base - 1; i >= 1; i--)
		tree[i] = min(tree[2 * i], tree[2 * i + 1]);
	
	cin >> a;
	while (a != -1) {
	    if (a == 0) {
	        if (query(base, 2*base-1, base, 2*base-1, 1)==0 && query(2*base-1, 2*base-1, base, 2*base-1, 1)== 0)
	            cout << "TAK\n";
	        else
	            cout << "NIE\n";
	        
	    }
	    else {
	        a--;
	        if (arr[a] == -1)
	           add(base+a, 2*base-1, base, 2*base-1, 1, 2);
	        else
	           add(base+a, 2*base-1, base, 2*base-1, 1, -2);
	        arr[a] *= -1;
	    }
	    cin >> a;
	}

	return 0;
}