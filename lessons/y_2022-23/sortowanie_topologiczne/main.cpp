#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAXN = 1e6+7;
vector <int> G[MAXN];
int degree[MAXN];

int main() {
    int n, m, u, v;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        G[u].push_back(v);
        degree[v]++;
    }
    queue <int> ready;
    vector <int> order;
    for (int i = 1; i <= n; i++)
        if (degree[i] == 0)
            ready.push(i);

    if (ready.size() < 1) {
        cout << "NIE";
        return 0;
    }
    while (!ready.empty()) {
        int v = ready.front();
        ready.pop();
        order.push_back(v);
        for (auto u : G[v]) {
            --degree[u];
            if (degree[u] == 0) ready.push(u);
        }
    }
    if (order.size() != n) cout << "NIE";
    else {
        cout << "TAK\n";
        for (auto el : order) cout << el << " ";
    }
}
