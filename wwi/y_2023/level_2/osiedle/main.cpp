#include <iostream>
#include <vector>
using namespace std;

constexpr int MAXN = 26e4+7;
vector<int> G[MAXN];
bool edge[MAXN];
int rep[MAXN];

int Find(int a) {
	if (a == rep[a]) return a;
	rep[a] = Find(rep[a]);
	return rep[a];
}

void Union(int a, int b) {
	a = Find(a);
	b = Find(b);
	if (a == b) return;
	edge[b] = edge[a] || edge[b];
	rep[a] = b;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m, k, x1, y1, x2, y2;
	cin >> n >> m >> k;
	for (int i = 1; i <= (n+1)*(m+1); ++i) {
		rep[i] = i;
	}
	for (int i = 1; i <= m+1; ++i) edge[i] = 1;
	for (int i = n*(m+1)+1; i <= (n+1)*(m+1); ++i) edge[i] = 1;
	for (int i = 1; i <= n*(m+1)+1; i+=m+1) edge[i] = 1;
	for (int i = m+1; i <= (n+1)*(m+1); i+=m+1) edge[i] = 1;

	for (int i = 0; i < k; ++i) {
		cin >> x1 >> y1 >> x2 >> y2;
		int a, b;
		if (x1 < x2 && y1 == y2) {
			a = (x1-1) * (m+1) + y1 + m + 1;
			b = a + 1;
		}
		else if (x1 > x2 && y1 == y2) {
			a = (x1-1) * (m+1) + y1;
			b = a + 1;
		}
		else if (x1 == x2 && y1 < y2) {
			a = (x1-1) * (m+1) + y1 + 1;
			b = a + m + 1;
		}
		else {
			a = (x1-1) * (m+1) + y1;
			b = a + m + 1;
		}

		if (Find(a) == Find(b)) {
			cout << "NIE\n";
		}
		else if (edge[Find(a)] && edge[Find(b)]) {
			cout << "NIE\n";
		}
		else {
			cout << "TAK\n";
			Union(a, b);
		}
	}
}
