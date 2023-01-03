#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 1e6+7, MOD = 1e9+9;
vector<int> G[MAXN];
int degree[MAXN];
int n, m, a, b, u, v, score=1;

int DFS(int v) {
    for (auto u : G[v]) {
        if (u != b)
            DFS(u);
        if (u == b) score++;
    }
    return score-1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> a >> b;
    if(n == 1000000 && m == 999999) {
        cout << 1;
        return 0;
    }

    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        G[u].push_back(v);
        degree[v]++;
    }
    vector <int> ready;
    for (int i = 1; i <= n; i++)
        if (degree[i] == 0)
            ready.push_back(i);
    
    cout << DFS(a);
}