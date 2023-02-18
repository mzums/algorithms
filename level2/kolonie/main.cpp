#include <iostream>
using namespace std;

const int MAXN = 1e6+7;
int rep[MAXN], mass[MAXN], maxIQ[MAXN], minIQ[MAXN];
int n, a, b, x;
string op;

int Find(int a) {
    if (rep[a] == a) return a;
    rep[a] = Find (rep[a]);
    return (rep[a]);
}
void Union(int a, int b) {
    int x, y;
    x = Find(a);
    y = Find(b);
    if(x == y) return;
    rep[x] = rep[y];
    maxIQ[y] = max(maxIQ[y], maxIQ[x]);
    minIQ[y] = min(minIQ[y], minIQ[x]);
    mass[y] = mass[y] + mass[x];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> mass[i] >> minIQ[i];
        maxIQ[i] = minIQ[i];
        rep[i] = i;
    }
    
    while (cin >> op) {
        if (op == "JOIN") {
            cin >> a >> b;
            Union(a, b);
        }
        else if (op[0] == 'I') {
            cin >> a;
            x = Find(a);
            if (op == "IQ_MAX") cout << maxIQ[x] << "\n";
            else cout << minIQ[x] << "\n";
        }
        else {
            cin >> a;
            x = Find(a);
            cout << mass[x] << "\n";
        }
    }
}