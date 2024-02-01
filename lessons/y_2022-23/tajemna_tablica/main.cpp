#include <iostream>
#include "tajtabbibl.h"

using namespace std;
int minn = 1e9, maxx = -1e9;
int minind, maxind;

void odp(int el) {
    int b = -1e9 - 7, e = 1e9 + 7, m;
    while (b < e) {
        m = (b + e) / 2;
        if (wieksze(el, m)) b = m + 1;
        else e = m - 1;
    }
    --b;
    if (minn > b) {
        minn = min(minn, b);
        minind = el;

    }
    if (maxx < b) {
        maxx = max(maxx, b);
        maxind = el;
    }
}

int main() {
    int n = inicjuj();
    int b = -1e9 - 7, e = 1e9 + 7;
    for (int i = 0; i < n; ++i) odp(i);
    odpowiedz(minind, maxind);
}