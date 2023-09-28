#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

constexpr int MAXN = 2e5+7;

vector<pair<int, int>> v;
vector<int> dp (MAXN);

int bs(int szukana, int r) {
    int l = 0, mid;
    while (l < r) {
        mid = (l + r) / 2;
        if (v[mid].first > szukana)
            r = mid;
        else   
            l = mid + 1;
    }
    return l;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, with, without;
    cin >> n;
    v.resize(n+1);

    for (int i = 1; i <= n; ++i) {
        int a, b;
        cin >> a >> b;
        v[i] = {b, a};
    }
    sort(v.begin(), v.end());

    for (int i = 1; i <= n; ++i) {
        without = dp[i-1];
        int last_index = bs(v[i].second, i);
        with = dp[last_index-1] + 1;
        dp[i] = max(with, without);
    }
    cout << dp[n];
}