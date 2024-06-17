#include <iostream>
#include <vector>
using namespace std;

constexpr int MAXN = 5e5+7;
int rep[MAXN];
vector<int> to_be_closed, to_be_opened;
bool used[MAXN];

int Find(int a) {
    if (rep[a] == a) return a;
    return rep[a] = Find(rep[a]);
}

void Union(int a, int b) {
    a = Find(a);
    b = Find(b);
    if (a != b) rep[a] = b;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, a, b;
    cin >> n;
    for (int i = 1; i <= n; ++i) rep[i] = i;
    for (int i = 1; i < n; ++i) {
        cin >> a >> b;
        if (Find(a) != Find(b)) Union(a, b);
        else to_be_closed.push_back(i);
    }
    cout << to_be_closed.size() << "\n";
    used[Find(1)] = 1;
    for (int i = 2; i <= n; ++i) {
        if (!used[Find(i)]) {
            cout << to_be_closed.back() << " " << Find(i) << " " << Find(1) << "\n";
            used[Find(i)] = 1;
            to_be_closed.pop_back();
        }
    }
}