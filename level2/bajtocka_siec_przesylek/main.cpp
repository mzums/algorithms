#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
const int MAXN = 1e6+7;
vector <pair <int, int>> G[MAXN];
int siz[MAXN];
ll dp[MAXN], f[MAXN];
int n, a, b, c;

void dfs1(int v, int p) {
    for (auto u : G[v])
        if (u.first != p) {
            dfs1(u.first, v);
            siz[v] += siz[u.first];
            dp[v] += siz[u.first]*u.second + dp[u.first];
        }
}

void dfs2(int v, int p) {
    for (auto x : G[v])
        if (x.first != p) {
            int u = x.first;
            int w = x.second;
            f[u]= f[v]+w*(n-2*siz[u]);
            dfs2(x.first, v);
        }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> a >> b >> c;
        G[a].push_back({b, c});
        G[b].push_back({a, c});
    }
    for (int i = 1; i <= n; i++)
        siz[i] = 1;

    dfs1(1, 1);
    f[1] = dp[1];
    dfs2(1, 1);
    for (int i = 1; i <= n; i++)
        cout << f[i] << "\n";
}