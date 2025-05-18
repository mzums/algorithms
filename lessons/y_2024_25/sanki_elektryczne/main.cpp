#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;

constexpr int MAXN = 5e5+7;

vector<pair<int, int>> G[MAXN], R[MAXN];
vector<int> G3[MAXN];
bool visited[MAXN];
int order[MAXN], comp[MAXN], poziom[MAXN];
ll dp[MAXN];
queue<int> q;
int t = 0;

void dfs(int v) {
	visited[v] = true;
	for (auto u : G[v]) {
		if (visited[u.first]) continue;
		dfs(u.first);
	}
	order[++t] = v;
}

void scc(int v) {
	visited[v] = true;
	comp[v] = t;
	for (auto u : R[v]) {
		if (visited[u.first]) continue;
		scc(u.first);
	}
}

ll cost(ll w) {
	ll pocz = 1, kon = 15000;
	while (pocz < kon) {
		ll srodek = (pocz + kon) / 2;
		if (w > srodek * (srodek + 1) / 2) {
			pocz = srodek + 1;
		} else {
			kon = srodek;
		}
	}
	
	ll k = pocz;
	return w * k - k * k * (k - 1) / 2 + k * (k - 1) * (2 * k - 1) / 6;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	
	for (int i = 1; i <= m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		G[a].push_back({b, c});
		R[b].push_back({a, c});
	}
	
	for (int i = 1; i <= n; i++) {
		if (visited[i]) continue;
		dfs(i);
	}
	
	t = 0;
	for (int i = 1; i <= n; i++) visited[i] = false;
	for (int i = n; i >= 1; i--) {
		if (visited[order[i]]) continue;
		t++;
		scc(order[i]);
	}
	
	for (int i = 1; i <= n; i++) R[i].clear();
	for (int i = 1; i <= n; i++) {
		for (auto p : G[i]) {
			if (comp[i] == comp[p.first]) {
				dp[comp[i]] += cost(p.second);
			} else {
				R[comp[i]].push_back({comp[p.first], p.second});
				G3[comp[p.first]].push_back(comp[i]);
				poziom[comp[i]]++;
			}
		}
	}
	
	for (int i = 1; i <= t; i++) {
		if (poziom[i] == 0) {
			q.push(i);
		}
	}
	
	while (q.size()) {
		int v = q.front();
		q.pop();
		
		ll maks = 0;
		for (auto u : R[v]) {
			maks = max(maks, dp[u.first] + u.second);
		}
		dp[v] += maks;
		
		for (int p : G3[v]) {
			poziom[p]--;
			if (poziom[p] == 0) {
				q.push(p);
			}
		}
	}
	
	int start;
	cin >> start;
	cout << dp[comp[start]];
}
