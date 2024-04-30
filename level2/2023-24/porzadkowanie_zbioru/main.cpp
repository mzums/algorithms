#include <iostream>
#include <vector>
#include <queue>
using namespace std;

constexpr int MAXN = 1e5+7;
vector<int> G[MAXN];
int degree[MAXN]; 
queue<int> ready, order;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, a, b;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        G[a].push_back(b);
        ++degree[b];   
    }
    for (int i = 1; i <= n; ++i)
        if (degree[i] == 0)
            ready.push(i);
    
    while (!ready.empty()) {
        if (ready.size() != 1) {
            cout << "NIE\n";
            return 0;
        }
        int v = ready.front();
        ready.pop();
        order.push(v);
        for (auto u : G[v]) {
            --degree[u];
            if (degree[u] == 0)
                ready.push(u);
        }
    }
    if (order.size() == n) {
        cout << "TAK\n";
        while (!order.empty()) {
            cout << order.front() << ' ';
            order.pop();
        }
    }
    else cout << "NIE\n";
}