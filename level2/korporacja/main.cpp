#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 5e5+7;
vector <int> G[MAXN];
int pre[MAXN], post[MAXN];
int c=1, n, p, a, b;

void DFS(int v, int p) {
    pre[v] = c;
    ++c;
    for (auto u : G[v])
        if (u != p) DFS(u, v);
    post[v] = c;
    ++c;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i =1; i < n; i++) {
        cin >> p;
        G[p].push_back(i);
        G[i].push_back(p);
    }
    DFS(0, 0);

    while (a != -1) {
        cin >> a;
        if (a != -1) {
            cin >> b;
            if (pre[a]<pre[b] && post[a]>post[b]) cout << "TAK\n";
            else cout << "NIE\n";
        }
    }
}