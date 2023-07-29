#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 1e6+7;
vector <int> G[MAXN];
int degree[MAXN];
int n, m, u, v;

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        G[u].push_back(v);
        degree[v]++;
    }
    //cout << "test\n";
    vector <int> ready;
    for (int i = 1; i <= n; i++)
        if (degree[i] == 0)
            ready.push_back(i);

    if(ready.size() != 1) {
        cout << "NIE";
        return 0;
    }
    
    vector <int> order;
    while (!ready.empty()) {
        int v = ready.back();
        ready.pop_back();
        order.push_back(v);
        for (auto u : G[v]) {
            degree[u]--;
            if (degree[u] == 0)
                ready.push_back(u);
        }
        if(ready.size() > 1) {
            cout << "NIE";
            return 0;
        }
    }
    if (order.size() != n)
        cout << "NIE";
    else {
        cout << "TAK\n";
        for (int i = 0; i < order.size(); i++)
            cout << order[i] << " ";
    }
}