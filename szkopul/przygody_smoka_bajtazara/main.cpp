#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

constexpr int MAXN = 1e6+7;
map<int, int> m;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, a;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        m[a]++;
    }
    int i = 0, last = 1e9+7;
    while (m.find(i) != m.end() && min(m[i], last-1) > 0) {
        last = min(m[i], last-1);
        i++;
    }
    cout << i+1 << "\n";
}