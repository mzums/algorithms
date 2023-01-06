#include <cmath>
#include <iostream>
#include <unordered_map>

using namespace std;

int a, c, p, i, an, n, akt;

int logarytm() {
    a %= p, c %= p;
    n = sqrt(p) + 1;

    an = 1;
    for (i = 0; i < n; ++i) an = (an * 1ll * a) % p;

    unordered_map<int, int> wartosci;
    for (i = 0, akt = c; i <= n; ++i) {
        wartosci[akt] = i;
        akt = (akt * 1ll * a) % p;
    }

    for (i = 1, akt = 1; i <= n; ++i) {
        akt = (akt * 1ll * an) % p;
        if (wartosci.count(akt)) {
            int ans = n * i - wartosci[akt];
            cout << i << " ";
            return ans;
        }
    }
    return -1;
}

int main() {
    while (cin >> a >> c >> p) cout << logarytm() << "\n";
}