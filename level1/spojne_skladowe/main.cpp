#include <iostream>
using namespace std;

const int MAXN = 1e6+7;
int rep[MAXN], degree[MAXN];
int n, m, q, a, b;

int Find(int a) {
    if (rep[a] != a) rep[a] = Find(rep[a]);
    return (rep[a]);
}
void Union(int a, int b) {
    int x = Find(a);
    int y = Find(b);
    if (degree[x] < degree[y]) rep[x] = y;
    else rep[y] = x;
    if (degree[x] == degree[y]) ++degree[x];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(); cout.tie(0);

    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) rep[i] = i;

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        Union(a, b);
    }
    for (int i = 0; i < q; i++) {
        cin >> a >> b;
        if (Find(a) == Find(b)) cout << "T\n";
        else cout << "N\n";
    }
}