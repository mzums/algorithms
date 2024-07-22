#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

constexpr int MAXN = 1e6+7;
int kafelki[MAXN];

int main() {
    int n, m, a, b;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a);
        ++kafelki[a];
    }

    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &a, &b);
        int nwd = __gcd(a, b);
        int res = 0;
        for (int i = 1; i < sqrt(nwd); ++i) {
            if (nwd % i == 0 && kafelki[i]) {
                res += kafelki[i];
            }
            if (nwd % (nwd / i) == 0 && kafelki[nwd / i]) {
                res += kafelki[nwd / i];
            }
        }
        if (sqrt(nwd) == (int)sqrt(nwd) && nwd % (int)sqrt(nwd) == 0 && kafelki[(int)sqrt(nwd)]) {
            res += kafelki[(int)sqrt(nwd)];
        }
        printf("%d\n", res);
    }
}