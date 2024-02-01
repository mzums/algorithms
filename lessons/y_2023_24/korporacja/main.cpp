#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 5e5+7;
int pre[MAXN], post[MAXN];
vector<int> G[MAXN];
int c = 1;

void dfs(int v, int p) {
    pre[v] = c++;
    for (auto u : G[v])
        if (u != p) dfs(u, v);
    post[v] = c++;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, p, a, b;
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> p;
        G[p].push_back(i);
        G[i].push_back(p);
    }
    dfs(0, 0);
    while (a != -1) {
        cin >> a;
        if (a != -1) {
            cin >> b;
            if (pre[a]<pre[b] && post[b]<post[a]) cout << "TAK\n";
            else cout << "NIE\n";
        }
    }
}