#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

const int MAXN = 1e5 + 7;
vector<int> G[MAXN];
int degree[MAXN];
int n, m, u, v;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        G[u].push_back(v);
        degree[v]++;
    }
    set<int> ready;
    for (int i = 1; i <= n; i++)
        if (degree[i] == 0)
            ready.insert(i);

    vector<int> order;
    while (!ready.empty()) {
        int v = *ready.begin();
        ready.erase(ready.begin());
        order.push_back(v);
        for (auto u : G[v]) {
            --degree[u];
            if (degree[u] == 0)
                ready.insert(u);
        }
    }
    if (order.size() != n)
        cout << "NIE";
    else {
        cout << "TAK\n";
        for (auto v : order)
            cout << v << " ";
    }
}