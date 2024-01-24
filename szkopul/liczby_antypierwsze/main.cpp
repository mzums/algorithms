#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> candidates;
int p[11] = {1, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

void generate(int j, int max_pow, int cand, int no_factors, int n) {
    candidates.push_back({cand, no_factors});
    for (int i = 1; i <= max_pow; ++i) {
        if (p[j] > n/cand) return;
        cand = cand * p[j];
        generate(j+1, i, cand, no_factors*(i+1), n);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, maxx = 0, res = 0;
    cin >> n;
    generate(1, 31, 1, 1, n);
    sort(candidates.begin(), candidates.end());
    for (auto [a, b] : candidates) {
        if (b > maxx && a <= n) res = a;
        maxx = max(maxx, b);
    }
    cout << res;
}