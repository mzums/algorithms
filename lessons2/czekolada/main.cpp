#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

struct Break {
    int cost, dir;
};

vector<Break> v;

bool Sort(Break a, Break b) {
    return a.cost > b.cost;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m, a, zero=1, one=1, res=0;
    cin >> m >> n;
    for (int i = 1; i < m; i++) {
        cin >> a;
        v.push_back({a, 0});
    }
    for (int i = 1; i < n; i++) {
        cin >> a;
        v.push_back({a, 1});
    }
    sort(v.begin(), v.end(), Sort);
    for (int i = 0; i < n+m-2; i++) {
        if (v[i].dir == 0) {
            one++;
            res += v[i].cost * zero;
        }
        if (v[i].dir == 1) {
            zero++;
            res += v[i].cost * one;
        }
    }
    cout << res;
}