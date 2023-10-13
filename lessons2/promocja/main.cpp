#include <iostream>
#include <map>
#include "cprolib.h"
using namespace std;

constexpr int MAXN = 3e5+7;
map<int, int> people[MAXN];
int cities[MAXN];

int solve(int v, int t) {
    auto p = people[v].upper_bound(t);
    --p;
    return p->second;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, z, a, b;
    inicjuj(&n, &m, &z);

    for (int i = 1; i <= n; i++) {
        cities[i] = i;
        people[i][0] = i;
    }
    for (int i = 1; i <= m; i++) {
        pobierz_promocje(i, &a, &b);

        int personA = cities[a];
        int personB = cities[b];
        swap(cities[a], cities[b]);
        people[personA][i] = b;
        people[personB][i] = a;
    }
    for (int i = 0; i < z; i++) {
        pobierz_zapytanie(&a, &b);
        odpowiedz(solve(a, b));
    }
}
