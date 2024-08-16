#include <iostream>
#include "ballib.h"
#include <unordered_map>
using namespace std;

constexpr int MAXN = 1e6+7;

struct Hsh {
    size_t operator()(int x) const {
        return x ^ 213897662357342;
    }
};

int minimalna_liczba_rzutow() {
    int n = liczba_malpek();
    int res = 0;

    for (int i = 1; i <= n; ++i) {
        unordered_map<int, int, Hsh> cnt;
        for (int j = kolejny_balon(i); j != -1; j = kolejny_balon(i)) {
            if (cnt[j] > 0) --cnt[j];
            ++cnt[j-1];
        }
        for (auto j : cnt) {
            res += j.second;
        }
    }

    return res;
}