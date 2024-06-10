#include <iostream>
#include <map>
using namespace std;

constexpr int MAXN = 3e5+7;
int rep[MAXN];
map<string, int> m;

int Find(int a) {
    if (a == rep[a]) return a;
    rep[a] = Find(rep[a]);
    return rep[a];
}

void Union(int a, int b) {
    a = Find(a);
    b = Find(b);
    if (a == b) return;
    rep[a] = b;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    string op, a, b;
    int p = 0;
    cin >> n;
    for (int i = 1; i <= 2*n+7; ++i) rep[i] = i;
    for (int i = 0; i < n; ++i) {
        cin >> op >> a >> b;
        if (m.find(a) == m.end()) m[a] = ++p;
        if (m.find(b) == m.end()) m[b] = ++p;
        if (op == "sending") {
            if (Find(m[a]) == Find(m[b]))
                cout << "Tak" << endl;
            else
                cout << "Nie" << endl;
        }
        else Union(m[a], m[b]);
    }
}