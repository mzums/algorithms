#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

constexpr int MAXN = 130;
string arr[MAXN];
vector<int> G[MAXN];
int deg[MAXN];

void toposort(int n) {
    queue <int> ready;
    vector <int> order;
    for (int i = 97; i <= 122; i++)
        if (deg[i] == 0)
            ready.push(i);

    if (ready.size() < 1) {
        cout << "Impossible";
        return;
    }
    while (!ready.empty()) {
        int v = ready.front();
        ready.pop();
        order.push_back(v);
        for (auto u : G[v]) {
            --deg[u];
            if (deg[u] == 0) ready.push(u);
        }
    }
    if (order.size() != 26) cout << "Impossible";
    else for (auto el : order) cout << (char)el;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> arr[i];
    for (int i = 0; i < n; ++i)
        for (int j = i-1; j >= 0; --j) {
            for (int k = 0; k < min(arr[i].size(), arr[j].size()); ++k) {
                if (arr[i][k] != arr[j][k]) {
                    G[arr[j][k]].push_back(arr[i][k]);
                    ++deg[arr[i][k]];
                    break;
                }
                if (k == min(arr[i].size(), arr[j].size())-1) {
                    if (arr[i].size() < arr[j].size()) {
                        cout << "Impossible";
                        return 0;
                    }
                }
            }
        }
    toposort(n);
}