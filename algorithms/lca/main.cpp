#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 10;
const int maxp2 = 20;

struct edge {
	int target;
	int dist;
};

vector<edge> con[maxn];
int dpt[maxn];
// Przodkowie.
// W tej tablicy par[x][y] oznacza 2^y przodka wierzchołka x.
int par[maxn][maxp2];
// Odległość do przodków. (int64_t to inaczej long long)
int64_t dist[maxn][maxp2];
// Odwiedzeni.
bool vis[maxn];

void DFS(int x) {
	vis[x] = true;
	// e jak edge.
	for (auto e : con[x]) {
		int syn = e.target;
		if (!vis[syn]) {
			par[syn][0] = x;
			dist[syn][0] = e.dist;
			dpt[syn] = dpt[x] + 1;
			// 2^i to jest aktualizowany właśnie przodek.
			// (1 << n) to 2^n, i liczy się od razu w jednej operacji (użyteczne).
			for (int i = 1; (1 << i) <= dpt[syn]; i++) {
				// Poprzednio aktualizowany przodek (2^(i-1)).
				int pop_przodek = par[syn][i - 1];
				par[syn][i] = par[pop_przodek][i - 1];
				dist[syn][i] = dist[syn][i - 1] + dist[pop_przodek][i - 1];
			}
			DFS(syn);
		}
	}
}

int64_t LCA(int x, int y) {
	int64_t wyn = 0;
	// Po tym ifie mamy pewność, że x jest głębiej (lub na tej samej głębokości) co y.
	if (dpt[y] > dpt[x]) {
		swap(x, y);
	}
	for (int i = maxp2; i >= 0; i--) {
		if (dpt[x] - dpt[y] >= (1 << i)) {
			wyn += dist[x][i];
			x = par[x][i];
		}
	}
	if (x == y) {
		return wyn;
	}
	for (int i = maxp2; i >= 0; i--) {
		// Pierwsza część warunku jest niepotrzebna, ale tak chyba
		// jest bardziej zrozumiale. (jeśli przodek nie istnieje to
		// jest zapisany jako 0 w tablicy i oba wierzchołki mają takich
		// samych przodków).
		if (dpt[x] >= (1 << i) && par[x][i] != par[y][i]) {
			wyn += dist[x][i];
			wyn += dist[y][i];
			x = par[x][i];
			y = par[y][i];
		}
	}
	wyn += dist[x][0];
	wyn += dist[y][0];
	return wyn;
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int a, b, c;
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b >> c;
		con[a].push_back({b, c});
		con[b].push_back({a, c});
	}
	DFS(1);
	int q;
	cin >> q;
	while (q--) {
		cin >> a >> b;
		cout << LCA(a, b) << "\n";
	}
}

/*
18
1 15 1
15 2 4
2 17 7
15 10 2
10 9 3
15 11 3
15 13 4
1 3 6
3 12 5
3 8 6
8 16 7
3 7 7
1 18 9
18 14 1
18 6 2
6 4 1
6 5 1
7
9 13
5 16
12 7
18 10
9 10
1 6
12 3
*/