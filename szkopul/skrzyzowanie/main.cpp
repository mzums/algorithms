#include <iostream>
#include <set>
using namespace std;

set<int> s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, p, t, a, b, res = 0;;
    cin >> n >> m >> p >> t;
    for (int i = 0; i < p; ++i) {
        cin >> a >> b;
        s.insert(a-b);
    }
    for (int i = 0; i < t; ++i) {
        cin >> a >> b;
        if (s.count(a-b)) ++res;
    }
    cout << t - res << "\n";
}