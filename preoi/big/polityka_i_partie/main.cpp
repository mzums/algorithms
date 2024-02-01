#include <iostream>
#include <vector>
using namespace std;

struct Q {
	int c, a, b;
};
constexpr int MAX = 3e5+7, LOG = 19;
vector<pair<int, int>> G[MAX + 1];
pair<int, int> order[MAX + 1];
int rep[MAX + 1], dist[MAX + 1];
int anc[MAX + 1][LOG + 1];
Q query[MAX + 1];
int t = 1;

void dfs(int v, int p) {
	order[v].first = (t++);
	
	anc[v][0] = p;
	for (int i = 1; i <= LOG; i++)
		anc[v][i] = anc[anc[v][i - 1]][i - 1];

	for (auto u : G[v])
		if (u.first != p) {
			dist[u.first] = dist[v] + u.second;
			dfs(u.first, v);
		}
	order[v].second = t - 1;
}

bool subtree_check(int a, int b) {
	return (order[a].first <= order[b].first) && (order[b].first <= order[a].second);
}

int lca(int a, int b) {
	if (subtree_check(a, b)) return a;
	if (subtree_check(b, a)) return b;
	
	for (int i = LOG; i >= 0; i--)
		if (!subtree_check(anc[b][i], a))
			b = anc[b][i];

	return anc[b][0];
}

int Find(int a) {
	if (a == rep[a]) return a;
	rep[a] = Find(rep[a]);
	return rep[a];
}
void Union(int a, int b) {
	a = Find(a);
	b = Find(b);
	if (a == b) return;
	rep[a] = b;
}

int calc_dist(int a, int b) {
	return dist[a] + dist[b] - 2 * dist[lca(a, b)];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) rep[i] = i;
	for (int i = 1; i <= m; i++) {
		int c, a, b;
		cin >> c >> a >> b;
		query[i] = {c, a, b};
		
		if (c <= 2 && Find(a) != Find(b)) {
			int weight = (c == 1 ? 0 : 1);
			G[a].push_back({b, weight});
			G[b].push_back({a, weight});
			Union(a, b);
		}
	}
	for (int i = 1; i <= n; i++)
		if (order[i].first == 0) dfs(i, i);

	for (int i = 1; i <= n; i++) rep[i] = i;
	
	for (int i = 1; i <= m; i++) {
        auto [c, a, b] = query[i];
		if (c <= 2) {
			if (Find(a) == Find(b)) {
				int d = calc_dist(a, b);
				if (c == 1) {
					if (d % 2 == 1) cout << -1 << "\n";
				} else {
					if (d % 2 == 0) cout << -1 << "\n";
				}
			} else Union(a, b);
		} else {
			if (Find(a) != Find(b)) {
				cout << 0 << "\n";
				continue;
			}
			int d = calc_dist(a, b);
			if (c == 3) cout << (d % 2 == 0 ? 1 : 0) << "\n";
			else cout << (d % 2 != 0 ? 1 : 0) << "\n";
		}
	}
}
